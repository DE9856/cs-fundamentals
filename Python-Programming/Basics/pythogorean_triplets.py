#a program to print all pythogorean triplets within the given range

limit = int(input("Enter range"))
for a in range(1,limit+1):
    for b in range(a,limit+1):
        for c in range(b,limit+1):
            if a*a + b*b == c*c:
                print(a,b,c)
