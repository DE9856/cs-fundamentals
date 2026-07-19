#include <stdio.h>
#define MAX 100

typedef struct{
    int no;
    float weight,profit,ratio;
} item;

item a[MAX];
int n;
float capacity;

void bubblesort(){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(a[j].ratio<a[j+1].ratio){
                item temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

void discrete(){
    float total=0;
    float rem = capacity;
    int x[MAX] = {0};
    for(int i=0;i<n;i++){
        if(rem>=a[i].weight){
            rem-=a[i].weight;
            total+=a[i].profit;
            x[i] = 1;
        }
    }
    printf("Total profit in Discrete Knapsack: %f\n", total);
    printf("Solution Vector: \n");
    for(int i=0;i<n;i++)
        printf("Item %d: %d\n", a[i].no, x[i]);
}

void fractional(){
    float total =0 ;
    float rem = capacity;
    float x[MAX] = {0.0};
    for(int i=0;i<n;i++){
        if(rem>=a[i].weight){
            rem-=a[i].weight;
            total+=a[i].profit;
            x[i] = 1.0;
        }
        else{
            x[i] = rem/a[i].weight;
            total+=(rem/a[i].weight)*a[i].profit;
            break;
        }
    }
    printf("The total profit is: %f\n", total);
    printf("Solution Vector: \n");
    for(int i=0;i<n;i++)
        printf("Item %d: %f\n", a[i].no, x[i]);
}

void main(){
    printf("Enter the number of items: ");
    scanf("%d", &n);

    printf("Enter the profits: ");
    for(int i=0;i<n;i++)
        scanf("%f", &a[i].profit);

    printf("Enter the weights: ");
    for(int i=0;i<n;i++)
        scanf("%f", &a[i].weight);

    for(int i=0;i<n;i++){
        a[i].no=i+1;
        a[i].ratio = a[i].profit/a[i].weight;
    }

    printf("Enter the max capacity: ");
    scanf("%f", &capacity);

    bubblesort();
    discrete();
    fractional();
}
