# Arduino-Nano-Sized-CH32V003-Dev-Board
The CH32V003F4P6 runs at 48MHz with 16KB of Flash and 2KB of SRAM. It one of the cheapest 32-bit MCUs you can get just in $0.10
See the full article from [Hackster](https://www.hackster.io/sainisagar7294/arduino-nano-sized-ch32v003-dev-board-865573)

In the past few months I had designed my own development boards in order to get max out of them, nowadays I am working on CH32V003F4P6 by WCH, and I was very amazed by the features and performance this microcontroller gives. Why I switched to this one from arduino is because this is a 32-bit RISC-V microcontroller that costs around $0.10 yes, ten cents that makes it one of the cheapest 32-bit MCUs you can get. But you know Arduino is love and that’s why I designed a complete custom dev board around this chip in the Arduino Nano form factor style.


But this time I modified this version with onboard USB-to-serial, a 3.3V LDO, programming header, indicator LEDs, and all GPIOs broken out to 2.54mm headers. The idea is simple to make a minimal, low-cost, open-source development board that anyone can manufacture and assemble. The CH32V003F4P6 runs at 48MHz with 16KB of Flash and 2KB of SRAM.


Which is more than enough for learning embedded programming, reading sensors, driving displays, and building small prototypes. In the future, I will come up with libraries which are compatible with CH32V003 like Arduino. At least the board gives a feel of instant Arduino, even though under the hood it is running a completely different architecture. In this article, I will walk you through the complete hardware design schematic, component selection, PCB layout, and the blink test code. The entire project is open-source, so you can download the design files and build your own. I have made the PCB in EasyEDA and fabricated it out using JLCPCB for just $2: [https://jlcpcb.com/?from=audrey3](https://jlcpcb.com/?from=audrey3). I have also ordered the stencil in order to assemble a few of them for the testing purposes.
