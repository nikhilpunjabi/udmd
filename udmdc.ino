#include<LiquidCrystal.h>
const int trigPin = 9;
const int echoPin = 10;
LiquidCrystal lcd(12,11,5,4,3,2);

long duration;
int distance;
int percentage;

void setup() {
  lcd.begin(16,2);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
 
}

void loop() {
  digitalWrite(trigPin,LOW) ;
  delayMicroseconds(200);

  digitalWrite(trigPin,HIGH);
  delayMicroseconds(100);

  duration = pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;
  percentage = ((distance-25)/25)*100;
 
  Serial.print("Distance : ");
  delay(250);
    lcd.print("Percentage = ");
  delay(5);  
    lcd.print(distance);
    delay(250);
    lcd.clear();
 
 
    Serial.println(distance);
 
}
