# Arduino-Nano-Sized-CH32V003-Dev-Board
The CH32V003F4P6 runs at 48MHz with 16KB of Flash and 2KB of SRAM. It one of the cheapest 32-bit MCUs you can get just in $0.10
See the full article from [Hackster](https://www.hackster.io/sainisagar7294/arduino-nano-sized-ch32v003-dev-board-865573)

In the past few months I had designed my own development boards in order to get max out of them, nowadays I am working on CH32V003F4P6 by WCH, and I was very amazed by the features and performance this microcontroller gives. Why I switched to this one from arduino is because this is a 32-bit RISC-V microcontroller that costs around $0.10 yes, ten cents that makes it one of the cheapest 32-bit MCUs you can get. But you know Arduino is love and that’s why I designed a complete custom dev board around this chip in the Arduino Nano form factor style.

<img width="480" height="270" alt="Image" src="https://github.com/user-attachments/assets/869318e3-0893-4302-a4cb-e48720bc253f" />

But this time I modified this version with onboard USB-to-serial, a 3.3V LDO, programming header, indicator LEDs, and all GPIOs broken out to 2.54mm headers. The idea is simple to make a minimal, low-cost, open-source development board that anyone can manufacture and assemble. The CH32V003F4P6 runs at 48MHz with 16KB of Flash and 2KB of SRAM.

<img width="1024" height="768" alt="Image" src="https://github.com/user-attachments/assets/0a33fa64-0228-4bd3-ac21-0dc1fd9d2c57" />

Which is more than enough for learning embedded programming, reading sensors, driving displays, and building small prototypes. In the future, I will come up with libraries which are compatible with CH32V003 like Arduino. At least the board gives a feel of instant Arduino, even though under the hood it is running a completely different architecture. In this article, I will walk you through the complete hardware design schematic, component selection, PCB layout, and the blink test code. The entire project is open-source, so you can download the design files and build your own. I have made the PCB in EasyEDA and fabricated it out using JLCPCB for just $2: [https://jlcpcb.com/?from=audrey3](https://jlcpcb.com/?from=audrey3). I have also ordered the stencil in order to assemble a few of them for the testing purposes.


**Circuit Diagram**

The board is powered through a USB Type-C connector (U4). I have used two 5.1k pull-down resistors (R4 and R7) on the CC1 and CC2 lines, which is required for USB-C to be recognized as a USB 2.0 device by the host. Without these resistors, many USB-C sources will not provide 5V. The 5V from USB goes to the HT7833-A-EV (U9) low-dropout regulator, which converts it to a clean 3.3V rail. The CH340C (U2) handles USB-to-UART conversion, so you can open a serial monitor and communicate with the CH32V003 directly over USB so no external adapter is needed. I also added TX and RX indicator LEDs (LED3 and LED4) with 1k resistors so you can visually see serial activity.

<img width="1223" height="856" alt="Image" src="https://github.com/user-attachments/assets/11d97e56-ce22-4aee-ba09-9a7d359a65eb" />

The CH32V003F4P6 (U1) sits at the heart of the board. It gets its clock from a 24MHz external crystal. The MCU internally multiplies this to reach its maximum operating frequency of 48MHz using the PLL. The reset button (SW1) is connected to PD7/NRST. I have used a 1k pull-up resistor (R12) and a 100nF debounce capacitor (C9) on the reset line. All available GPIO pins are broken out to two 12-pin female headers (U7 and U8) on either side of the board, just like an Arduino Nano. This gives you easy access to I2C (PC1/SDA, PC2/SCL), SPI, USART, ADC channels, power pins (VIN, 3V3, GND), and general-purpose I/O.

**PCB Design**

I designed the PCB in EasyEDA, keeping the board size compact to match the Arduino Nano form factor. The layout prioritizes clean power distribution in 2 layers only. Then poured the ground plane on both sides for a low-impedance ground return path. Placed the decoupling capacitors as close as possible to the power pins of both the CH32V003 and the CH340C. Crystal is placed near the MCU's oscillator pins with short, symmetric traces. The USB-C connector sits at one end with the CH340C and LDO nearby to keep signal paths short. Programming header is positioned in the end of board for easy access while the board is on a breadboard. The design files are open-source in EasyEDA format, so you can modify the layout and order PCBs from JLCPCB in just $2.

<img width="1239" height="313" alt="Image" src="https://github.com/user-attachments/assets/57a9c673-e8e6-464d-bf44-75cc2ae2287c" />

I have assembled the board myself but trust me without hotplate and proper soldering equipments like microscope and heatgun small components of 0402 size are impossible to solder. But with a skillset of soldering for 5 years I am able to solder this board myself in 2 hours. It takes a lot of solder debugging, But you can choose JLCPCB SMT assembly services to get rid of soldering by hands. All you need is a proper BOM and CPL file which is already attached within this document.

**Blink Test Code**
The first thing I always do with a new board is run a blink test if the LED blinks, you know the MCU is alive, the crystal is working, and your toolchain is set up correctly. Then you can test some given examples within the attached download folder.

<img width="480" height="270" alt="Image" src="https://github.com/user-attachments/assets/1c773293-2279-4975-9de2-01df7a019b53" />

This board is a practical tool for both learning and prototyping. The entire project is open-source with EasyEDA design files, BOM with LCSC part numbers, and over 20 example projects. You can manufacture this board yourself, modify the design, or just use the example code to learn RISC-V embedded programming. In future I will continue this series with some really cool programming stuff. If you have any questions or suggestions, please comment below. I would love to see your builds!
