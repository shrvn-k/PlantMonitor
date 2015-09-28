#include <LiquidCrystal.h>
#include <SoftwareSerial.h>

//Initialize pins for sensors
int lightPin=A0;
int tempPin=A1;
int moistPin=A2;

int warningLed=10;  //pin for warning led
int val,light,moist,temp;
LiquidCrystal lcd(12,11,2,3,4,5); //specify pins used for lcd
void setup()
{
  pinMode(warningLed,OUTPUT);     //initialize warning pin and output
  Serial.begin(9600);             //begin serial output
  lcd.begin(16, 2);               //specify size of display (col,row)
}

void loop()
{

  //read and print light value
  val=analogRead(lightPin);       //read light value
  light=map(val,0,1023,0,10);     //map between 0-10
  if(light<3)                     //check if level too low
    digitalWrite(warningLed,HIGH); //turn on warning led
  lcd.print("Light level:");      //print value to lcd
  lcd.setCursor(0,1);
  lcd.print(light);
  delay(4000);                    //wait 4 seconds
  digitalWrite(warningLed,LOW);   //set warning led off
  lcd.clear();                    //clear lcd

  //read and print tempereature value
  val=analogRead(tempPin);
  temp=map(val,520,700,0,10);
  if(temp<3)
    digitalWrite(warningLed,HIGH);
  lcd.print("Temp level:");
  lcd.setCursor(0,1);
  lcd.print(temp);
  delay(4000);
  digitalWrite(warningLed,LOW);
  lcd.clear();
  val=analogRead(moistPin);

  //read and print moisture value
  moist=map(val,0,100,0,10);
  if(moist<3)
    digitalWrite(warningLed,HIGH);
  lcd.print("Moisture level:");
  lcd.setCursor(0,1);
  lcd.print(moist);
  delay(4000);
  digitalWrite(warningLed,LOW);
  lcd.clear();

  //print values to serial monitor
  Serial.print("Running time:");
  Serial.println(millis()/1000);    //prints total running time
  Serial.print("Light level:");
  Serial.println(light);
  Serial.print("Temperature level:");
  Serial.println(temp);
  Serial.print("Moisture level:");
  Serial.println(moist);
  Serial.println(" ");
}

