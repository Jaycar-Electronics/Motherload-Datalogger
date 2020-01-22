#include "json.h"

#define SERIAL_BAUD 115200

const long timeout = 6000; //60 seconds timeout, so we don't waste data

unsigned long lastTime = 0;
void setup()
{
  Serial.begin(SERIAL_BAUD);
  //Do any initialisation of sensors here
}

void loop()
{
  // read and track any sensor data here,
  // keep things updated, update averages, etc.

  //timeout function -------------------
  unsigned long elapsed = millis() - lastTime;
  if (elapsed > timeout)
  {
    lastTime = millis();
    // ---------------------------------

    StaticJsonDocument<100> doc;

    // add any data that you want to send here
    doc.add("Running Time:");
    doc.add(millis());

    //send it to serial
    serializeJson(doc, Serial);
    // -------------------------------
  }
}