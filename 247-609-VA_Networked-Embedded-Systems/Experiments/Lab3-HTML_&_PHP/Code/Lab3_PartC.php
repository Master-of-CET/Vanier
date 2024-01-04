<!DOCTYPE html>
<html>
<body>


<form action = "/Lab3_PartC.php" method = "get">
<input type = "radio" name = "USR3_LED" value = "led_on">LED ON<br>
<input type = "radio" name = "USR3_LED" value = "led_off">LED OFF<br>
<input type = "radio" name = "USR3_LED" value = "led_toggle">LED blink<br>
<input type = "submit" value = "submit">
</form>


<?php

$rx = $_GET['USR3_LED'];

if ($rx == "led_on"){
	exec("echo none > /sys/class/leds/beaglebone:green:usr3/trigger");
	exec("echo 1 > /sys/class/leds/beaglebone:green:usr3/brightness");
	echo "<br>";
	echo "<br>";
	echo "LED set to turn on!";
}

elseif ($rx == "led_off"){
	exec("echo none > /sys/class/leds/beaglebone:green:usr3/trigger");
	exec("echo 0 > /sys/class/leds/beaglebone:green:usr3/brightness");
	echo "<br>";
	echo "<br>";
	echo "LED set to turn off!";
}

elseif ($rx == "led_toggle"){
	exec("echo heartbeat > /sys/class/leds/beaglebone:green:usr3/trigger");
	echo "<br>";
	echo "<br>";
	echo "LED set to toggle!";
}

echo "<br>";
echo "<br>";
header("refresh: 2");

$LED_PowerState = exec("cat /sys/class/leds/beaglebone:green:usr3/brightness");
$LED_ToggleState = exec("cat /sys/class/leds/beaglebone:green:usr3/trigger");

if ($LED_ToggleState == "none rc-feedback kbd-scrollock kbd-numlock kbd-capslock kbd-kanalock kbd-shiftlock kbd-altgrlock kbd-ctrllock kbd-altlock kbd-shiftllock kbd-shiftrlock kbd-ctrlllock kbd-ctrlrlock nand-disk usb-gadget usb-host mmc0 mmc1 timer oneshot [heartbeat] backlight gpio default-on"){
	echo "Current LED status: TOGGLING";
}

elseif ($LED_PowerState == "1"){
	echo "Current LED status: ON";	
}

elseif ($LED_PowerState == "0"){
	echo "Current LED status: OFF";
}

?>


</body>
</html>