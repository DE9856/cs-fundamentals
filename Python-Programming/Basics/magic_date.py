#a program to check whether the given input date is a magic date or not

day = int(input("Enter the day"))
month = int(input("Enter the day"))
year = input("Enter year")
year = int(year[-2:])
if month * day==year:
    print("It is a magic date")
else:
    print("It is not a magic date")
