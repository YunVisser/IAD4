///////////////Created by Gledis Qose//////////////////
//https://www.youtube.com/watch?v=y6LRbCTHZGQ

#include <HTTPClient.h>
#include <ArduinoJson.h>

const int ledPin1 = 17;
const int ledPin2 = 22;
int fsr1 = 33; // verbonden met analoog
int fsr2 = 36; // verbonden met analoog

HTTPClient client;


void setup()
{
  Serial.begin(9600);

  pinMode(PushButtonT, INPUT); // pin 4 digital input
  pinMode(PushButtonW, INPUT);  // pin 15

  pinMode(fsr1, INPUT); //  pin 33 //0 tot 1
  pinMode(fsr2, INPUT); //  pin 36 //0 tot 1

  pinMode(ledPin1, OUTPUT); // pin 17
  pinMode(ledPin2, OUTPUT); // pin 22

  analogWrite(ledPin1, 255);
  analogWrite(ledPin2, 255);

  connectWiFi();

  // laat de verbinding met de server openstaan (als mogelijk)
  client.setReuse(true);
}


void loop()
{
  String protocol = "https";
  String host = "studentdav.hku.nl";

  // haal alle waardes op
  String request = "/~yun.visser/homework/Km_IAD4/data-insert.php";
  String request = "/~yun.visser/homework/Km_IAD4/device_overview.php";

  String url = protocol + "://" + host + request;

  String response = "";
  client.begin(url);

  Serial.println("Send request...");
  Serial.println(url);
  int httpResultCode = client.GET();
  if (httpResultCode = HTTP_CODE_OK) {
    String response = client.getString();
    Serial.print(httpResultCode);
    Serial.print(":");
    Serial.println(response);

    DynamicJsonDocument doc(256);
    DeserializationError err = deserializeJson(doc, response);

    if (!err) {
      Serial.println(F("JSON parsed OK"));

      int slider1 = doc["slider1"];
      Serial.print("slider1=");
      Serial.println(slider1);
      analogWrite(6, 255 - slider1 / 8);
    } else {
      Serial.println(F("JSON incorrect?"));
      Serial.println(err.c_str());
    }
  } else {
    Serial.print("Error in request: code=");
    Serial.println(httpResultCode);
    delay(3000);
  }
  delay(1000);
}

//
//  int fsrWaarde = analogRead(fsr1);
//  Serial.println(fsrWaarde);
//
//  if (fsrWaarde < 4000) {
//    digitalWrite(ledPin1, HIGH);
//  } else {
//    digitalWrite(ledPin1, LOW);
//  }
//
//  int fsrWaarde2 = analogRead(fsr2);
//  Serial.println(fsrWaarde2);
//
//  if (fsrWaarde2 < 4000) {
//    digitalWrite(ledPin2, HIGH);
//  } else {
//    digitalWrite(ledPin2, LOW);
//  }
