    import java.util.*;
    public class Stack{
        private int maxsize;
        private int[] stack;
        private int top;
      
        public Stack(int size){
            maxsize = size;
            stack = new int[maxsize];
            top = -1;
        }
      
        public boolean isFull(){
            return top==maxsize-1;
        }
      
        public boolean isEmpty(){
            return top==-1;
        }
      
        public void push(int val){
            if(isFull()){
                System.out.println("Stack Overflow");
                return;
            }
            stack[++top] = val;
            System.out.println(val+" has been pushed");
        }
      
        public void pop(){
            if(isEmpty()){
                System.out.println("Stack Underflow");
                return;
            }
            System.out.println(stack[top--]+"has been popped");
        }
      
        public void display(){
            if(isEmpty()){
                System.out.println("Stack is Empty");
                return;
            }
            System.out.println("Stack from top to bottom: ");
            for(int i = top;i>=0;i--)
                System.out.println(stack[i]);
        }
      
        public void peek(){
            if(isEmpty()){
                System.out.println("Stack is Empty");
                return;
            }
            System.out.println("Top Most Element in the stack is: "+stack[top]);
        }
      
        public static void main(String[] args){
            Scanner sc = new Scanner(System.in);
            System.out.println("Enter size of stack: ");
            int size = sc.nextInt();
            if(size>10 || size<0){
                System.out.println("Enter a positive value <=10");
                return;
            }
            Stack s = new Stack(size);
            System.out.println("STACK OPERATIONS MENU");
            System.out.println("1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT");
            while(true){
                System.out.println("Select Option: ");
                int choice = sc.nextInt();
                switch(choice){
                    case 1:
                        System.out.println("Enter value to push: ");
                        int val = sc.nextInt();
                        s.push(val);
                        break;
                    case 2:
                        s.pop();
                        break;
                    case 3:
                        s.display();
                        break;
                    case 4:
                        s.peek();
                        break;
                    case 5:
                        System.out.println("Exiting");
                        return;
                    default:
                        System.out.println("Enter a valid choice");
                }
            }
        }
    }
