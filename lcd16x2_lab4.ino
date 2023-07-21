#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define pingPin 13
#define inPin 12

LiquidCrystal_I2C lcd(0x27, 16, 2);

float cm1;

void setup()
{
  lcd.begin();
  Serial.begin(9600);
  pinMode(pingPin, OUTPUT);
  pinMode(inPin, INPUT);

  delay(2000);
  cm1 = getDistance();
  Serial.print("cm1 :");
  Serial.println(cm1, 1);

  lcd.setCursor(0, 0);
  lcd.print("Distance :");
  lcd.print(cm1);
  delay(3000);
  lcd.clear();
  lcd.print("Distance :");
  lcd.print("0 cm");
  lcd.clear();
}

void loop()
{
  float cm = getDistance();
  float eiei = cm1 - cm;
  Serial.println(eiei);

  delay(1000);
  lcd.setCursor(0, 0);
  lcd.print("Distance :");
  lcd.print(eiei);

  if (eiei <= 10)
  {
    lcd.setCursor(6, 1);
    lcd.print("Small");
  }
  else if (eiei <= 20)
  {
    lcd.setCursor(6, 1);
    lcd.print("Medium");
  }
  else if (eiei > 20)
  {
    lcd.setCursor(6, 1);
    lcd.print("Large");
  }
}

float getDistance()
{
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);

  float duration = pulseIn(inPin, HIGH);
  return (duration / 1000000) * 173 * 100;
}

