#takes input of fibonacci series length, and prints fibonacci series for that many numbers

n = int(input("Enter the fibonacci sequence length to be generated: "))
firstnumber = 0
secondnumber = 1
print("Fibonacci sequence: ")
print(firstnumber, end=' ')
print(secondnumber, end=' ')
for i in range(2, n):
    nextnumber = firstnumber + secondnumber
    print(nextnumber, end=' ')
    firstnumber = secondnumber
    secondnumber = nextnumber
