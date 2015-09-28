#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

int lightPin=A0;
int val,light;
LiquidCrystal lcd(12,11,2,3,4,5); //initialize lcd pins
void setup()
{
  Serial.begin(9600);             //start serial and lcd
  lcd.begin(16, 2);
}

void loop()
{
  val=analogRead(lightPin);       //read light value and map b/w 0 to 10
  light=map(val,0,1023,0,10);     //change these values accordingly
  Serial.println(val);            //print to serial monitor
  lcd.print("Light level:");      //print on display
  lcd.setCursor(0,1);             //set cursor to next line
  lcd.print(light);               //print light value
  delay(100); 
  lcd.clear();                    //clear lcd
}

