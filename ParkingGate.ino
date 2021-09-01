#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = "d3de1a5e76d24f1db1cba1a8e1bf20c7";
char ssid[] = "iPhone";
char pass[] = "guadalajara1";


#include <Servo.h>

Servo myservo;

int pos = 0;
int ESTADOpluma=0;
int aux=0;
const int ledrojo=5;
const int ledverde=15;
const int BUTTON = 4;
const int BUZZER = 0;
int BUTTONstate = 0;


void setup() {
  
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  
  myservo.attach(13);
  myservo.write(45);

  pinMode(ledrojo,OUTPUT);
  pinMode(ledverde,OUTPUT);

  pinMode(BUZZER, OUTPUT);
  pinMode(BUTTON, INPUT);

   digitalWrite(ledrojo,HIGH);
  
}

void loop() {
  Blynk.run();
  
   BUTTONstate= digitalRead(BUTTON);
   if(BUTTONstate==HIGH){
      digitalWrite(BUZZER,HIGH);
   }
   else{
      digitalWrite(BUZZER,LOW);
   }
 
  ESTADOpluma=digitalRead(12);
  if(ESTADOpluma==HIGH){
      digitalWrite(ledrojo,LOW);
      digitalWrite(ledverde,HIGH);
      while(aux<1){
      myservo.write(140);
      delay(1000);
      aux+=1;
      }
  }
 
  if(ESTADOpluma==LOW and aux==1){
    digitalWrite(ledverde,LOW);
    digitalWrite(ledrojo,HIGH);
    myservo.write(45);
    delay(1000);
    aux=0;
  }

  }
  

  
     
