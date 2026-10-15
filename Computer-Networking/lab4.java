//NAME THE FILE IN YOUR COMPUTER AS CRC.java
/*TO EXECUTE
Run command: javac filename.java
Run command: java classname
  */

import java.util.*;

public class CRC {
  static int[] divide(int[] a, int[] d){
    int[] r = new int[a.length];
    for(int i=0;i<a.length;i++)
      r[i] = a[i];
    for(int i=0;i+d.length <= r.length; i++){
      if(r[i]==1)
        for(int j=0;j<d.length;j++)
          r[i+j] ^= d[j];
    }
    return r;
  }
  
  static int[] read(Scanner sc, int n){
    int[] a = new int[n];
    for(int i=0;i<n;i++)
      a[i] = sc.nextInt();
    return a;
  }
  
  static void print(int[] a){
    for(int i=0;i<a.length;i++)
      System.out.print(a[i]+" ");
    System.out.println();
  }
  
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    
    System.out.println("Enter number of data bits and the data bits: ");
    int[] data = read(sc, sc.nextInt());
    
    System.out.println("Enter number of divisor bits and the divisor bits: ");
    int[] div = read(sc, sc.nextInt());
    
    int n= data.length + div.length -1;
    int[] code = new int[n];
    
    for(int i=0;i<data.length;i++)
      code[i] = data[i];
    System.out.println("Dividend after appending 0's: ");
    print(code);
    
    int[] rem = divide(code, div);
    for(int i=data.length;i<n;i++)
      code[i] = rem[i];
    System.out.println("CRC Code: ");
    print(code);
    
    System.out.println("Enter recieved code of "+n+" bits");
    rem = divide(read(sc,n),div);
    boolean error = false;
    for(int i=0;i<n;i++)
      if(rem[i]!=0)
        error = true;
      System.out.println(error?"Error":"No Error");
      System.out.println("Thank you");
  }
}




//OR



import java.io.*;
import java.math.*;
class CRC{
    public static void main(String args[]) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] data;
        int[] div;
        int[] divisor;
        int[] rem;
        int[] crc;
        int data_bits, divisor_bits, tot_length;
        System.out.println("Enter number of data bit: ");
        data_bits = Integer.parseInt(br.readLine());
        data = new int[data_bits];
        System.out.println("Enter data bits: ");
        for(int i=0;i<data_bits;i++)
            data[i] = Integer.parseInt(br.readLine());
        System.out.println("Enter number of bits in divisor: ");
        divisor_bits = Integer.parseInt(br.readLine());
        divisor = new int[divisor_bits];
        System.out.println("Enter divisor bits: ");
        for(int i=0;i<divisor_bits;i++)
            divisor[i] = Integer.parseInt(br.readLine());
        tot_length = data_bits + divisor_bits - 1;
        div = new int[tot_length];
        rem = new int[tot_length];
        crc = new int[tot_length];
        
        for(int i=0;i<data.length;i++)
            div[i] = data[i];
        System.out.println("Dividend (After appending 0's) are: ");
        for(int i=0;i<div.length;i++)
            System.out.println(div[i]);
        System.out.println();
        for(int j=0;j<div.length;j++)
            rem[j] = div[j];
        rem = divide(div, divisor, rem);
        for(int i=0;i<div.length;i++)
            crc[i] = (div[i]^rem[i]);
        System.out.println("\nCRC code: ");
        for(int i=0;i<crc.length;i++)
            System.out.println(crc[i]);
        System.out.println("\nEnter CRC code of "+tot_length+" bits: ");
        for(int i=0;i<crc.length;i++)
            crc[i] = Integer.parseInt(br.readLine());
        for(int j=0;j<crc.length;j++)
            rem[j] = crc[j];
        rem = divide(crc, divisor, rem);
        for(int i=0;i<rem.length;i++){
            if(rem[i]!=0){
                System.out.println("Error");
                break;
            }
            if(i==rem.length-1)
                System.out.println("No Error");
        }
        System.out.println("THANK YOU....:)");
    }
    static int[] divide(int div[], int divisor[], int rem[]){
        int cur =0;
        while(true){
            for(int i=0;i<divisor.length;i++)
                rem[cur+i] = (rem[cur+i]^divisor[i]);
            while(rem[cur]==0 && cur!=rem.length-1)
                cur++;
            if((rem.length-cur)<divisor.length) 
                break;
            }
        return rem;
    }
}




/*TO EXECUTE
Run command: javac filename.java
Run command: java classname
  */
