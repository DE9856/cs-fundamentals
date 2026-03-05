//Custom Exception
public class DivisionByZeroException extends Exception{
    DivisionByZeroException(String message){
        super(message);
    }
}

//Main.java
import java.util.Scanner;
public class CustomExceptionDemo{
    public static double divide(int a, int b) throws DivisionByZeroException{
        if(b==0)
            throw new DivisionByZeroException("Cannot Divide By 0");
        return a/b;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        try{
            System.out.println("Enter a,b values: ");
            int a = sc.nextInt();
            int b = sc.nextInt();
            System.out.println("The answer is: "+divide(a,b));
        }
        catch(DivisionByZeroException e){
            System.err.println("Exception: "+e.getMessage());
        }
        finally{
            System.out.println("Program is Completed");
            sc.close();
        }
    }
}
