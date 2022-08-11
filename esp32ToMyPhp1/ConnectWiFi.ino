#include <WiFi.h>

#define NETWORK_NAME "iPhone van Yun"
#define NETWORK_PASSWORD "."

void connectWiFi() {
  //Serial.begin(9600);

  Serial.println("Opstarten");
  delay(2000); // geef de ESP WiFi tijd om op te starten

  WiFi.begin(NETWORK_NAME, NETWORK_PASSWORD);

  while (WiFi.status() != WL_CONNECTED) {
    Serial.println("Verbinden met netwerk " NETWORK_NAME);
    delay(1000);
  }

  Serial.println("! Verbonden met netwerk " NETWORK_NAME);

  // check wat voor IP adres we gekregen hebben
  Serial.print("Mijn IP adres: ");
  Serial.println(WiFi.localIP());

  // toon 't MAC (hardware) adres
  Serial.print("Mijn MAC adres: ");
  Serial.println(WiFi.macAddress());

  Serial.print("RRSI: ");
  Serial.println(WiFi.RSSI());
}
