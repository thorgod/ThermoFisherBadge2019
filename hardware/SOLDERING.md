
<div align="center">
  <h1>Thermo Fisher Badge 2019</h1>
  
  
 :crystal_ball: 
 [Puzzle Sumbit Awnsers / View Solution](https://forms.gle/YPb5huNXZmUNNtqC8)
 :nut_and_bolt: 
 [PCB Soldering](SOLDERING.md)
 :minidisc: 
 [Firmware](https://github.com/thorgod/ThermoFisherBadge2019/)
 :eggplant:
 [PCB Order](PCB.md)
 :package: 
 [BOM](BOM.md)
</div>

# Soldering Badge

> Feel free to skip directly to Buttons with this link



## Soldering 101

Some links:

Through Holes
https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all

Basic Surface Mount for buttons/bat holder https://www.sparkfun.com/tutorials/96

![Soldering 101](https://cerebro.readthedocs.io/en/1.0/_images/soldering101.png)



## Components

3.5V battery, DIP, OLED Screen, 3xBattery, Attiny85 chip

Thermo Fisher PCB, Battery Holder, 3x10k Res, On/Off Switch (Not in picture)

![1](https://mikes3ds.com/public/badge/1.jpg)

Schematic
![27](https://mikes3ds.com/public/badge/schem.png)

## Steps:

### Battery Holder

```
NOTE: Do not add that much solder to center pad, you want to keep the height on solder very small. If not it will break battery holder off. See image of how much I added.
```
##### Part 1: Add pad (To touch battery a tiny bit)


![2](https://mikes3ds.com/public/badge/2.jpg)
![3](https://mikes3ds.com/public/badge/3.jpg)

##### Part 2: Tint
Add solder to top and bottom of holder.
![4](https://mikes3ds.com/public/badge/4.jpg)

##### Part 3: Tap Down Holder + Solder

```
Direction does matter!!!!!!
```

Tape down battery holder in correct position, it will make it easer to work with.
![5](https://mikes3ds.com/public/badge/5.jpg)

Solder it down. + Add extra solder if needed
![6](https://mikes3ds.com/public/badge/6.jpg)

```
 Important: ADD MORE SOLDER, over SOLDER top. This is what holds the badge, we need to make sure its secure. See image below
```
![7](https://mikes3ds.com/public/badge/7.jpg)


### Switch


Place switch on back.
![9](https://mikes3ds.com/public/badge/9.jpg)
Turn over and solder.
![10](https://mikes3ds.com/public/badge/10.jpg)

### DIP
Add DIP on the top. (Do not add Attiny chip tell done)
Direction does not matter.
![11](https://mikes3ds.com/public/badge/11.jpg)
Solder back all 8 pins
![12](https://mikes3ds.com/public/badge/12.jpg)

### OLED Display

Put OLED Display on top
![13](https://mikes3ds.com/public/badge/13.jpg)


Turn over and cut extra pin length down to board. (Leave a tiny bit sticking out)
![14](https://mikes3ds.com/public/badge/14.jpg)
![15](https://mikes3ds.com/public/badge/15.jpg)

Solder Pins
![16](https://mikes3ds.com/public/badge/16.jpg)

# Making Buttons Work

#### Part 1: Jumper Enable
Solder Jumpers
```
The jumper is required to turn on buttons. (* You wont be able to program directly to board after you jump those two pins.) Solder this two holes together to enable buttons
```
![17](https://mikes3ds.com/public/badge/17.jpg)
![18](https://mikes3ds.com/public/badge/18.jpg)


#### Part 2: 3xResistors
Bend the resistors (Direction does not matter)
![19](https://mikes3ds.com/public/badge/19.jpg)

Bend the resistors makes it easier to insert(Direction does not matter)
![20](https://mikes3ds.com/public/badge/20.jpg)
![21](https://mikes3ds.com/public/badge/21.jpg)
Push as far as you can get them into the board. (I placed them on the back)
![21](https://mikes3ds.com/public/badge/22.jpg)

Cut the extra living a tiny bit sticking out
![23](https://mikes3ds.com/public/badge/23.jpg)
Cut the extra living a tiny bit sticking out
![24](https://mikes3ds.com/public/badge/24.jpg)
Solder resistor
![25](https://mikes3ds.com/public/badge/25.jpg)

Do the same for the other two (See images)
![27](https://mikes3ds.com/public/badge/27.jpg)

![27](https://mikes3ds.com/public/badge/28.jpg)
![27](https://mikes3ds.com/public/badge/29.jpg)
![27](https://mikes3ds.com/public/badge/30.jpg)
![27](https://mikes3ds.com/public/badge/31.jpg)
![27](https://mikes3ds.com/public/badge/32.jpg)
![27](https://mikes3ds.com/public/badge/33.jpg)
![27](https://mikes3ds.com/public/badge/34.jpg)

#### Part 3: Surface Mount Buttons

```
This babies are small!!! Open them over a desk, do it slowly.
```

Direction does not matter, try your best to get them in the center;however, as long as each pad is soldered to the button you are good. See images.

![27](https://mikes3ds.com/public/badge/35.jpg)

Add some solder to ONE pad.
![27](https://mikes3ds.com/public/badge/36.jpg)

Place the small button on the pad, and solder
![27](https://mikes3ds.com/public/badge/37.jpg)
![27](https://mikes3ds.com/public/badge/38.jpg)

Add solder and solder to the rest of the pads.
![27](https://mikes3ds.com/public/badge/39.jpg)
![27](https://mikes3ds.com/public/badge/40.jpg)
![27](https://mikes3ds.com/public/badge/41.jpg)
![27](https://mikes3ds.com/public/badge/42.jpg)

```
I did a bad job getting it in the center, because I was taking pictures, try your best to get it in the center. But the thing still works.
```

Repeat for all the buttons (See images)

![27](https://mikes3ds.com/public/badge/43.jpg)
![27](https://mikes3ds.com/public/badge/44.jpg)
![27](https://mikes3ds.com/public/badge/45.jpg)
![27](https://mikes3ds.com/public/badge/46.jpg)
![27](https://mikes3ds.com/public/badge/47.jpg)

## The CHIP

Ground your self by touching the desk. (Dont build up static by rubbing your feet on carpet ect) 

```
Direction is important look at the dot.
```
![27](https://mikes3ds.com/public/badge/49.jpg)

```
Direction is important look at the dot.
```
Grab your chip, Attiny85, bend the pins slighly so its easier to put in the dip.
![27](https://mikes3ds.com/public/badge/50.jpg)

```
Direction is important look at the dot. (ITs toward the bottom)
```

![27](https://mikes3ds.com/public/badge/51.jpg)


```
Direction is important look at the dot. (ITs toward the bottom)
```

![27](https://mikes3ds.com/public/badge/52.jpg)

## FINISHING

```
 WASH YOUR HANDS WHEN YOU ARE DONE....some solder has lead. Dont want to eat that. 
```

![27](https://mikes3ds.com/public/badge/53.jpg)


## USING IT.

All  chips should already be programmed. Contact me if its not.



How to use the program is located at:



 :minidisc: 
 [Firmware](https://github.com/thorgod/ThermoFisherBadge2019/)



