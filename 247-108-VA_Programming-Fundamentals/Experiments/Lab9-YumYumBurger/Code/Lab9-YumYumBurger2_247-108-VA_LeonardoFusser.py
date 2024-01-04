'''
This program is desinged to calculate how much money will be paid out to a person after 7 days collecting bottles.
The number of bottles are inputted by the user.


Leonardo Fusser (1946995)
Programming Fundamentals (Q4)(Lab 9)
Subash Handa

'''

#[Start of program]


#loop variables
count_days = 1
count_bottle_total = 0

#loop begin
while count_days <= 7:
        count_bottle = int(input("Enter amount of recycled bottles for day %d: " % (count_days)))
        #input error validation
        while count_bottle < 0:
            count_bottle = int(input("Please enter a valid number of bottles recycled for %d: " % (count_days)))
        count_bottle_total += count_bottle
        count_days += 1

#calculation payout
price_bottle = count_bottle_total * 0.1

#page break
print("----------------------------------------------------")

#print to user
print("You recycled %d bottles and have received %.2f $." % (count_bottle_total, price_bottle))


#[End of program]


