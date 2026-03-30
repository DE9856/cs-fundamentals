#program to check whether the given number is a perfect number or not

n = int(input("Enter number: "))
res = 0
for i in range(1,n):
    if n%i==0:
        res = res + i
if res ==n:
    print("Perfect number")
else:
    print("Not a perfect number")
