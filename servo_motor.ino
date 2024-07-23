#define BLYNK_TEMPLATE_ID "TMPL3UXVuncF_"
#define BLYNK_TEMPLATE_NAME "servo motor"
#define BLYNK_AUTH_TOKEN "9I2b6XRBJ3xiHG3BBRBrhTUgt53WDazg"

#define BLYNK_PRINT Serial
#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <ESP32Servo.h>

Servo servo1;

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "GVG";
char pass[] = "vimalesh99";

BLYNK_WRITE(V0)
{
  int s0 = param.asInt();
  servo1.write(s0);
}

void setup() {
  Serial.begin(9600);
  Serial.println("Connecting to WiFi: ");
  Serial.println(ssid);
  
  WiFi.begin(ssid, pass);
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  
  Serial.println("Setup started");
  servo1.setPeriodHertz(50);
  servo1.attach(5); // Attach servo to GPIO pin 5
  Blynk.begin(auth, ssid, pass);
  Serial.println("Setup complete");
  delay(2000);
}

void loop() {
  Blynk.run();
}
