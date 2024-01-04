'''
This program is designed to replicate three basic funtions of a calculator. The two numerical values are inputted by the user.

Program made by: Leonardo Fusser (1946995)
For: Subash Handa
Programming Fundamentals
(Lab 11)(Question 2)

'''


#[Start of program]


#variable definition
def main():
  operations_list = ["1.Addition", "2.Subtraction", "3.Multiplication", "4.Division"]
  print('Here are some operations:')
  print(*operations_list, sep='\n')
  print("------------------------------")
  Operation = input("Choose your operation: ")
  print("------------------------------")
  
  while True:
    try:
      num1 = float(input('Enter a number: '))
      num2 = float(input('Enter another number: '))
      break
    except ValueError:
      float(input('Try again! Please only enter a numerical value!: '))
  return Operation,num1,num2   

#page break
print("------------------------------")


#(Defining the calculator operations)

#Addition
def add(num1,num2):
  print(num1 + num2)

#Substraction
def substract(num1,num2):
  print(num1 - num2)

#Multiplication
def multiply(num1,num2):
  print(num1 * num2)

#Division
def divide(num1,num2):
  print(num1 / num2)



def operations():

#selection based on user input
  if Operation == '1':
    add(num1,num2)

  elif Operation == '2':
    substract(num1,num2)

  elif Operation == '3':
    multiply(num1,num2)
    
  elif Operation == '4':
    divide(num1,num2)
  

Operation,num1,num2 = main()
print(num1,num2)
operations()


#quit or continue
while True:
  print("------------------------------")
  calcstate = input('Would you like to end the program? Yes-end, No-continue: ')
  print("------------------------------")
  if calcstate == 'Yes':
                  break
  else:
       Operation,num1,num2 = main()
       print(num1,num2,Operation)
       operations()



#[End of program]
