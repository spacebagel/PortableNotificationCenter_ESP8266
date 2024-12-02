struct CurrentWeatherData {
  String temperature;
  String date;
};

CurrentWeatherData getWeather() {
  WiFiClient client;
  CurrentWeatherData weatherData;
  if (client.connect(server, 80)) {
    String url = "/v1/forecast?latitude=" + String(latitude)
               + "&longitude=" + String(longitude)  
               + "&timezone="+ timeZone
               + "&current_weather=true";

    client.println("GET " + url + " HTTP/1.1");
    client.println("Host: " + String(server));
    client.println("Connection: close");
    client.println();
    
    while (client.connected() || client.available()) {
      if (client.available()) {
        String line = client.readStringUntil('\n');
        if (line.startsWith("{")) {
          StaticJsonDocument<512> doc;
          DeserializationError error = deserializeJson(doc, line);
          if (error) {
            Serial.print("JSON deserialization failed: ");
            Serial.println(error.c_str());
            return weatherData;
          }

          float temperature = doc["current_weather"]["temperature"];
          String date = doc["current_weather"]["time"];
          auto temperatureValue = String(temperature, 0);
          weatherData.temperature = (temperatureValue == "-0" ? "0" : temperatureValue) + " C";
          weatherData.date = date.substring(8, 10) + "." + date.substring(5, 7);
          return weatherData;
        }
      }
    }
    
    client.stop();
  } else {
    return weatherData;
  }

  return weatherData;
}
