###################################################################################################
#                                                                                                 #
# Name: Leonardo Fusser (1946995)                                                                 #
# Mechatronics & Robotic Systems (247-510-VA)                                                     #
# John F. N. Salik                                                                                #
#                                                                                                 #
# Assignment: Autonomous Self-Driving Robot/Car                                                   #
#                                                                                                 #
# Filename: SelfDriving_Robot.py                                                                  #
#                                                                                                 #
# Description: code for a self-driving robot. The robot consists of a OpenMV camera system, a     #
#              OpenMV pan and tilt shield and a OpenMV motor driver board. The OpenMV is mounted  #
#              in the front of the car. The car is a two-wheel drive system, with a third passive #
#              wheel. A total of four LEDs are mounted around the car. Two are in the front, which#
#              act as signal/status lights, and two are in the rear, which always remain on and act#
#              as leader lights for other cars. The LEDs are red, and the camera has been coded   #
#              two identify two red LEDs that are in front of the car. Depending on the position  #
#              of the identified red LEDs ahead of the car, the car will react/move in certain    #
#              ways. The car is powered by 4x AA sized batteries.                                 #
#                                                                                                 #
###################################################################################################


# [Dependencies required included below]
import sensor, image, time, pyb, utime
from tb6612 import Motor


# [Macro constants]
FULL_SPEED_FORWARD = const(40)
FULL_SPEED_REVERSE = const(-40)
NO_SPEED = const(0)
LED_ON = const(1)
LED_OFF = const(0)
LED_DLY_VeryFast = const(125)
LED_DLY_Fast = const(250)
LED_DLY_Slow = const(500)

# [Variable declarations and initializations]
threshold_index = 0 #Initialize to 0.
x1 = 0              #" ".
y1 = 0              #" ".
x2 = 0              #" ".
y2 = 0              #" ".

# [Generic color tracking: (L min, L max, A min, A max, B min, B max)]
thresholds = [(15, 100, 30, 100, -30, 30)] #Red parameters.

# [OpenMV Camera initialization]
sensor.reset()                          #Reset camera.
sensor.set_pixformat(sensor.RGB565)     #Initialize camera for 16-bit color.
sensor.set_framesize(sensor.QVGA)       #Initialize camera for 320x240 resolution.
sensor.skip_frames(time = 2000)         #Initialize camera refresh rate.

# [Timestamp initialization]
clock = time.clock()                    #Timestamp variable for camera.
InitialTIME = utime.ticks_ms()          #Timestamp for LEDs (gets ticks).

#mask = createEmptyFrame()
#mask = createEmptyFrame(160, 120)
#print(mask)

# [LEDs initialization]
LED1 = pyb.Pin("P4", pyb.Pin.OUT_PP)    #Defines pin P4 (LED1) on OpenMV camera as output.
LED2 = pyb.Pin("P5", pyb.Pin.OUT_PP)    #Defines pin P5 (LED2) on OpenMV camera as output.
LED1_state = LED_OFF                    #LED1 initial state.
LED2_state = LED_OFF                    #LED2 initial state.

# [Motor initialization]
_M1 = Motor(1)  #Defines pin A0 and A1 on OpenMV motor shield as motor 1.
_M2 = Motor(2)  #Defines pin B0 and B1 on OpenMV motor shield as motor 2.

# [LED control function]
def ToggleLED(toggle_LED1, toggle_LED2):
    LED1.value(toggle_LED1)                 #Controls LED1.
    LED2.value(toggle_LED2)                 #Controls LED2.

# [Motor control function]
def MotorCONTROL(MOT1_speed, MOT2_speed):
    _M1.set_speed(MOT1_speed)               #Controls motor 1.
    _M2.set_speed(MOT2_speed)               #Controls motor 2.


