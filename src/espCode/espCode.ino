#define SERIAL_BAUD 115200

#include <ESP8266HTTPClient.h>
#include <ESP8266WiFi.h>
#include "json.h"

const char *wifi_ssid = "WiFi network";
const char *wifi_pass = "p4ssw0rd";
const char *invoke_url = "http://someURLToYour.cloudfunctions.net/functionNameProbablyLogData";

//-- generally, anything below this line doesn't have to be touched --
//-- but feel free to have a poke. --

String copyBuffer;
char jsonBuffer[300];

void setup()
{
  copyBuffer.reserve(100);
  Serial.begin(SERIAL_BAUD);

  WiFi.begin(wifi_ssid, wifi_pass);
  Serial.println();
  Serial.println();

  //Serial.printf is a special ESP function, won't work on UNO.
  Serial.printf("connecting to: %s\n", wifi_ssid);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected!");
}

void loop()
{

  delay(2000); //bit of a delay just incase too much data is sent
  DynamicJsonDocument data(1024);
  //JsonArray data = doc.createNestedArray("data");
  deserializeJson(data, Serial);

  if (data.isNull())
  {
    return;
  }

  StaticJsonDocument<JSON_ARRAY_SIZE(30)> doc;

  doc["data"] = data;

  serializeJson(doc, jsonBuffer);

  HTTPClient http;
  http.begin(invoke_url);
  http.addHeader("Content-Type", "application/json");
  int httpCode = http.POST(jsonBuffer);
  http.end();

  Serial.print("Got Code: ");
  Serial.println(httpCode);

  if (httpCode < 0)
    Serial.println(http.errorToString(httpCode));

  Serial.println("Sent:");
  Serial.println(jsonBuffer);
}
// -------------------------------
// functions
