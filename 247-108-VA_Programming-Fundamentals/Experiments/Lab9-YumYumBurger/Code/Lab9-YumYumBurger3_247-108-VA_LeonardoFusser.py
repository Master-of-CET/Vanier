''' 
This program is designed to calculate the total cost of purchasing a meal.
The selection choice is made by the user.

Leonardo Fusser (1946995)
Programming Fundamentals (Lab 9)(Question 5)
Subash Handa

'''

#[Start of Program]



#variable definition
burger = ('Yum Yum Burger costs $.99')
fries = ('Grease Yum Fries costs $.79')
soda = ('Soda Yum costs $1.09')
menu = [burger,fries,soda]

#user selection options
print(*menu , sep='\n')

#page break
print('--------------------------------------')

#input validation
num_burgers = int(input("Enter number of Yum Yum Burgers: "))
while num_burgers < 0:
    print("Please enter a valid number of Yum Yum Burgers!")
    num_burgers = int(input())

            
num_fries = int(input("Enter number of Grease Yum Fries: "))
while num_fries < 0:
    print("Please enter a valid number of Yum Fries!")
    num_fries = int(input())


num_soda = int(input("Enter a valid number of Soda Yums: "))
while num_soda < 0:
    print("Please enter a valid number of Soda Yums!")
    num_soda = int(input())

#menu items cost
price_burger = num_burgers * 0.99
price_fries = num_fries * 0.79
price_soda = num_soda * 1.09

#price calculation
total = price_burger + price_fries + price_soda

#amount of tax charged
tax = 0.6
total_tax = tax * total

#meal price with tax
totalprice_taxed = total_tax + total

#page break
print("---------------------------------------")

#[print to user console]
print("Number of Yum Yum Burgers ordered: ", num_burgers)
print("Number of Grease Yum Fries ordered: ", num_fries)
print("Number of Soda Yums ordered: ", num_soda)
#page break
print("---------------------------------------")
print("The total cost of your meal is $ %.2f " % totalprice_taxed)
print("The total amount of tax charged is $ %.2f " % total_tax)




#[End of program]
    
    
    
    


            

