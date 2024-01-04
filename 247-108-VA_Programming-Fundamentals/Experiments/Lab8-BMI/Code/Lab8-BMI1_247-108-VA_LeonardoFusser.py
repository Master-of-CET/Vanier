#This program is desinged to calculate a person's BMI and determine if they are overweight or underweight.
#The weight is in pounds and the height is in inches. The values are inputted by the user.

#Program made by Leonardo Fusser (1946995)
#Programming fundamentals
#Lab 8 (Q2)
#Subash Handa



#[Start of Program]



#deine variables
weight = float()
height = float()
BMI = float()

#user input error checking
while True:
    try:
        print("Please enter your weight (in pounds): ")
        weight = float(input())
        break
    except ValueError:
        print("Bad input, try again! Please enter your weight (in pounds): ")
        continue

while True:
    try:
        print("Please enter your height (in inches): ")
        height = float(input())
        break
    except ValueError:
        print("Band input, try again! PLease enter your height (in inches): ")
        continue

#calculations
BMI = (weight *703) /height**2

#page break
print("--------------------------------------------------------------------------")

#conditional statements
if BMI < 18.5:
    print("Your results from your BMI conclude that you're underweight!", round(BMI, 2))
elif BMI > 25:
    print("Your results from your BMI conclude that you're overweight!", round(BMI, 2))
    print("Your results from your BMI conclude that you have an optimal weight!", round(BMI, 2))




#[End of Program]