# [Runs task below forever]
while(True):

    clock.tick()                    #Timestamp for camera (gets ticks).
    PresentTIME = utime.ticks_ms()  #Timestamp for LEDs (gets ticks).
    img = sensor.snapshot()         #Takes a picture from camera.

    x1 = 0  #Implied statement.
    y1 = 0  #" ".
    x2 = 0  #" ".
    y2 = 0  #" ".

    # [Identifies left red LED]
    for blob in img.find_blobs([thresholds[threshold_index]],roi=(0, 0, 159, 240),pixels_threshold=10, area_threshold=40, merge=True):
        img.draw_rectangle(blob.rect())         #Draw rectangle around left red LED.
        img.draw_cross(blob.cx(), blob.cy())    #Draw cross in the center of the rectangle around left red LED.
        x1 = blob.cx()                          #Capture X value for left red LED.
        y1 = blob.cy()                          #Capture Y value for right red LED.

    # [Identifies right red LED]
    for blob in img.find_blobs([thresholds[threshold_index]],roi=(160, 0, 320, 240),pixels_threshold=10, area_threshold=40, merge=True):
        img.draw_rectangle(blob.rect())         #Draw rectangle around right red LED.
        img.draw_cross(blob.cx(), blob.cy())    #Draw cross in the center of the rectangle around right red LED.
        x2 = blob.cx()                          #Capture X value for right red LED.
        y2 = blob.cy()                          #Capture Y value for right red LED.


    # [Print statement for debugging]
    #print("[X1 value: %d  Y1 value: %d] [X2 value: %d  Y2 value: %d]" %(x1,y1,x2,y2)) #Prints X and Y values for left and right red LEDs.


    # [If no car detected ahead - car stopped]
    if(x1 == 0 and x2 == 0):
        #print("Car is stopped!")                                           #For debugging.
        MotorCONTROL(NO_SPEED,NO_SPEED)                                     #Makes motors stop car.
        if utime.ticks_diff(PresentTIME,InitialTIME) > LED_DLY_VeryFast:
            LED1_state = not LED1_state                                     #LEDs blink very fast.
            LED2_state = not LED2_state                                     #" ".
            ToggleLED(LED1_state,LED2_state)                                #" ".
            InitialTIME = PresentTIME                                       #Timestamp.

    # [If left and right red LEDs drifting right - car turns right]
    elif((x1 < 10) and (x2 < 300)):
        #print("Car turning right!")                                        #For debugging.
        MotorCONTROL(NO_SPEED,FULL_SPEED_FORWARD)                           #Makes motors turn car right.
        if utime.ticks_diff(PresentTIME,InitialTIME) > LED_DLY_Fast:
            LED1_state = not LED1_state                                     #Right LED blinks fast. Left LED stays on.
            ToggleLED(LED1_state,LED_ON)                                    #" ".
            InitialTIME = PresentTIME                                       #Timestamp.

    # [If left and right red LEDs drifting left - car turns left]
    elif((x1 < 130) and (x2 < 10)):
        #print("Car turning left!")                                         #For debugging.
        MotorCONTROL(FULL_SPEED_FORWARD,NO_SPEED)                           #Makes motors turn car left.
        if utime.ticks_diff(PresentTIME,InitialTIME) > LED_DLY_Fast:
            LED2_state = not LED2_state                                     #Left LED blinks slower. Right LED stays on.
            ToggleLED(LED_ON,LED2_state)                                    #" ".
            InitialTIME = PresentTIME                                       #Timestamp.

    # [If left and right red LEDs moving closer together - car reverses]
    elif((x2 - x1) > 135):
        #print("Car moving backwards!")                                     #For debugging.
        MotorCONTROL(FULL_SPEED_REVERSE,FULL_SPEED_REVERSE)                 #Makes motors move car backwards.
        ToggleLED(LED_ON,LED_ON)                                            #Both LEDs stay on.

    # [If left and right red LEDs moving further apart - car moves forward]
    elif((x2 - x1) < 60):
        #print("Car moving forward!")                                       #For debugging.
        MotorCONTROL(FULL_SPEED_FORWARD,FULL_SPEED_FORWARD)                 #Makes motors move car forwards.
        ToggleLED(LED_ON,LED_ON)                                            #Both LEDs stay on.

    # [If left and right red LEDs too far apart - car stopped]
    elif((x2 - x1) > 70):
        #print("Car is stopped!")                                           #For debugging.
        MotorCONTROL(NO_SPEED,NO_SPEED)                                     #Makes motors stop car.
        if utime.ticks_diff(PresentTIME,InitialTIME) > LED_DLY_Slow:
            LED1_state = not LED1_state                                     #LEDs blink slow.
            LED2_state = not LED2_state                                     #" ".
            ToggleLED(LED1_state,LED2_state)                                #" ".
            InitialTIME = PresentTIME                                       #Timestamp.

    # [If all above fails...]
    else:
        ToggleLED(LED_OFF,LED_OFF)  #LEDs off.
        x1 = 0                      #Resets x and y values.
        y1 = 0                      #" ".
        x2 = 0                      #" ".
        y2 = 0                      #" ".
