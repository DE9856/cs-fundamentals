//Outer.java
public class Outer{
    String msg = "This is outer String";
    void display(){
        System.out.println(msg);
    }
    public class Inner{
        String msg = "This is Inner String";
        void display(){
            System.out.println(msg);
        }
    }
    void show(){
        Inner i1 = new Inner();
        i1.display();        
    }
}

//Main.java
public class Main3{
    public static void main(){
        Outer o1 = new Outer();
        o1.display();
        o1.show();
    }
}

