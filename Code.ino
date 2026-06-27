#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 32

#define OLED_RESET     -1 
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int sensorPin = A0;
int sensorValue = 0;
int sensorValueMap = 0;

void setup() {
  // put your setup code here, to run once:
  display.begin();
  display.clearDisplay();
  display.setTextColor(SSD1306_WHITE);    

  
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorValue = analogRead(sensorPin);
  sensorValueMap = map(sensorValue, 1023, 0, 0, 100);
  display.clearDisplay();
  display.setCursor(0,0); 
  display.setTextSize(1);
  display.print("Humitat del substrat:");
  display.setTextSize(2);
  display.print(sensorValueMap);
  display.print("%");
  display.setTextSize(1);

  if (sensorValueMap <= 22) {
    display.setCursor(34,20);
    display.print("  Estat: Cal regar");
  }

  else if (sensorValueMap > 22 && sensorValueMap < 61) {
    display.setCursor(34,20);
    display.print("  Estat: Ok, :)");
  }

  else if (sensorValueMap >= 61) {
    display.setCursor(34,20);
    display.print("  Estat: No regui +");
  }

  display.display();

   delay(60000);
}
