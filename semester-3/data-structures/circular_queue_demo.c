#include <stdio.h>
#include <stdlib.h>
#define MAX 3
char queue[MAX];
int front = -1,rear=-1;
int isFull(){
    return(front==(rear+1)%MAX);
}
int isEmpty(){
    return front==-1;
}
void enqueue(){
    char x;
    if(isFull()){
        printf("Queue Overflow: ");
        return;
    }
    printf("Enter character to Enqueue: ");
    scanf(" %c",&x);
    if(isEmpty())
        front=rear=0;
    else
        rear = (rear+1)%MAX;
    queue[rear] = x;
    printf("Pushed %c",x);
}
void dequeue(){
    if(isEmpty()){
        printf("Queue Underflow");
        return;
    }
    printf("Deleted %c",queue[front]);
    if(front==rear)
        front = rear = -1;
    else
        front = (front+1)%MAX;
}
void peek() {
    if(isEmpty()) {
        printf("Queue is Empty\n");
        return;
    }
    printf("Front element: %c\n", queue[front]);
}
void display(){
    if(isEmpty()){
        printf("Queue is Empty");
        return;
    }
    printf("Queue Elements: ");
    int i = front;
    while(1){
        printf("%c\t",queue[i]);
        if(i==rear)
            break;
        else
            i = (i+1)%MAX;
    }
    printf("\n");
}
int main(){
    printf("QUEUE OPERATIONS");
    printf("1.ENQUEUE\n2.DEQUEUE\n3.PEEK\n4.DISPLAY\n5.EXIT");
    int choice;
    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3: peek();break;
            case 4: display();break;
            case 5: printf("Exiting");return 0;
            default:printf("Invalid Choice");
        }
    }
}
