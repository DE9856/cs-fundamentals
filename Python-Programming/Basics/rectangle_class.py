#a program to find midpoint of a rectangle using classes

class rectangle:
    def __init__(self):
        self.width = int(input("Enter width: "))
        self.length = int(input("Enter length: "))
        self.x = int(input("Enter starting x: "))
        self.y = int(input("Enter starting y: "))
    def cp(self):
        self.widthcenter = self.x + (self.width/2)
        self.widthlength = self.y + (self.length/2)
        return self.widthcenter, self.widthlength
r1 = rectangle()
print(r1.cp())
