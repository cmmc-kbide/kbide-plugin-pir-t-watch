#include <Arduino.h>
#include <pins_arduino.h>
#include <WiFi.h>
#include <WiFiClient.h>
#include <WiFiAP.h>
#include <WebServer.h>
#include <Wire.h>
//#### Screen SETUP ######
#include "SPI.h"
#include <TFT_eSPI.h>
#define BACKLIGHT_CHANNEL   ((uint8_t)1)
#define TFT_BL              12
TFT_eSPI tft = TFT_eSPI();   // Invoke library
//########################

void setup()
{
  // Wire.begin(TOUCH_SDA, TOUCH_SCL);
  // Wire1.begin(SENSOR_SDA, SENSOR_SCL);
  SPI.begin(TFT_SCLK, TFT_MISO, TFT_MOSI, -1); 

  ledcAttachPin(TFT_BL, 1);
  ledcSetup(BACKLIGHT_CHANNEL, 12000, 8);
  ledcWrite(BACKLIGHT_CHANNEL, 255);

  tft.init();
  tft.fillScreen(0xFFFF);
  tft.setRotation(0);
  tft.setTextSize(1);
  tft.setSwapBytes(true);

  pinMode(21, INPUT_PULLUP);
  Serial.begin(115200);

}
void loop()
{
  Serial.println((digitalRead(21)));
  if ((digitalRead(21)) == 1) {
    tft.fillScreen(0xf800);
      tft.setTextSize(3);
      tft.setCursor(30, 100);
      tft.setTextColor(0xffff);
      tft.println(String(String("DETECT !!!")));
      } else {
    tft.fillScreen(0x0);
  }
  delay(500); 
}
