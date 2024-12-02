const long utcOffsetInSeconds = 10800; 

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP, utcOffsetInSeconds);

String dayOfWeek[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
