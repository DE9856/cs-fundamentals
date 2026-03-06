//Write a program to find the total number of students stored in the HashMap.

import java.util.*;
public class test6{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        HashMap <String, Integer> map = new HashMap <String, Integer>();
        map.put("Deepesh", 100);
        map.put("Deepesh1", 99);
        map.put("Deepesh2",98);
        if(!map.isEmpty()){
            System.out.println(map.size());
        }
        else
            System.out.println("Map is empty");
    }
}
