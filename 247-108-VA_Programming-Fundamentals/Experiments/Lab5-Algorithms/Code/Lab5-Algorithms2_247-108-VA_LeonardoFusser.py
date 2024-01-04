#this program is designed to calculate the amount of tips, provincial sales tax
#and federal sales tax. The meal cost is inputted by the user.


#Code made by Leonardo Fusser (1946995)
#Programming Fundamentals
#Lab 5 (Question 4)
#Suabsh Handa



#start of program.



#Defining variables
provincialtax_rate = float(0.09)
federaltax_rate = float(0.05)
tip_rate = float(0.2)

#User input (meal cost data)
print ("Enter the amount of your meal below: ")
meal_cost = float(input())

#Calculation (tip based on meal)
mealcost_tips = meal_cost * tip_rate
mealcost_tips_rounded = round(mealcost_tips, 2)

#Calculation (federal tax data)
federaltax_amount = meal_cost * federaltax_rate
federaltax_amount_rounded = round(federaltax_amount, 2)

#Calculation (provincial tax data)
provincialtax_amount = meal_cost * provincialtax_rate
provincialtax_amount_rounded = round(provincialtax_amount, 2)

#Calculation (total)
totalmeal_cost = provincialtax_amount_rounded + federaltax_amount_rounded + meal_cost
totalmeal_cost_rounded = round(totalmeal_cost, 2)

#Print to console window
print ("Here is your total meal cost... ")
print ("PST: (in $) ", provincialtax_amount_rounded)
print ("GST:(in $) ", federaltax_amount_rounded)
print ("Total tips to be owed:(in $) ", mealcost_tips_rounded)
print ("Total meal cost:(in $) ", totalmeal_cost_rounded)



#end of program.
