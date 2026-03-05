//Runnable Implementation
public class MyRunnable implements Runnable{
    private String threadstring;
    public MyRunnable(String str){
        this.threadstring = str;
    }
    public void run(){
        try{
            for(int i=0;i<3;i++){
                System.out.println(threadstring+" is running");
                Thread.sleep(500);
            }
        }
        catch(InterruptedException e){
            System.out.println(threadstring+" was interrupted");
        }
        System.out.println(threadstring+" is done");
    }
}

//Main.java
import java.util.Scanner;
public class RunnableDemo{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of threads: ");
        int n = sc.nextInt();
        Thread[] threads = new Thread[n];
        for(int i=0;i<n;i++){
            threads[i] = new Thread(new MyRunnable("String "+(i+1)));
            threads[i].start();
        }
        sc.close();
    }
}
