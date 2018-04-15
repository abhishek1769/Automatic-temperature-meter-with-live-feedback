#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
pinMode(6,INPUT);
}
float temp1=0;
float humid1=0;
float temp=0;
float humid=0;
int sw1=1;
void loop() {
  // put your main code here, to run repeatedly:
temp=digitalRead(6);
humid=digitalRead(6);
temp1=temp;
humid1=humid;
if(sw1==1){
if(temp1==temp){
  lcd.setCursor(0,0);
  lcd.print("TEMPERATURE=");
  lcd.setCursor(13,0);
  lcd.print(temp);
  delay(2000);
  sw1=2;
}else{
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("TEMPERATURE=");
  lcd.setCursor(13,0);
  lcd.print(temp1);
  delay(2000);
  sw1=2;
}
}else if(sw1==2){
if(humid1==humid){
  lcd.setCursor(0,1);
  lcd.print("HUMIDITY=");
  lcd.setCursor(10,1);
  lcd.print(humid);
  delay(2000);
  sw1=1;
}else{
  lcd.clear();
  lcd.setCursor(0,1);
  lcd.print("HUMIDITY=");
  lcd.setCursor(10,1);
  lcd.print(humid1);
  delay(2000);
  sw1=1;
}
}
}
