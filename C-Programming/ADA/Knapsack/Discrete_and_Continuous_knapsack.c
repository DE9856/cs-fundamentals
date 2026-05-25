#include <stdio.h>
#define MAX 50

typedef struct{
    int profit, weight, index;
    double ratio;
} item;

void greedy(item items[], int n, int m){
    for(int i =0;i<n-1;i++)
        for(int j = i+1;j<n;j++)
            if(items[i].ratio< items[j].ratio){
                item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
    int cw = 0;
    double mp = 0.0, x[MAX] = {0.0};
    for(int i =0;i<n;i++){
        if(cw+items[i].weight<=m){
            x[items[i].index] = 1.0;
            mp+=items[i].profit;
            cw += items[i].weight;
        }
        else{
            x[items[i].index] = (m-cw)/(double)items[i].weight;
            mp+=x[items[i].index]*items[i].profit;
            break;
        }
    }
    printf("Optimal Solution: %.2lf", mp);
    printf("\nSolution Vector: ");
    for(int i =0 ;i<n;i++)
        printf("%.2lf ", x[i]);
}

void main(){
    int n,m;
    item items[MAX];
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the profits: ");
    for(int i =0 ;i<n;i++){
        scanf("%d", &items[i].profit);
    }
    printf("Enter the weights: ");
    for(int i =0;i<n;i++){
        scanf("%d", &items[i].weight);
        items[i].ratio = items[i].profit/items[i].weight;
        items[i].index = i;
    }
    printf("Enter max capacity: ");
    scanf("%d", &m);
    greedy(items,n,m);
}
