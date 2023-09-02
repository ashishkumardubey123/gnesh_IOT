/*************************************************************
 Note: If you don't have the ESP32-S in your IDE 'Boards Manager' 
 and cannot search for it,
 then please copy and paste the following URLS 
 to your 'Additional Boards Manager' 
 under Arduino IDE -> Settings...:

 http://arduino.esp8266.com/stable/package_esp8266com_index.json, https://raw.githubusercontent.com/espressif/arduino-esp32/gh-pages/package_esp32_dev_index.json
 
 Once added, try searching for and adding 'ESP32' boards to Arduino IDE.
 GOOD LUCK! 
 - Paul Marriott (@paulmarriott on YouTube)
 *************************************************************

  You’ll need:
   - Blynk IoT app (download from App Store or Google Play)
   - ESP32 board
   - Decide how to connect to Blynk
     (USB, Ethernet, Wi-Fi, Bluetooth, ...)

  There is a bunch of great example sketches included to show you how to get
  started. Think of them as LEGO bricks  and combine them as you wish.
  For example, take the Ethernet Shield sketch and combine it with the
  Servo example, or choose a USB sketch and add a code from SendData
  example.
 *************************************************************/

// Template ID, Device Name and Auth Token are provided by the Blynk.Cloud
// See the Device Info tab, or Template settings
#define BLYNK_TEMPLATE_ID "TMPL3VuOv2fDW"
#define BLYNK_TEMPLATE_NAME "ganesh"
#define BLYNK_AUTH_TOKEN "DK0Az2LbZm5zbUBRUkY2eMIVCT57hpoI"

// Comment this out to disable prints and save space
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "DK0Az2LbZm5zbUBRUkY2eMIVCT57hpoI";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "POCO M3 Pro 5G";
char pass[] = "ashish#123";

int IN1 = 4;
int IN2 = 5;
int IN3 = 12;
int IN4 = 13;


BLYNK_WRITE(V1) { //move forward  
  digitalWrite(IN2, param.asInt());
  digitalWrite(IN4, param.asInt());
}

BLYNK_WRITE(V2) { //move backward
  digitalWrite(IN1, param.asInt());
  digitalWrite(IN3, param.asInt());
}

BLYNK_WRITE(V3) { //turn left
  digitalWrite(IN2, param.asInt());
  digitalWrite(IN3, param.asInt());
}

BLYNK_WRITE(V4) { //turn right
  digitalWrite(IN1, param.asInt());
  digitalWrite(IN4, param.asInt());
}


void setup()
{
  // Debug console
  Serial.begin(115200);

  pinMode(IN1,OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
  // You can also specify server:
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 8080);
  // Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);
}

void loop()
{
  Blynk.run();

  // You can inject your own code or combine it with other sketches.
  // Check other examples on how to communicate with Blynk. Remember
  // to avoid delay() function!
}
