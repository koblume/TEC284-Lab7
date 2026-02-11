//Added library for SoftwareSerial to fix Q4
#include <SoftwareSerial.h>
#include "rgb_lcd.h"
#include <Wire.h>
rgb_lcd lcd;

SoftwareSerial mySerial(10,11); //RX, TX pins

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  Serial.begin(9600); //Initalize hardware serial connection
  mySerial.begin(9600); //Initialize software serial connection
  lcd.setRGB(100,255,0);
  lcd.print("Waiting...");
}

void loop() {
  // put your main code here, to run repeatedly:
  if(mySerial.available() > 0){ // if information is ready to be read...
    String recievedMessage = mySerial.readString();
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(recievedMessage); //Display it on the screen
    
  }
}
