#This program is designed to calculate the time it takes for the ball to reach a certain height at a gievn time.
#The values are inputted by the user.

#Code made by Leonardo Fusser (1946995)
#Programming Fundamentals
#Lab 6 (Question 4)
#Subash Handa



#Start of program.



#User input (situation data)
v = float(input("Enter velocity: "))
g = float(input("Enter gravitanional force: "))
h = float(input("Enter height (in meters) : "))


#Importing the "Math" module
import math

#Calculation (time where ball will reach given height)
t1 = (-v - (math.sqrt(math.pow(v, 2))) - 2*g*h)/2*g
t2 = (-v + (math.sqrt(math.pow(v, 2))) - 2*g*h)/2*g
time_to_reach_h = t2-t1

#Print to console window
print("The ball will reach", round(h,2), "m when ", round(time_to_reach_h,2), "s have passed.")




#End of program.
