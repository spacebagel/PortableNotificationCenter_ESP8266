int cursorX = 18;
int endLineXPoint = 142, activeAreaWidth = 70, activeAreaHeight = 15;
int gamePoints = 0, gameLevel = 1;
int activeAreaXLeft = 34, activeAreaYLeft = 34;

void drawMainGameLine() {
  auto x1 = 18, y1 = 50;
  tft.drawLine(x1, y1 - 5, x1, y1 + 5, GAME_MAIN_LINE_COLOR); 
  tft.drawLine(x1, y1, endLineXPoint, y1, GAME_MAIN_LINE_COLOR); 
  tft.drawLine(endLineXPoint, y1 - 5, endLineXPoint, y1 + 5, GAME_MAIN_LINE_COLOR); 
}

void drawActiveArea() {
  tft.fillRect(activeAreaXLeft, activeAreaYLeft, activeAreaWidth, activeAreaHeight, GAME_ACTIVE_AREA_COLOR);
}

void drawGameCursor() {
  tft.drawLine(cursorX, 70, cursorX, 30, MAIN_FOREGROUND_COLOR);
  tft.drawLine(cursorX - gameLevel, 70, cursorX - gameLevel, 30, MAIN_BACKGROUND_COLOR);
  if (cursorX >= endLineXPoint) 
  {
    tft.drawLine(cursorX, 70, cursorX, 30, MAIN_BACKGROUND_COLOR);
    cursorX = 18;
  }
  drawActiveArea();
  drawMainGameLine();
}

void drawEmptyScoreLvlInfo()
{
  tft.setTextSize(1);
  tft.setTextColor(MAIN_FOREGROUND_COLOR); 
  tft.setCursor(10, 5);
  tft.print("Score:");
  tft.setCursor(10, 15);
  tft.print("Level:");
}

void drawScoreLvlInfo() 
{
  String oldScoreResult = String(gamePoints);
  String oldLevelResult = String(gameLevel);
  if (gameLevel > 1) 
  {
    oldScoreResult = String(gamePoints - 100 * gameLevel);
    oldLevelResult = String(gameLevel - 1);
  }
  redrawText(50, 5, oldScoreResult, String(gamePoints));
  redrawText(50, 15, oldLevelResult, String(gameLevel));
}

void resetWindow()
{
  tft.fillScreen(MAIN_BACKGROUND_COLOR);
  drawActiveArea();
  drawScoreLvlInfo();
  drawGameCursor();
  drawEmptyScoreLvlInfo();
}

void resetGameScore()
{
  cursorX = 18;
  gamePoints = 0;
  gameLevel = 1;
  activeAreaWidth = 70;
  activeAreaXLeft = int(random(18, endLineXPoint - activeAreaWidth));
}
