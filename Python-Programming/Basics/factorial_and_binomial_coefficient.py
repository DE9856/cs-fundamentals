#program to find factorial and binomial coefficient of the given input number

def fact(n):
    if n==0:
        return 1
    else:
        return n * fact(n-1)
n = int(input("Enter n value: "))tu
r = int(input("Enter r value: "))
print("Factorial of n: ",fact(r))
print("Binomial Coefficient: ",fact(n)/(fact(r)*fact(n-r)))
