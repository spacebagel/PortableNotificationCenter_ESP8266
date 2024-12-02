#include <ESP8266WiFi.h>
#include <Adafruit_GFX.h>  
#include <Adafruit_ST7735.h> 
#include <WiFiUdp.h>
#include <NTPClient.h>
#include <ArduinoJson.h>
#include "config.h"
#include "currentDateTime.h"
#include "beaconSpam.h"
#include "playSound.h"
#include "wifiAuth.h"
#include "weather.h"
#include "generalPageScreenManager.h"
#include "morsePageScreenManager.h"
#include "homePageScreenManager.h"
#include "gamePageScreenManager.h"

int selectedMenuItem = 0;  
const int maxVisibleItems = 3; 

unsigned long previousMillis = 0;
const long intervalMain = 500;

const int numMenuItems = 4;
const char* menuItems[] = {"Home", "WiFiSpam", "Morse", "Game"};

bool isPageOpen = false;
bool isFirstPageLoop = true;
bool button1State;

String lastTime;
String lastDay;
String lastDate;
String lastWeather;

void showMenu() {
  tft.fillScreen(MAIN_BACKGROUND_COLOR);
  tft.setCursor(5, 5);
  int tempPosition = 0;
  for (int i = 0; i < maxVisibleItems; i++) {
    tempPosition = selectedMenuItem + i;
    tft.setTextColor(MAIN_FOREGROUND_COLOR);
    if (tempPosition == selectedMenuItem) tft.setTextColor(ST77XX_ORANGE);
    if (tempPosition < numMenuItems) tft.println(menuItems[tempPosition]);
  }
  Serial.println(tempPosition);
}

void showHomePage()
{
  if(isFirstPageLoop == true) 
  {
    lastTime = "lo_ad";
    lastDay = "Loading";
    lastDate = "lo_ad";
    lastWeather = "lo_ad";
    isFirstPageLoop = false;
  }
   
  timeClient.update();
  String nowTime = timeClient.getFormattedTime();
  for (int i = 0; i < 5; i++) 
  {
    if(lastTime[i] != nowTime[i])
    {
      drawTime(i, lastTime[i], nowTime[i]);
      lastTime[i] = timeClient.getFormattedTime()[i];
    }
  }

  String dayNow = dayOfWeek[timeClient.getDay()];
  if (dayNow != lastDay)
  {
    drawDay(lastDay, dayNow);
    lastDay = dayNow;
  }
  
  if (nowTime[-1] == '0' || lastDate == "lo_ad")
  {
    auto weather = getWeather();
    String nowDate = weather.date;
    if (lastDate != nowDate)
    {
      drawDate(lastDate, nowDate);
      lastDate = nowDate;
    }

    tft.setCursor(110, 37);
    tft.print("///");

    String nowWeather = weather.temperature;
    if (nowWeather != lastWeather)
    {
      drawWeather(lastWeather, nowWeather);
      lastWeather = nowWeather;
    }
  }
}

void showWiFiSpamPage()
{
  spamProcess();

  if(isFirstPageLoop == true)
  {
    tft.setCursor(20.5, 33);
    tft.println("Spaming...");
    spamSettingSchouldBeInSetup();
    isFirstPageLoop = false;
  }
}

void showMorsePage() {
  if(isFirstPageLoop == true)
  {
    drawMorseAlphabet();
    isFirstPageLoop = false;
  }
  
  if (button1State) 
  {
    drawMorseClick(MORSE_PAGE_CLICK_INFO_COLOR);
    playMorseDotSound();
  }
  else 
  {
    drawMorseClick(0xffff);
    offSound();
  }
}

void showGamePage() {
  if(isFirstPageLoop == true) 
  {
    isFirstPageLoop = false;
    drawMainGameLine();
    drawScoreLvlInfo();
    resetGameScore();
    drawEmptyScoreLvlInfo();
  }

  drawActiveArea();
  cursorX += gameLevel;
  drawGameCursor();

  if (button1State && cursorX >= activeAreaXLeft && cursorX <= activeAreaXLeft + activeAreaWidth)
  {
    gamePoints = ++gameLevel * 100;
    drawScoreLvlInfo();
    activeAreaWidth *= 0.9;
    cursorX = 18;
    resetWindow();
    delay(100);
  }
  else if (button1State && (cursorX < activeAreaXLeft || cursorX > activeAreaXLeft + activeAreaWidth))
  {
    resetGameScore();
    resetWindow();
  }
}

void openPage()
{
  isPageOpen = true;
  if(isFirstPageLoop == true)
  {
    tft.fillScreen(MAIN_BACKGROUND_COLOR);
  }
  if (selectedMenuItem == 0) 
  {
    showHomePage();
  }
  if (selectedMenuItem == 1) 
  {
    showWiFiSpamPage();
  }
  if (selectedMenuItem == 2) 
  {
    showMorsePage();
  }
  if (selectedMenuItem == 3) 
  {
    showGamePage();
  }
}

void selectDownMenuItem()
{
  ++selectedMenuItem;
  if (selectedMenuItem == numMenuItems) selectedMenuItem = 0;
}

void setup() {
  Serial.begin(115200);

  tft.initR(INITR_MINI160x80); 
  tft.invertDisplay(false);
  tft.setRotation(3);
  tft.fillScreen(MAIN_BACKGROUND_COLOR);
  tft.setCursor(30, 30);
  tft.setTextColor(MAIN_FOREGROUND_COLOR);
  tft.setTextSize(2);
  tft.println("HELLO");
  
  WiFiAuth();
  
  timeClient.begin();

  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_1_PIN, INPUT_PULLUP);
  pinMode(BUTTON_2_PIN, INPUT_PULLUP);
  
  if(enableSound) playStartupSound();
  showMenu();
  
  randomSeed(analogRead(0));
}

void loop() {
  unsigned long currentMillis = millis();
  button1State = digitalRead(BUTTON_1_PIN) == LOW;
  bool button2State = digitalRead(BUTTON_2_PIN) == HIGH;
  
  if (isPageOpen && !button2State)
  {
    openPage();
  }
  else if (isPageOpen && button2State)
  {
    isPageOpen = false;
    selectedMenuItem = 0;
    isFirstPageLoop = true;
    tft.setTextSize(2);
    showMenu();    
  }
  else
  {
    if (button1State)
    {
      if(enableSound && !isPageOpen) playButtonClickSound();
      openPage();
    }
    if (button2State)
    {
      if(enableSound && !isPageOpen) playButtonClickSound();
      selectDownMenuItem();
      showMenu();
    }
  }
}
