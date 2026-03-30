#code where you can enter the year of birth, and it will tell you whether the person is a senior citizen or not

from datetime import date
today = date.today()
t = today.year
n = int(input("Enter year of birth: "))
age = t-n
if(age>=60):
    print("Senior Citizen")
else:
    print("Not a senior citizen")
