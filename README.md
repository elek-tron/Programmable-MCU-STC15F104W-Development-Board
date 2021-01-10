# Programmable-MCU-STC15F104W-Development-Board
![overview](./Pictures/overview.jpg)

This board consists of a STC15W104W microcontroller and a CH340G USB interface. 
Print is marked: CJMCU-104 found on ebay, ali-express etc
This repository holds:
- The reverse-engineered schematic.
- A tiny demo project.

# Preparation:
Needs a drop of solder to connect all solder islands in the corner of the pcb either on the 5V or 3.3V before using it. 
![CH340 voltage selection](./Pictures/CH340\ voltage\ selection.jpg)

# Software requirements:
- SDCC (free to use compiler w/o any limits like keil)
- AtmelStudio 7 (not needed, but has C beautyfier, editor, make, etc...)
- stc-isp-15xx-v6.88.exe (to program the STC processor)

# Links:
Compiler/Linker SDCC:
http://sdcc.sourceforge.net/
 
Programming software to download into STC processor:
http://www.stcmicro.com/rjxz.html

# Pictures
![Frontside](./Pictures/Front.jpg)

![Backside](./Pictures/Back.jpg)

To understand the hidden connections, removed the crystal:
![wo crystal](./Pictures/wo\ crystal.jpg)

And drawn the two connections between the usb and processor parts of the board.
![wo crystal TxD RxD drawn](./Pictures/wo\ crystal\ TxD\ RxD\ drawn.jpg)
