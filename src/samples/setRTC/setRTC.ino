// look for RTClib  by adafruit 1.3.3
#include "RTClib.h"

RTC_DS1307 rtc;

void setup()
{
  Serial.begin(115200);
  // following line sets the RTC to the date & time this sketch was compiled
  rtc.begin();
  rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));

  Serial.println("OK!"); //that's all you have to do

  for (;;)
    ;
  /*
      Do not keep this sketch programmed, as each time you reboot the device, it will change 
      to whatever time and date that you first uploaded it.

      Instead, copy and paste the below code into your own sketch.
      Once the RTC is initliased (by running this sketch), you will be able to call
      rtc.begin() and use the code as below in your own sketch. 
    */
}

void loop()
{

  //get the time now
  DateTime now = rtc.now();

  //similar to the other code, have a json doc ready.
  /*

  StaticJsonDocument<100> doc;

  // add a timestamp in any format you wish
  
  doc.add( now.toString("YYMMDD-hh:mm:ss") );
  // reads as "200101-13:41:51" or etc.
  it will also ignore (and pass on) whatever isn't the below;

  //hh - the hour with a leading zero (00 to 23) 
  //mm - the minute with a leading zero (00 to 59)
  //ss - the whole second with a leading zero where applicable (00 to 59)

  //YY - the year as two digit number (00-99)
  //MM - the month as number with a leading zero (01-12)
  //DD - the day as number with a leading zero (01 to 31)

  //DDD - the abbreviated English day name ('Mon' to 'Sun') 
  //MMM - the abbreviated English month name ('Jan' to 'Dec')
  //YYYY - the year as four digit number

  //send it to serial
  serializeJson(doc, Serial);

  */
}