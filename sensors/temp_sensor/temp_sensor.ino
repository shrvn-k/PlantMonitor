#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

int tempPin=A1;
int val,temp;
LiquidCrystal lcd(12,11,2,3,4,5);
void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop()
{
  val=analogRead(tempPin);
  temp=map(val,520,700,0,10); //change these values accordingly
  Serial.println(val);
  lcd.print("Temp level:");
  lcd.setCursor(0,1);
  lcd.print(temp);
  delay(100);
  lcd.clear();
}

