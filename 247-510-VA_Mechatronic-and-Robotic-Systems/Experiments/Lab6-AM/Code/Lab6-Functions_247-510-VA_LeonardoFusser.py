def function_one(a,b):
    sum=a+b
    return sum
def function_two(numerator=1,divider=1):
    quotient=numerator/divider
    return quotient
def function_three(a,b,numerator=1,divider=1):
    value=(a*numerator)/(b*numerator)+a/divider-b
    return value
def function_four(p1,p2,param1=None,param2=None):
    #Test param1
    if param1==None:
        print('Parameter 1 not specified!')
    # Test param1
    if param2 == None:
        print('Parameter 2 not specified!')

    value=(p1+p2)/(param1+param2)
    return value


#region Example 1: Simple arguments.
a = 1
b = 2
print(function_one(a,b))
#endregion
#region Example 2: Named arguments.
x = 1
y = 2
print(function_two())
print(function_two(divider=3))
print(function_two(divider=3,numerator=2))
#endregion
#region Example 3: Mixed arguments.
g = 1
h = 2
print(function_three(x,y,divider=3))
#endregion
#region Example 4: Testing for missing arguments.
print(function_four(1,2))
#endregion
