//Write a program to print all marks stored in the HashMap.

import java.util.*;
public class test9{
    public static void main(String args[]){
        HashMap <String, Integer> map = new HashMap <String, Integer>();
        map.put("Deepesh",100);
        map.put("Deepesh1",99);
        map.put("Deepesh2",98);
        for(int n : map.values())
            System.out.print(n+"\t");
    }
}
