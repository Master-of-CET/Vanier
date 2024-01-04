#This program determines what quadrant the values of X & Y are located in. The values of X & Y are inputted by the user.

#Program made by Leonardo Fusser (1946995)
#Programming Fundamentals
#Lab 7 (question 3)
#Subash Handa




#Start of program.




#defining variables
x_var = float(input("Please input the X cordinate: "))
y_var = float(input("Please input the Y cordinate: "))

#page break
print("---------------------------------------")

#[This part of the code determines which quadrant X & Y are located in]



#if in first quadrant
if(x_var > 0 and y_var > 0):
    print("These cordinates are located in the first quadrant!")

#if in second quadrant
elif(x_var < 0 and y_var > 0):
    print("These cordinates are located in the second quadrant!")

#if in third quadrant
elif(x_var < 0 and y_var < 0):
    print("These cordinates are located in the third quadrant!")

#if in fourth quadrant
elif(x_var > 0 and y_var < 0):
    print("These cordinates are located in the fourth quadrant!")

#if none of the above conditions are satisfied
else:
    print("These cordinates are not located in any of the four quadrants. Please check your input and try again!")




#End of program.

              
