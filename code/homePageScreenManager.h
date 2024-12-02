void drawTime(int i, char lastTimeChar, char nowTimeChar) {
  redrawText(26 + i * 12, 30, (String)lastTimeChar, (String)nowTimeChar, 2);
}

void drawDay(String lastDay, String dayNow) {
  redrawText(26, 46, lastDay, dayNow);
}

void drawDate(String lastDate, String nowDate) {
  redrawText(108, 27, lastDate, nowDate);
}

void drawWeather(String lastWeather, String nowWeather) {
  redrawText(109, 47, lastWeather, nowWeather);
}
