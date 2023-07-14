#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define pingPin 13
#define inPin 12
// Set the LCD address to 0x27 or 0x3F for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 16, 2);
 
void setup()
{
// initialize the LCD
lcd.begin();
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(inPin, INPUT);
 
}
void loop() {
 float duration, cm;
  
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  
  duration = pulseIn(inPin, HIGH);
  cm = (duration/ 1000000)*173 *100;

  Serial.println(cm);
  Serial.print("cm");
  Serial.println();

  delay(500);

  // Turn on the blacklight and print a message.

lcd.setCursor(0, 0); // ไปที่ตัวอักษรที่ 0 แถวที่ 1
lcd.print("Distance :");

lcd.setCursor(6, 1); // ไปที่ตัวอักษรที่ 6 แถวที่ 2
lcd.print(cm);
lcd.print(" cm");
}
