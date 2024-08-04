# Portable notification center with ESP8266

## Description
This project is my first experience in 3D modeling, 3D printing, making draft, microcontroller programming and soldering.

- 3D models: [*link*](https://github.com/spacebagel/PortableNotificationCenter_ESP8266/tree/main/3D%20models)
- code: *link*

## Components
- NodeMcu v3 CH340

![NodeMcu](https://github.com/user-attachments/assets/a518ae98-04c3-412c-af66-ca832b69a79a)

- TFT 0,96 ST7735 IC 80*160

![tft](https://github.com/user-attachments/assets/f2653042-fcff-449f-a87f-c2415d406e3f)

- Buzzer KY-006 KY-012
 
![buzzer](https://github.com/user-attachments/assets/798ce2ee-16f0-4e82-aad6-f2f15dd99fee)

- Buttons x2

![button](https://github.com/user-attachments/assets/bd7959df-eb6c-4532-9665-42a2b992ae7b)

- Switch 1P2T

![switch](https://github.com/user-attachments/assets/9275a60a-c271-44ae-b088-2c091feca2a4)

- Lithium battery ICR18650 3,7V

![battery](https://github.com/user-attachments/assets/f993c509-e99c-40ca-8983-61a2c351906c)

- USB Type-C 5V 2A charge-discharge module
 
![charger](https://github.com/user-attachments/assets/56433555-d19b-489a-adc7-6d6defcabd63)

- 18650 battery case

![case](https://github.com/user-attachments/assets/54c35ac4-8c9c-4cfc-9419-1bc02254136f)


## Equipment and consumables
- 3D printer (KINGROON KP3S)
- PLA plastic
- Soldering iron
- Electrical tape
- Solder
- Rosin
- Wires
- 3 drops of glue
- Screeds

## Software
- FreeCAD (https://www.freecad.org)
- PrusaSlicer (https://github.com/prusa3d/PrusaSlicer/releases)
- Arduino IDE (https://www.arduino.cc/en/software)
- CH340 Driver (https://sparks.gogo.co.nz/ch340.html)

## Setings
Arduino IDE, selected board: 

![board](https://github.com/user-attachments/assets/f5383f68-e8d3-464f-8066-7276657e37e0)

![board_more](https://github.com/user-attachments/assets/b3e62740-8841-4b0f-960f-630f44730f5b)


PrusaSlicer: 

![slicer_main](https://github.com/user-attachments/assets/134c0e7f-3a00-4365-b619-8da64940caf3)

![slicer_other](https://github.com/user-attachments/assets/55342bc1-92a6-46e7-a91f-9da44a4564af)


## Stages 


## Pins
Display: 
- D2 - DC 
- D3 - RST
- D4 - CS
- D5 - ...
- D7 - ...

## Libraries
- ESP8266WiFi
- ESP8266HTTPClient
- ArduinoJson
- Adafruit_GFX
- Adafruit_ST7735
- WiFiClient
- WiFiClientSecure
- WiFiClientSecureBearSSL

## Guides

FreeCAD: https://youtu.be/yQpD8cCA7x4?si=OD5aLB4QK-etjoWo
