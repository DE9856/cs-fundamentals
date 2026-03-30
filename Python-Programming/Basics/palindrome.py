#program to check whether given input string is a palindrome or not

str1 = input("Enter String")
str1.lower()
str2 = str1[::-1]
if str1 == str2:
    print("Palindrome")
else:
    print("Not a palindrome")
