#This program is designed to calculate the amount of county sales tax, state sales tax
#and total sales tax based on monthly sales. The amount of sales are inputted by the user.

#Code made by Leonardo Fusser (1946995)
#Programming Fundamentals
#Lab 5 (Question 3)
#Subash Handa



#Start of program.



#Defining variables
statetax_rate = float(0.04)
countytax_rate = float(0.02)

#User input (sales tax data)
print ("Enter the amount of the sales recieved this month below: ")
month_sales = float(input())

#Calculation (state tax data)
state_amount = month_sales * statetax_rate

#Calculation (county tax data)
county_amount = month_sales * countytax_rate

#Calculation (total tax data)
total_tax = state_amount + county_amount

#Print to console window
print ("These are the taxes you owe as defined below...")
print ("Amount of State Tax:(in $) ", state_amount)
print ("Amount of County Tax:(in $) ", county_amount)
print ("Your total tax amount is:(in $) ", total_tax)



#End of program.
