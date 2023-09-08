//Tech Trends Shameer
//Control LED Using Blynk 2.0/Blynk IOT

#define BLYNK_TEMPLATE_ID "TMPL3Qeo1m91F"
#define BLYNK_TEMPLATE_NAME "LED Blink"
#define BLYNK_AUTH_TOKEN "dj_xe4VYG7fbzTLH-uKRTf8z2M158InG"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
 

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "POCO M3 Pro 5G";
char pass[] = "ashish#123";  // Enter your Wifi password

int IN1 = 4;
int IN2= 5;
void setup()
{     
  Serial.begin(115200);
  Blynk.begin(auth, ssid, pass);    
  pinMode(IN1,OUTPUT);
    pinMode(IN2,OUTPUT);
  
}

void loop()
{
  Blynk.run(); 
}