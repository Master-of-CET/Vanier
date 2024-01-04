#!/bin/bash

LED0_PATH=/sys/class/leds/beaglebone:green:usr0
LED1_PATH=/sys/class/leds/beaglebone:green:usr1

function removeTrigger0
{
 echo "none" >> "$LED0_PATH/trigger"
}

function removeTrigger1
{
 echo "none" >> "$LED1_PATH/trigger"
}

echo "[Start of LED script!]"

if [ $# != 2 ]; then
 echo "There is an incorrect number of arguments! Check and try again!"
 echo "[End of script!]"
 exit 2

elif [ "$1" != "on" ] && [ "$1" != "off" ] || [ "$2" != "on" ] && [ "$2" != "off" ]; then
 echo "Arguments not valid! Check and try again!"
 echo "[End of script!]"
 exit 2

fi

if [ "$1" == "on" ] && [ "$2" == "on" ]; then
 echo "Turning [LED0] on!"
 removeTrigger0
 echo "1" >> "$LED0_PATH/brightness"

 echo "Turning [LED1] on!"
 removeTrigger1
 echo "1" >> "$LED1_PATH/brightness"

elif [ "$1" == "off" ] && [ "$2" == "off" ]; then
 echo "Turning [LED0] off!"
 removeTrigger0
 echo "0" >> "$LED0_PATH/brightness"

 echo "Turning [LED1] off!"
 removeTrigger1
 echo "0" >> "$LED1_PATH/brightness"

elif [ "$1" == "on" ] && [ "$2" == "off" ]; then
 echo "Turning [LED0] on!"
 removeTrigger0
 echo "1" >> "$LED0_PATH/brightness"

 echo "Turning [LED1] off!"
 removeTrigger1
 echo "0" >> "$LED1_PATH/brightness"

elif [ "$1" == "off" ] && [ "$2" == "on" ]; then
 echo "Turning [LED0] off!"
 removeTrigger0
 echo "0" >> "$LED0_PATH/brightness"

 echo "Turning [LED1] on!"
 removeTrigger1
 echo "1" >> "$LED1_PATH/brightness"

fi

echo "[End LED script!]"
