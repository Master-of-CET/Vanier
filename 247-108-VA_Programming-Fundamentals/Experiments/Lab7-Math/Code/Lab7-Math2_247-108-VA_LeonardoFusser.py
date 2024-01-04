#This program calculates the total area of a triangle and tells the user if it is a
#"Right-Angled triangle" or "Not a Right-Angled triangle". The dimensions of the triangle are inputted by the user.

#Code made by Leonardo Fusser (1946995)
#Programming Fundamentals
#Lab 7 (Question 2)
#Subash Handa



#Start of program.


import math

#defining variables
a_var = float(input("Please enter your A variable: "))
b_var = float(input("Please enter your B variable: "))
c_var = float(input("Please enter your C variable: "))

#calculate for "s"
s_var = (a_var + b_var + c_var)/2

#calculate for triangle area
trigl_area = math.sqrt((s_var * (s_var - a_var) * (s_var - b_var) * (s_var - c_var)))


a_pow = math.pow(a_var, 2.0)
b_pow = math.pow(b_var, 2.0)
c_pow = math.pow(c_var, 2.0)


#page break
print("---------------------------------------")

#[these two last parts of the code determine what kind of triangle the user inputted]


#It's a Right-Angled triangle!
if c_pow == (b_pow + a_pow):
    print("It's a Right-Angled triangle! :)")
    print("Side A: ", a_var)
    print("Side B: ", b_var)
    print("Side C: ", c_var)
    print("Triangle Area: ", trigl_area)

#It's not a Right-Angled triangle!
else:
    print("It's not a Right-Angled triangle! :(")
    print("Side A: ", a_var)
    print("Side B: ", b_var)
    print("Side C: ", c_var)
    print("Triangle Area: ", trigl_area)




#End of program.
