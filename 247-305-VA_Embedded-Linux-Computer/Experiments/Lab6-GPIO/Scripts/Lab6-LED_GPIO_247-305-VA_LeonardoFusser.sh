#!/bin/bash
#Created by Leonardo Fusser (1946995)

echo "[Start of script!]"

echo 60 > /sys/class/gpio/export				#export
echo out > /sys/class/gpio/gpio60/direction			#set as output

#(Turning LED on for 10 secs.)
echo 1 > /sys/class/gpio/gpio60/value				#output HIGH
echo
echo "Turning ON LED at pin 12 (GPIO 60) for 10 seconds..."
sleep 10							#wait 10 secs.

#(Turning LED off for 10 secs.)
echo 0 > /sys/class/gpio/gpio60/value				#output LOW
echo "Turning OFF LED at pin 12 (GPIO 60) for 10 seconds..."
echo
sleep 10							#wait 10 secs.

echo 60 > /sys/class/gpio/unexport				#unexport

echo "[End of script!]"
