import java.util.*;
public class Employee{
    private int id;
    private String name;
    private double salary;
  
    Employee(int id, String name, double salary){
        this.id = id;
        this.name = name;
        this.salary = salary;
    }
  
    public void raiseSalary(double percent){
        if(percent<0){
            System.out.println("Enter a positive hike value");
            return;
        }
        else{
            this.salary = this.salary + (this.salary*percent)/100;
        }
    }
  
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter ID, Name, and Salary");
        int id = sc.nextInt();
        String name = sc.next();
        double salary = sc.nextDouble();
        Employee e1 = new Employee(id, name, salary);
        System.out.println("Enter Salary Hike Percentage: ");
        double percent = sc.nextDouble();
        e1.raiseSalary(percent);
        System.out.println("Salary After hike: "+e1.salary);
        sc.close();
    }
}
