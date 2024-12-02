#define TFT_CS     D4
#define TFT_RST    D3
#define TFT_DC     D2
#define BUZZER_PIN D6
#define BUTTON_2_PIN D8
#define BUTTON_1_PIN D1

// ======== COLORS ========
#define MAIN_FOREGROUND_COLOR 0x0000
#define MAIN_BACKGROUND_COLOR 0xffff

#define GAME_MAIN_LINE_COLOR 0x0000
#define GAME_ACTIVE_AREA_COLOR 0x03E0

#define MORSE_PAGE_CLICK_INFO_COLOR 0x7e0

// ========================


// ========= INUT =========
Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);
// ========================

// ======= SETTINGS =======
// == sound ==
bool enableSound = false;

// == wi-fi ==
const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

// == weather ==
 float longitude = 37.6156, latitude = 55.7522;
String timeZone = "Europe%2FMoscow";
const char* server = "api.open-meteo.com";

// ========================
