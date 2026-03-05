//Shape.java
public class Shape{
    public void draw(){
        System.out.println("Drawing Shape");
    }
    public void erase(){
        System.out.println("Erasing Shape");
    }
}

//Circle.java
public class Circle extends Shape{
    @Override
    public void draw(){
        System.out.println("Drawing Circle");
    }
    @Override
    public void erase(){
        System.out.println("Erasing Circle");
    }
}

//Triangle.java
public class Triangle extends Shape{
    @Override
    public void draw(){
        System.out.println("Drawing Triangle");
    }
    @Override
    public void erase(){
        System.out.println("Erasing Triangle");
    }
}

//Square.java
public class Square extends Shape{
    @Override
    public void draw(){
        System.out.println("Drawing Square");
    }
    @Override
    public void erase(){
        System.out.println("Erasing Square");
    }
}


//Main.java
public class Main{
    public static void main(String[] args){
        Shape s1 = new Circle();
        Shape s2 = new Triangle();
        Shape s3 = new Square();
        s1.draw();
        s1.erase();
        s2.draw();
        s2.erase();
        s3.draw();
        s3.erase();
    }
}
