
[![Arduino CI](https://github.com/RobTillaart/dateTimeHelpers/workflows/Arduino%20CI/badge.svg)](https://github.com/marketplace/actions/arduino_ci)
[![Arduino-lint](https://github.com/RobTillaart/dateTimeHelpers/actions/workflows/arduino-lint.yml/badge.svg)](https://github.com/RobTillaart/dateTimeHelpers/actions/workflows/arduino-lint.yml)
[![JSON check](https://github.com/RobTillaart/dateTimeHelpers/actions/workflows/jsoncheck.yml/badge.svg)](https://github.com/RobTillaart/dateTimeHelpers/actions/workflows/jsoncheck.yml)
[![License: MIT](https://img.shields.io/badge/license-MIT-green.svg)](https://github.com/RobTillaart/dateTimeHelpers/blob/master/LICENSE)
[![GitHub release](https://img.shields.io/github/release/RobTillaart/dateTimeHelpers.svg?maxAge=3600)](https://github.com/RobTillaart/dateTimeHelpers/releases)


# dateTimeHelpers

Arduino library with date and time helper functions.

## Description

This library contains functions that have the goal to help with 
date and time processing.
It is primary a placeholder.

Please report missing functions, open an issue or preferably a PR.


#### Related libraries

- https://github.com/RobTillaart/printHelpers
- https://github.com/RobTillaart/stopWatch_RT
- https://github.com/RobTillaart/CountDown
- https://github.com/RobTillaart/timing


#### Implementation notes

- the function share an output buffer. This can give problems when prints are made fast after each other as the buffer is not printed completely before it is filled again. (think also RTOS)
- math is straightforward, may be optimized? sprintf()?
- code has repeating parts, may be optimized?


## Interface

```cpp
#include "dateTimeHelpers.h"
```

#### Functions

- **void secondsSplit(uint32_t seconds, uint16_t \* days, uint8_t \* hours, uint8_t \* minutes, uint8_t \* sec)** Splits the seconds into days, hours, minutes and seconds. 
This is the math worker for the next three.
- **char \* seconds2clock24(uint32_t seconds, bool displaySeconds = false)** returns "days 00:00:00 .. 23:59:59" or "days 00:00 ..    23:59"
- **char \* seconds2clock12(uint32_t seconds, bool displaySeconds = false)** returns "days 00:00:00 .. 12:59:59" or "days 00:00 ..    12:59". 
Note this function has no morning or afternoon indication.
- **char \* seconds2clockAMPM(uint32_t seconds, bool displaySeconds = false)**
- **char \* millis2clock(uint32_t millis)**


### Convertors

Note: the following do float math so there might occur rounding
- **float weeks(uint32_t seconds)** convert a number of seconds to weeks.
- **float days(uint32_t seconds)** convert a number of seconds to days.
- **float hours(uint32_t seconds)** convert a number of seconds to hours.
- **float minutes(uint32_t seconds)** convert a number of seconds to minutes.


## Future

#### Must

- improve documentation
- test a lot

#### Should 

- optimize secondssplit() (see fast math lib)
- merge code where possible
- extend examples
- unit tests
- create .cpp file, + move code


#### Could

- date math functions 
  - days=date-date or date = date + days
  - day of week
- time math functions
- 64 bit versions of convertors?
- unusual time units for converters?
  - atomic time
- micros2clock()
  - mm:ss:ttt:mmm or mm:ss.ttt.mmm ?
- hour2angle(hh.mm.ss) = angle of the hour hand
  - 12x60x60 = 360� in 1/12th parts
  - idem radians..
- minute2angle(mm.ss) = angle of the minute hand (mm x 6 + ss x 0.1
- seconds2angle(ss) = angle of the seconds hand (ssx6)


#### Won't

