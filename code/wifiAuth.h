void WiFiAuth() {
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    for (int i = 0; i < 4; i++) {
      tft.setCursor(30, 50);               
      tft.setTextColor(ST77XX_BLACK);
      tft.print("...");
      tft.setCursor(30, 50);
      tft.setTextColor(ST77XX_WHITE);
      
      if (i == 1) tft.print(".  ");
      else if (i == 2) tft.print(".. ");
      else if (i == 3) tft.print("...");
    }
  }
}
