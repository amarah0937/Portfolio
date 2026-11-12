/*
Name: Amara HIll
Date: May 2026
email: ahill87105@uat.edu
Description:
This program displays "Hello World" on the M5Core2.
The screen has a pink background and white text.
*/

#include <M5Core2.h>      // Include M5Core2 library

// global variables
// axes
float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

// max axes
float maxX = 0.0F;
float maxY = 0.0F;
float maxZ = 0.0F;

// max acceleration
float maxVector = 0.0F;


void setup() {
  M5.begin();            // Initialize M5Core2 and start it
  M5.IMU.Init();         // Initialize M5Core2 sensors
  }

void loop() {
  M5.update(); 
  // Part 1:
  // get directional data
  M5.IMU.getAccelData(&accX, &accY, &accZ);
  // set cursor
  M5.Lcd.setCursor(0, 20);
  // print axes
  M5.Lcd.print("accX, accY, accZ");
  // set cursor
  M5.Lcd.setCursor(0, 42);
  M5.Lcd.printf("%5.2F %5.2F %5.2F", accX, accY, accZ);

  // Part 2A: maxX, maxY and maxZ variable 
  // check and set max axes
  if (accX > maxX) {
    maxX = accX;
  }

  if (accY > maxY) {
    maxY = accY;
  }

  if (accZ > maxZ) {
    maxZ = accZ;
  }

  // set cursor
  M5.Lcd.setCursor(0, 70);
  M5.Lcd.print("maxX, maxY, maxZ");
  // set cursor
  M5.Lcd.setCursor(0, 92);
  // print max axes
  M5.Lcd.printf("%5.2F %5.2F %5.2F", maxX, maxY, maxZ);


  // Part 2B: Xsq, Ysq, Zsq
  // create squared and max value variables
  float accSq = sq(accX) + sq(accY) + sq(accZ);
  float maxMag = sqrt(accSq);

  // check for and set new max
  if (maxMag > maxVector){
    maxVector = maxMag;
  }
  
  // set cursor
  M5.Lcd.setCursor(0, 120);
  // print max value
  M5.Lcd.printf("Maximum Acc: %.2f G", maxVector);

  delay(10);

  // Part 2C: button to clear max vector
  if (M5.BtnA.wasReleased() || M5.BtnA.pressedFor(1000, 200)) {
    maxVector = 0.0F;
    maxX = 0.0F;
    maxY = 0.0F;
    maxZ = 0.0F;

  }
  
  // Part C: flash screen if M5Core2 drops 10cm
   if (maxVector > 1.80F) {
    for (int i = 0; i < 4; i++) {
      M5.Lcd.fillScreen(RED);
      delay(500);                    
      M5.Lcd.fillScreen(WHITE);
      delay(500);
    }
  // reset max acceleration
  maxVector = 0.0F;
  M5.Lcd.fillScreen(Black);
  
  }
  }
