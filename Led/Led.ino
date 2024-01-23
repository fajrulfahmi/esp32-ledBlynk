#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#define BLYNK_PRINT Serial

#define BLYNK_TEMPLATE_ID "TMPL6cfwbj2Zi"
#define BLYNK_TEMPLATE_NAME "LED"
#define BLYNK_AUTH_TOKEN "E6G5uL_U-6t_g4elo56KfmralSGR0uYa"

//Led pin 13
#define redLed 13

//Blynk Wifi Config
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "admin";
char pass[] = "12345678";

BLYNK_WRITE(V0) {
  int btn = param.asInt(); //Cek Data Button
  Serial.print("BUTTON RED LED:"); Serial.println(btn);
  if (btn == 1)digitalWrite(redLed, HIGH); //1-ON , 0-OFF
  if (btn == 0)digitalWrite(redLed, LOW);
}

void setup() {
  Serial.begin(9600);
  pinMode(redLed, OUTPUT); //Led Output
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80); //Blynk Config
  Serial.println(Blynk.connected());
  Serial.println("OK");
}

void loop() {
  Blynk.run();
}
