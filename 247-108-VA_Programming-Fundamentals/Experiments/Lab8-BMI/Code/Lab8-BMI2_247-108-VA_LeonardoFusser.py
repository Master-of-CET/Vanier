#This program is designed to correctly format the amount of seconds to either the amount of minutes, hours, days or all three of them.
#The amount of seconds is inputted by the user.

#Program made by Leonardo Fusser (1946995)
#Programming Fundamentals
#Lab 8 (Q3)
#Subash Handa



#[Start of Program]




#define variables
seconds = float()
minutes = float()
hours = float()
days = float()
duration_mins = float(60.0)
duration_hrs = float(3600.0)
duration_days = float(86400.0)

#input error validation
while True:
        try:
            print("Enter a number of seconds: ")
            seconds = float(input())
            break
        except ValueError:
            print("Try again! Enter a number of seconds: ")

#Function 1
def minutesFunction(seconds):
    if seconds >= 60:
        minutes = seconds / duration_mins
        minutes = round(minutes, 2)
        return minutes
    else:
        print("There are not enough seconds to convert into minutes!")

#Function 2
def hoursFunction(seconds):
    if seconds >= 3600:
        hours = seconds / duration_hrs
        hours = round(hours, 2)
        return hours
    else:
        print("There are not enough seconds to convert into hours!")

#Function 3
def daysFunction(seconds):
    if seconds >= 86400:
        days = seconds / duration_days
        days = round(days, 2)
        return days
    else:
        print("There are not enough seconds to convert into days!")

#page break
print("----------------------------------------------------")

#user output
print("The number of seconds: ", seconds)
print("The number of minutes: ", minutesFunction(seconds))
print("The number of hours: ", hoursFunction(seconds))
print("The number of days: ", daysFunction(seconds))




#[End of Program]


