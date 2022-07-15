/*Describe: M5StickC IMU Sensors
 * Class: CSC230
 * Prof: Matthew Prater
 * Date: 4/23/2022
 * Created by: Samuel Dubuisson.
 * Email: samdubui@uat.edu
 * 
 * 
*/

#include <M5StickCPlus.h>

float accX = 0.0F;
float accY = 0.0F;
float accZ = 0.0F;

float maxX = 0.0F;
float maxY = 0.0F;
float maxZ = 0.0F;

float maxAccVec = 0.0F;

void setup() {
  
M5.begin();
M5.Imu.Init();
M5.Lcd.setRotation(3);
M5.Lcd.fillScreen(BLACK);
M5.Lcd.setTextSize(1);
M5.Lcd.setCursor(80, 15);
M5.Lcd.println("Accel TEST");
M5.Lcd.setCursor(30, 30);
M5.Lcd.println("X     Y     Z");
M5.Lcd.setCursor(30, 70);
M5.Lcd.println("maxX   maxY    maxZ");


}

void loop() {
  static float temp = 0;

  M5.IMU.getAccelData(&accX,&accY,&accZ);
  M5.Lcd.setCursor(30, 50);
  M5.Lcd.printf("%5.2f   %5.2f   %5.2f  ", accX,  accY,  accZ);


  if(accX > maxX){
    maxX = accX;
  }
  if(accY > maxY){
    maxY = accY;
  }
    if(accZ > maxZ){
    maxZ = accZ;
  }

  M5.Lcd.setCursor(30, 90);
  M5.Lcd.printf("%5.2f   %5.2f   %5.2f  ", accX,  accY,  accZ);

  if(M5.BtnA.wasPressed()) {
     maxX = 0.0F;
     maxY = 0.0F;
     maxZ = 0.0F;
  }

  float xSq = sq(accX);
  float ySq = sq(accY);
  float zSq = sq(accZ); 

  float accVec = sqrt(xSq + ySq + zSq);
  if(accVec > maxAccVec) {
    maxAccVec = accVec;
  }
  
  M5.Lcd.setCursor(30, 110);
  M5.Lcd.printf("Max Accel %5.2f  ", maxAccVec);

  delay(100);

}
