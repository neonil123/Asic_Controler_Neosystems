
// Fill-in information from your Blynk Template here
#define BLYNK_TEMPLATE_ID "TMPL5EGIxbVF"
#define BLYNK_DEVICE_NAME "Asic Control"

#define BLYNK_FIRMWARE_VERSION        "0.1.0"

#define BLYNK_PRINT Serial
//#define BLYNK_DEBUG

#define APP_DEBUG

// Uncomment your board, or configure a custom board in Settings.h
//#define USE_WROVER_BOARD
//#define USE_TTGO_T7

#define rel1 4 
#define rel2 16
#define rel3 17
#define cSense 21 

bool statAsic1 = 0;
bool statAsic2 = 0;
bool statAsic3 = 0;

bool senseStat = 0;

bool onState   = 0; 

long millis1   = 0;



#include "BlynkEdgent.h"

void setup()
{
  Serial.begin(115200);
  delay(100); 
  pinMode(rel1,OUTPUT);
  pinMode(rel2,OUTPUT);
  pinMode(rel3,OUTPUT);
  pinMode(cSense,INPUT);
  
  digitalWrite(rel1,LOW);
  digitalWrite(rel2,LOW);
  digitalWrite(rel3,LOW);
  
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
  main1();
}



void main1(){
 senseStat = digitalRead(cSense);
 Blynk.virtualWrite(V3, senseStat);
 
 if(!senseStat){
  //Blynk.logEvent("no220");
 // Serial.println("no 220");
  millis1 = millis();
  delay(1000);
 }


 
if (millis()- millis1 > 10000){

 if(statAsic1){
  digitalWrite(rel1,HIGH);
 }
 else{
  digitalWrite(rel1,LOW);
 }

  if(statAsic2){
  digitalWrite(rel2,HIGH);
 }
 else{
  digitalWrite(rel2,LOW);
 }


  if(statAsic3){
  digitalWrite(rel3,HIGH);
 }
 else{
  digitalWrite(rel3,LOW);
 }

   
}
else{
  digitalWrite(rel1,LOW);
  digitalWrite(rel2,LOW);
  digitalWrite(rel3,LOW);
}






  
 }





BLYNK_WRITE(V0)
{   
  statAsic1 = param.asInt(); // Get value as integer
}


BLYNK_WRITE(V1)
{   
  statAsic2 = param.asInt(); // Get value as integer
}

BLYNK_WRITE(V2)
{   
  statAsic3 = param.asInt(); // Get value as integer
}
