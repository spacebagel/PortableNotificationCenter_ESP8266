void redrawText(int cursorPositionX, int cursorPositionY, String oldText, String newText, int textSize = 1)
{
  tft.setTextSize(textSize);
  tft.setCursor(cursorPositionX, cursorPositionY);
  tft.setTextColor(MAIN_BACKGROUND_COLOR); 
  tft.print(oldText);
  tft.setTextColor(MAIN_FOREGROUND_COLOR); 
  tft.setCursor(cursorPositionX, cursorPositionY);
  tft.print(newText);
}
