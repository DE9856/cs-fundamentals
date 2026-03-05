//Interface Resizable.java
public interface Resizable{
    void resizeHeight(int height);
    void resizeWidth(int width);
}

//Rectangle.java
public class Rectangle implements Resizable{
    private int height,width;
    Rectangle(int height,int width){
        this.height = height;
        this.width = width;
    }
    void display(){
        System.out.println("Height: "+this.height+"\nWidth: "+this.width);
    }
    @Override
    public void resizeHeight(int height){
        this.height = height;
    }
    @Override
    public void resizeWidth(int width){
        this.width = width;
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
