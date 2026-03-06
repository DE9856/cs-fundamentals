//Create an ArrayList of 5 names. Print all names using a for-each loop.
import java.util.*;
public class test16{
    public static void main(String args[]){
        ArrayList <String> list = new ArrayList <String>();
        list.add("Deepesh");
        list.add("Deepesh1");
        list.add("Deepesh2");
        list.add("Deepesh3");
        list.add("Deepesh4");
        for(String name: list) 
            System.out.println(name);
    }
}
