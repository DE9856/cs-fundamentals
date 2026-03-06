//Create a program to store student names and their marks in a HashMap and display all the entries.
import java.util.*;
public class test1{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        HashMap <String, Integer> map = new HashMap<String, Integer>();
        System.out.println("Enter the no. of students: ");
        int n = sc.nextInt();
        for(int i=0;i<n;i++){
            System.out.println("Enter name: ");
            String name = sc.next();
            System.out.println("Enter marks: ");
            int marks = sc.nextInt();
            map.put(name, marks);
        }
        for(Map.Entry <String, Integer> entry : map.entrySet()){
            System.out.println(entry.getKey() + " : "+entry.getValue());
        }
    }
}
