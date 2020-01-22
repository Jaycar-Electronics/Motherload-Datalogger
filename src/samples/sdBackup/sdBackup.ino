#include <SPI.h>
#include <SD.h>
#include "RTClib.h"

const int chip_select = 10;

RTC_DS1307 rtc;

void setup()
{
  rtc.begin(); //the rtc should be init using the setRTC example, first.

  pinMode(chip_select, OUTPUT);
  SD.begin(chip_select);
}
void loop()
{
  //hourly log files, you could make minute logs by adding 'mm'
  //consult RTC sample for info
  String filename = rtc.now().toString("YYMMDDhh.log");

  File f = SD.open(filename, 'a');
  if (!f)
  {
    //failed to open; if it doesn't exist, try creating:
    f = SD.open(filename, 'w');
    if (!f)
    {
      //you will have to manage your own error here, maybe add info to the sheet?
      Serial.println("failed to open sd file");
      for (;;)
        ;
    }
  }

  // make json doc as normal
  // gather data

  /*

  StaticJsonDocument<100> doc;

  // add any data that you want to send here
  doc.add("Running Time:");
  doc.add(millis());

  //send it to serial (to ESP)
  serializeJson(doc, Serial);

  //send it to file as well.
  serializeJson(doc, f);

  //if it's too slow to send to file, read more here:
  // https://arduinojson.org/v6/faq/why-is-arduinojson-slow/ 
  */
}