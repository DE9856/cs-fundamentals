// Write a program to display the marks of a given student name from the HashMap.
import java.util.*;
public class test2{
    public static void main(String args[]){
        HashMap <String, Integer> map = new HashMap <String, Integer>();
        Scanner sc = new Scanner(System.in);
        map.put("Deepesh", 100);
        map.put("Deepesh1", 99);
        map.put("Deepesh2",98);
        System.out.println("Enter key value: ");
        String str = sc.nextLine();
        if(map.containsKey(str))
            System.out.println("Marks: "+map.get(str));
        else
            System.out.println("Does not Exist");
    }
}
