void drawMorseAlphabet() {
  tft.fillScreen(MAIN_BACKGROUND_COLOR);
  tft.setTextColor(MAIN_FOREGROUND_COLOR);
  tft.setTextSize(1);

  const char* morseAlphabet[] = {
    "A .-", "B -...", "C -.-.", "D -..", "E .", "F ..-.",
    "G --.", "H ....", "I ..", "J .---", "K -.-", "L .-..",
    "M --", "N -.", "O ---", "P .--.", "Q --.-", "R .-.",
    "S ...", "T -", "U ..-", "V ...-", "W .--", "X -..-",
    "Y -.--", "Z --..", "0 -----", "1 .----", "2 ..---", 
    "3 ...--", "4 ....-", "5 .....", "6 -....", "7 --...", 
    "8 ---..", "9 ----."
  };

  int x = 2, y = 4;
  for (int i = 0; i < 36; i++) {
    tft.setCursor(x, y);
    tft.print(morseAlphabet[i]);
    y += 8;
    if (y >= 76) { 
      y = 4;
      x += 38;
    }
  }
}

void drawMorseClick(int color)
{
  tft.setTextSize(2);
  tft.setCursor(134, 72);
  tft.setTextColor(color); 
  tft.print("--");
}
