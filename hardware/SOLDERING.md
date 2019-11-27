
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

<img src="https://mikes3ds.com/public/badge/topbanner.jpg" >


# Soldering Badge

> Feel free to skip directly to Buttons with this link

[Go directlyl to soldering buttons](#Making-Buttons-Work)


## Soldering 101

Some links:

Through Holes
https://learn.sparkfun.com/tutorials/how-to-solder-through-hole-soldering/all

Basic Surface Mount for buttons/bat holder https://www.sparkfun.com/tutorials/96

![Soldering 101](https://cerebro.readthedocs.io/en/1.0/_images/soldering101.png )



## Components

3.5V battery, DIP, OLED Screen, 3xBattery, Attiny85 chip

Thermo Fisher PCB, Battery Holder, 3x10k Res, On/Off Switch (Not in picture)
<img src="https://mikes3ds.com/public/badge/1.jpg" width="700px">


Schematic


<img src="https://mikes3ds.com/public/badge/schem.png" width="700px">


## Steps:

### Battery Holder

```
NOTE: Do not add that much solder to center pad, you want to keep the height on solder very small. If not it will break battery holder off. See image of how much I added.
```
##### Part 1: Add pad (To touch battery a tiny bit)


<img src="https://mikes3ds.com/public/badge/2.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/3.jpg" height="400px">

##### Part 2: Tint
Add solder to top and bottom of holder.

<img src="https://mikes3ds.com/public/badge/4.jpg" height="400px">

##### Part 3: Tap Down Holder + Solder

```
Direction does matter!!!!!!
```

Tape down battery holder in correct position, it will make it easer to work with.

<img src="https://mikes3ds.com/public/badge/5.jpg" height="400px">

Solder it down. + Add extra solder if needed

<img src="https://mikes3ds.com/public/badge/6.jpg" height="400px">

```
 Important: ADD MORE SOLDER, over SOLDER top. This is what holds the badge, we need to make sure its secure. See image below
```

<img src="https://mikes3ds.com/public/badge/7.jpg" height="400px">


### Switch


Place switch on back.

<img src="https://mikes3ds.com/public/badge/9.jpg" height="400px">

Turn over and solder.

<img src="https://mikes3ds.com/public/badge/10.jpg" height="400px">

### DIP
Add DIP on the top. (Do not add Attiny chip tell done)
Direction does not matter.

<img src="https://mikes3ds.com/public/badge/11.jpg" height="400px">

Solder back all 8 pins

<img src="https://mikes3ds.com/public/badge/12.jpg" height="400px">

### OLED Display

Put OLED Display on top

<img src="https://mikes3ds.com/public/badge/13.jpg" height="400px">


Turn over and cut extra pin length down to board. (Leave a tiny bit sticking out)

<img src="https://mikes3ds.com/public/badge/14.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/15.jpg" height="400px">

Solder Pins

<img src="https://mikes3ds.com/public/badge/16.jpg" height="400px">

# Making Buttons Work

#### Part 1: Jumper Enable
Solder Jumpers
```
The jumper is required to turn on buttons. (* You wont be able to program directly to board after you jump those two pins.) Solder this two holes together to enable buttons
```
<img src="https://mikes3ds.com/public/badge/17.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/18.jpg" height="400px">

#### Part 2: 3xResistors
Bend the resistors (Direction does not matter)

<img src="https://mikes3ds.com/public/badge/19.jpg" height="400px">

Bend the resistors makes it easier to insert(Direction does not matter)

<img src="https://mikes3ds.com/public/badge/20.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/21.jpg" height="400px">

Push as far as you can get them into the board. (I placed them on the back)

<img src="https://mikes3ds.com/public/badge/22.jpg" height="400px">

Cut the extra living a tiny bit sticking out 

<img src="https://mikes3ds.com/public/badge/23.jpg" height="400px">

Cut the extra living a tiny bit sticking out

<img src="https://mikes3ds.com/public/badge/24.jpg" height="400px">

Solder resistor

<img src="https://mikes3ds.com/public/badge/25.jpg" height="400px">

Do the same for the other two (See images)

<img src="https://mikes3ds.com/public/badge/27.jpg" height="400px">

<img src="https://mikes3ds.com/public/badge/28.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/29.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/30.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/31.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/32.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/33.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/34.jpg" height="400px">

#### Part 3: Surface Mount Buttons

```
This babies are small!!! Open them over a desk, do it slowly.
```

```
Nick Rivette, suggests a small dab of super glue to keep in the correct position before soldering. 
```

Direction does not matter, try your best to get them in the center;however, as long as each pad is soldered to the button you are good. See images.

<img src="https://mikes3ds.com/public/badge/35.jpg" height="400px">

Add some solder to ONE pad.

<img src="https://mikes3ds.com/public/badge/36.jpg" height="400px">

Place the small button on the pad, and solder

<img src="https://mikes3ds.com/public/badge/37.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/38.jpg" height="400px">

Add solder and solder to the rest of the pads.

<img src="https://mikes3ds.com/public/badge/39.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/40.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/41.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/42.jpg" height="400px">

```
I did a bad job getting it in the center, because I was taking pictures, try your best to get it in the center. But the thing still works.
```

Repeat for all the buttons (See images)

<img src="https://mikes3ds.com/public/badge/43.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/44.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/45.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/46.jpg" height="400px">
<img src="https://mikes3ds.com/public/badge/47.jpg" height="400px">

## The CHIP

Ground your self by touching the desk. (Dont build up static by rubbing your feet on carpet ect) 

```
Direction is important look at the dot.
```
<img src="https://mikes3ds.com/public/badge/49.jpg" height="400px">


```
Direction is important look at the dot.
```
Grab your chip, Attiny85, bend the pins slighly so its easier to put in the dip.

<img src="https://mikes3ds.com/public/badge/50.jpg" height="400px">


```
Direction is important look at the dot. (ITs toward the bottom)
```

<img src="https://mikes3ds.com/public/badge/51.jpg" height="400px">


```
Direction is important look at the dot. (ITs toward the bottom)
```

<img src="https://mikes3ds.com/public/badge/52.jpg" height="400px">

## FINISHING

```
 WASH YOUR HANDS WHEN YOU ARE DONE....some solder has lead. Dont want to eat that. 
```

<img src="https://mikes3ds.com/public/badge/53.jpg" height="400px">


## USING IT.

All  chips should already be programmed. Contact me if its not.



How to use the program is located at:



 :minidisc: 
 [Firmware](https://github.com/thorgod/ThermoFisherBadge2019/)



