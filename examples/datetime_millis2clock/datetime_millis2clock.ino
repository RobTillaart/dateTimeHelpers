//
//    FILE: datetime_datetime_millis2clock.ino
//  AUTHOR: Rob Tillaart
// PURPOSE: demo datetime_millis2clock
//     URL: https://github.com/RobTillaart/dateTimeHelpers


#include "dateTimeHelpers.h"

uint32_t start, stop, duration1;

void setup()
{
  Serial.begin(115200);
  Serial.println(__FILE__);
}


void loop()
{
  uint32_t mil = micros();  //  simulation

  Serial.println(millis2clock(mil));
  delay(1234);
}


// -- END OF FILE --
