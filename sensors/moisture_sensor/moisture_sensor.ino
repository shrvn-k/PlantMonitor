#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

int moistPin=A2;
int val,moist;
LiquidCrystal lcd(12,11,2,3,4,5);
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  val=analogRead(moistPin);
  moist=map(val,0,100,0,10);    //change these values accordingly
  Serial.println(val);
  lcd.print("Moisture level:");
  lcd.setCursor(0,1);
  lcd.print(moist);
  delay(100);
  lcd.clear();
}

