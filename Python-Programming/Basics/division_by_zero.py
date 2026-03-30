#A program using try...except blocks to make sure division by zero function occurs without any errors


def DivExp(a,b):
    try:
        assert a > 0, "A should be greated than 0"
        if b == 0 :
            raise ZeroDivisionError("Division by Zero is not allowed")
        
        c = a / b
        print("The result of division is: ", c)
    
    except Exception as e:
        print(e)

a = int(input("Enter the value of a: "))
b = int(input("Enter the value of b: "))
DivExp(a, b)
