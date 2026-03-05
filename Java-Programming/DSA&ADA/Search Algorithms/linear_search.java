import java.util.*;
public class linear_search{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the no. of elements in the array: ");
        int n = sc.nextInt();
        int arr[] = new int[n];
        System.out.println("Enter the elements into the array: ");
        for(int i=0;i<n;i++)
            arr[i] = sc.nextInt();
            
        System.out.println("Enter the element to be searched: ");
        int key = sc.nextInt();
        int flag = 0;
        for(int i=0;i<=0;i++){
            if(key==arr[i]){
                System.out.println("Element is found in the array.");
                flag = 1;
            }
        }
        if(flag == 0)
            System.out.println("The element is not found in the array.");
    }
}
