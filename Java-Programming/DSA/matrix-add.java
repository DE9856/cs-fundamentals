import java.util.*;
public class MatrixAdd{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        if(args.length==0){
            System.out.println("Please enter an argument");
            return;
        }
        int n = Integer.parseInt(args[0]);
        if(n>5||n<0){
            System.out.println("Enter a positive number less than 5 as argument");
            return;
        }
        int a[][] = new int[n][n];
        int b[][] = new int[n][n];
        int c[][] = new int[n][n];
      
        System.out.println("Enter values in Matrix A: ");
        for(int i =0;i<n;i++)
            for(int j = 0;j<n;j++)
                a[i][j] = sc.nextInt();
      
        System.out.println("Enter values in Matrix B: ");
        for(int i=0;i<n;i++)
            for(int j =0;j<n;j++)
                b[i][j] = sc.nextInt();
      
        for(int i =0;i<n;i++)
            for(int j = 0;j<n;j++)
                c[i][j] = a[i][j] + b[i][j];
      
        System.out.println("Matrix A: ");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                System.out.print(a[i][j]+"\t");
            System.out.println();
        }
      
        System.out.println("Matrix B: ");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                System.out.print(b[i][j]+"\t");
            System.out.println();
        }
      
        System.out.println("Matrix C: ");
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
                System.out.print(c[i][j]+"\t");
            System.out.println();
        }
    }
}
