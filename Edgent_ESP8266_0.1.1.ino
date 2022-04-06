#define BLYNK_TEMPLATE_ID "TMPLoERPoXGr"
#define BLYNK_DEVICE_NAME "LED Blynk"
#define BLYNK_FIRMWARE_VERSION        "0.1.1"
#define BLYNK_PRINT Serial
#define APP_DEBUG
#define RelayPin1 13 //D7 wrong pin
#define RelayPin2 12 //D6
#define VPIN_BUTTON_1    V1
#define VPIN_BUTTON_2    V2
#define wifiLed   2   
bool toggleState_1 = LOW; //Define integer to remember the toggle state for relay 1
bool toggleState_2 = LOW; //Define integer to remember the toggle state for relay 2

#include "BlynkEdgent.h"

BLYNK_CONNECTED()
{ 
  Blynk.syncVirtual(VPIN_BUTTON_1);
  Blynk.syncVirtual(VPIN_BUTTON_2);
}

BLYNK_WRITE(VPIN_BUTTON_1) {
  toggleState_1 = param.asInt();
  if(toggleState_1 == 1){
    digitalWrite(RelayPin1, LOW);
  }
  else { 
    digitalWrite(RelayPin1, HIGH);
  }
}

BLYNK_WRITE(VPIN_BUTTON_2) {
  toggleState_2 = param.asInt();
  if(toggleState_2 == 1){
    digitalWrite(RelayPin2, LOW);
  }
  else { 
    digitalWrite(RelayPin2, HIGH);
  }
}

void setup()
{
  Serial.begin(115200);
  delay(100);
  
  pinMode(RelayPin1, OUTPUT);
  pinMode(RelayPin2, OUTPUT);
  pinMode(wifiLed, OUTPUT);
  digitalWrite(RelayPin1, HIGH);
  digitalWrite(RelayPin2, HIGH);
  digitalWrite(wifiLed, HIGH);
  BlynkEdgent.begin();
}

void loop() {
  BlynkEdgent.run();
}
