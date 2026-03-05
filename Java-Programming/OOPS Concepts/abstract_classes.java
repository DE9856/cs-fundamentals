//Abstract Class Shape.java
public abstract class Shape1{
    abstract double calcArea();
    abstract double calcPerimeter();
}

//Circle.java
public class Circle1 extends Shape1{
    private int radius;
    public Circle1(int radius){
        this.radius = radius;
    }
    @Override
    public double calcPerimeter(){
        return Math.PI*2*this.radius;
    }
    @Override
    public double calcArea(){
        return Math.PI*this.radius*this.radius;
    }
}


//Triangle.java
public class Triangle1 extends Shape1{
    private int s1,s2,s3;
    public Triangle1(int s1, int s2, int s3){
        this.s1 = s1;
        this.s2 = s2;
        this.s3 = s3;
    }
    @Override
    public double calcPerimeter(){
        return s1+s2+s3;
    }
    @Override
    public double calcArea(){
        double s = this.calcPerimeter()/2;
        return Math.sqrt(s*(s-this.s1)*(s-this.s2)*(s-this.s3));
    }
}


//Main.java
import java.util.*;
public class Main1{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter radius of the Circle: ");
        int r = sc.nextInt();
        Circle1 c1 = new Circle1(r);
        System.out.println("Enter Sides of the Triangle: ");
        int s1 = sc.nextInt();
        int s2 = sc.nextInt();
        int s3 = sc.nextInt();
        Triangle1 t1 = new Triangle1(s1,s2,s3);
        System.out.println("Perimeter of Circle is: "+c1.calcPerimeter());
        System.out.println("Area of Circle is: "+c1.calcArea());
        System.out.println("Perimeter of triangle is: "+t1.calcPerimeter());
        System.out.println("Area of Triangle is: "+t1.calcArea());
    }
}
