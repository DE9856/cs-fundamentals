#program to find factorial of a number

n = int(input("What is the number you want to take the factorial of: "))
if n==0:
    print("Factorial is 0")
elif n<0:
    print("Enter a positive number")
else:
    fact = 1
    for i in range(1,n+1):
        fact = fact *i
    print(fact)
