
<div align="center">
  <h1>Thermo Fisher Badge 2019</h1>
  
   :crystal_ball: 
 [Puzzle Sumbit Awnsers / View Solution](https://forms.gle/YPb5huNXZmUNNtqC8)
 :nut_and_bolt: 
 [PCB Soldering](./hardware/SOLDERING.md)
 :minidisc: 
 [Firmware](https://github.com/thorgod/ThermoFisherBadge2019/)
 :eggplant:
 [PCB Order](./hardware/PCB.md)
 :package: 
 [BOM](./hardware/BOM.md)

</div>

 
<img src="https://644db4de3505c40a0444-327723bce298e3ff5813fb42baeefbaa.ssl.cf1.rackcdn.com/8a477da6db4c1c878bf2dddf7847318c.png"><img src="https://644db4de3505c40a0444-327723bce298e3ff5813fb42baeefbaa.ssl.cf1.rackcdn.com/74715465d474f9708d0b7933d6b577b8.png">

Board Design, Program, and Assembly by Michael Leuer  <br/>
MIT Licence 

***

Code Based on the following sources.

https://github.com/MichMich/Electrocard <br/>
https://github.com/richardkchapman/TinyOLED<br/>
https://github.com/datacute/Tiny4kOLED <br/>
https://github.com/datacute/TinyOLED-Fonts<br/>
https://github.com/jjshortcut/PockeTetris/ <br/>

## Features

- 🔥 OLED Images
- ⚡️ Attiny85 Atmel Chip
- 😍 Tetris 
- 💪 EPROM 
    - Save Name 
    - Save High Score
- 📝 Battery Monitoring 
- 😱 Atari Fonts
- :godmode: 99.9% Flash Ram Used (8 bytes left.)

# QUICK USAGE GUIDE
```
    To be able to switch modes you need to solder the buttons down. View link on how solder buttons.
```

## There are four modes:
Rotation, Save Txt, Tetris, Settings

<img src="https://mikes3ds.com/public/badge/A.png" width="700px">

### **Default:** Rotation
Every 5 seconds it switches between:
1. Thermo Fisher Logo
2. Line1: [Name]  Line2: [Thermo Fisher]
3. AWS Logo
4. Scrolls -> Line1: [Name] Line2: [AWS Re:Invent]

### **Save Text:** Hold TOP button 

<img src="https://mikes3ds.com/public/badge/C.png" width="700px">

~5-10 seconds

It will bring up TXT letting you know you can change your text or name.
The # is under the text indicating what letter you are changing

- TOP Button: *Increment Position*
- LEFT Button: *Select previous letter*
- RIGHT Button: *Select next letter*
- Hold TOP Button: *Saves to Memory current text*

**Tip:** *Hold top button untill you see* `saved`

### **Tetris:** Hold LEFT button 

<img src="https://mikes3ds.com/public/badge/B.png" width="700px">

It will start tetris. 
- TOP Button: *Rotates Piece*
- LEFT Button: *Moves Piece Left*
- RIGHT Button: *Moves Piece Left*

**Tip:** *Turn board 90 degrees. Its easier to hold and play* 



### **Settings/High Score/Battery Monitoring:** Hold RIGHT button 

<img src="https://mikes3ds.com/public/badge/D.png" width="700px">

It will bring up a screen displaying the current battery voltage. It is in MV, a fully charged battery will display 3500mv - it can run down to 800mv I think. (3.5V-.8mv)


# HOW TO PROGRAM

## Programmer

There are several ways of programing an Attiny85. I will explain a two of them. Pick one.

#### 1. SparkFun Programmer ISP (The one I used)
https://www.sparkfun.com/products/11801?_ga=2.197781223.930268666.1574204062-751361143.1571946351

1.  Install
     - 32-bit USBTinyISP Driver -- Windows driver for manual installation on 32-bit systems
http://cdn.sparkfun.com/datasheets/Dev/AVR/usbtinyisp_libusb-win32_1.2.1.0.zip 

     - 64-bit USBTinyISP Driver -- Windows driver for manual installation on 64-bit systems
http://cdn.sparkfun.com/datasheets/Dev/AVR/usbtinyisp_libusb-win32_1.2.1.0.zip
or

View this tutorial.
[https://learn.sparkfun.com/tutorials/tiny-avr-programmer-hookup-guide/all


#### 2. Ardunio  ISP

Follow the guide on this link
https://www.studiopieters.nl/miniaturizing-attiny85/

In platoformio.ini you willl need to change

```
upload_protocol = arduinoisp
```
You might need more stuff, also change com port to correct


```
platform = atmelavr
framework = arduino
board = attiny85
upload_protocol = arduinoisp
upload_flags = -P$UPLOAD_PORT -b$UPLOAD_SPEED
upload_port = COM4
upload_speed = 19200
```

**I have not tried programing with ardunio ISP but it is possible**


## Setup VS Code

1. Install visual studio code
2. Add the extension ```PlatformIO```
   * https://platformio.org/


## Building

In VS Code ProjectIO click on 

The Check Button to build


## Uploading Click Upload

The arrow button is how to upload.



# Contributors

Thanks goes to everyone that helped make it happen

* Michael Leuer
* Nick Rivette
* Scott Woollard
* Adam Schmitz

