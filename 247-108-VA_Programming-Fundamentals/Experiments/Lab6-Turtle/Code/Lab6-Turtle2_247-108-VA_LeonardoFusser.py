#This program is designed to calculate the total amount to set-up and paint 4 walls.
#The characteristics of the walls are inputted by the user.

#Leonardo Fusser (1946995)
#Programming Fundamentals
#Lab 6 (Question 3)
#Subash Handa



#Start of program.



#defining variables
height_walls = str(input("Input the height of each wall below (in feet): ")) 
width_walls = str(input("Input the width of each wall below (in feet): ")) 
paint_price = str(input("Input the price of paint per gallon (in dollars): "))

#given variables
wall_time = int(8.0) #time that takes to complete the project
wall_charge = int(45.00) #hourly cost of labour

#calculation (wall square feet)
wall_sqrft = float(height_walls) * float(width_walls)

#calculation (labour)
wall_labour = int(wall_time) * int(wall_charge)
