'''
This program is desinged to print out a spiral shape using the Turtle library.
There are no inputs required by the user.

Leonardo Fusser (1946995)
Programming Fundamentals (Q3)(Lab 9)
Subash Handa

'''

#[Start of program]


#import Turtle library
import turtle

#Turtle variable assignments
myPen = turtle.Turtle()
myPen.speed(0)
myPen.color("#FFF000")

side=400
myPen.penup()
myPen.goto(-200,-200) #position cursor at the bootom right of the screen
myPen.pendown()

#Turtle start spiral
for i in range (1,100):
   myPen.forward(side)
   myPen.left(90)
   side=side-4


#[End of program]
