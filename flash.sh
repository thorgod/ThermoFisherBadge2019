#/bin/bash

#Set Fuses
# -B4 is nessecery to set the bit clock in order to set fuses for new attiny's.
avrdude -c usbtiny -p t85 -u -U lfuse:w:0x62:m -U hfuse:w:0xDF:m -U efuse:w:0xFF:m -B4

echo "Fuses set!"

#Burn Firmware
avrdude -c usbtiny -p t85 -u -U flash:w:./.pio/build/attiny85/firmware.hex 

echo "Thermo Badge flashed!"
echo ""
echo ""
read -p "It finished press Any Key [Enter]"
