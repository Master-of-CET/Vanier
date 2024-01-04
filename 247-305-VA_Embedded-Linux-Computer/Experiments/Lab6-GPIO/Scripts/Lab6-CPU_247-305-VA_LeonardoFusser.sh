#!/bin/bash
# Created by Serge Hould
# Modified by Leonardo Fusser (1946695)

LED0_PATH=/sys/class/leds/beaglebone:green:usr0		#path for LED0
LED1_PATH=/sys/class/leds/beaglebone:green:usr1		#path for LED1
LED2_PATH=/sys/class/leds/beaglebone:green:usr2		#path for LED2
LED3_PATH=/sys/class/leds/beaglebone:green:usr3		#path for LED3
PREV_TOTAL=0
PREV_IDLE=0
MAX=90

echo
echo "[Start of script!]"
echo
echo "Program started..."
echo "Do [CTRL+C] to stop program!"
echo
echo

while true; do

	Date=($(cat "/sys/class/rtc/rtc0/date"))
	Time=($(cat "/sys/class/rtc/rtc0/time"))

        # Get the total CPU statistic.
        CPU=($(cat "/proc/stat"))
        IDLE=${CPU[4]} # Just the idle CPU time.

        # Calculate the total CPU time.
        TOTAL=0
        let "TOTAL=${CPU[1]}+${CPU[2]}+${CPU[3]}+${CPU[4]}"
  # Calculate the CPU usage since we last checked.
        let "DIFF_IDLE=$IDLE-$PREV_IDLE"
        let "DIFF_TOTAL=$TOTAL-$PREV_TOTAL"
        let "DIFF_USAGE=(1000*($DIFF_TOTAL-$DIFF_IDLE)/$DIFF_TOTAL+5)/10"
	echo -en "\b\b"
        echo -en "\rCPU: $DIFF_USAGE%"
	echo

	#(If CPU usage is greater than 90%...)
	if [ "$DIFF_USAGE" -gt "$MAX" ]; then
	 echo "1" > "$LED0_PATH/brightness"	#turn on LED0
         echo "1" > "$LED1_PATH/brightness"	#turn on LED1
         echo "1" > "$LED2_PATH/brightness"	#turn on LED2
	 echo "1" > "$LED3_PATH/brightness"	#turn on LED3

	#(If CPU usage is less than 90%...)
	else
	 echo "0" > "$LED0_PATH/brightness"	#turn off LED0
	 echo "0" > "$LED1_PATH/brightness"	#turn off LED1
	 echo "0" > "$LED2_PATH/brightness"	#turn off LED2
	 echo "0" > "$LED3_PATH/brightness"	#turn off LED3

	fi

	sleep 9					#wait 10 secs.

	#(Write current date, time & CPU usage to syslog)
	echo "$Date" "$Time" "$DIFF_USAGE %" >> /var/log/syslog

        # Remember the total and idle CPU times for the next check.
        PREV_TOTAL="$TOTAL"
        PREV_IDLE="$IDLE"
        # Wait before checking again.
        sleep 1
done
