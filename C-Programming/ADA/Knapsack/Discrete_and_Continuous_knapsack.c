#include <stdio.h>

#define MAX 50

typedef struct{
    int profit, weight;
    double ratio;
    int index;
} item;

void greedy(item items[], int n, int m){
    int i, j;

    for(i = 0; i < n - 1; i++){
        for(j = i + 1; j < n; j++){
            if(items[i].ratio < items[j].ratio){
                item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }

    int currentweight = 0;
    double maxprofit = 0.0;
    double x[MAX] = {0.0};

    for(i = 0; i < n; i++){
        if(currentweight + items[i].weight <= m){
            x[items[i].index] = 1.0;
            maxprofit += items[i].profit;
            currentweight += items[i].weight;
        }
        else{
            x[items[i].index] =
            (m - currentweight) / (double)items[i].weight;

            maxprofit +=
            x[items[i].index] * items[i].profit;

            break;
        }
    }

    printf("\nOptimal Solution: %lf", maxprofit);

    printf("\nSolution Vector: ");

    for(i = 0; i < n; i++)
        printf(" %lf ", x[i]);

    printf("\n");
}

int main(){
    int n, m, i;

    printf("Enter the number of objects: ");
    scanf("%d", &n);

    item items[n];

    printf("Enter the profits: ");

    for(i = 0; i < n; i++){
        scanf("%d", &items[i].profit);
    }

    printf("Enter weights: ");

    for(i = 0; i < n; i++){
        scanf("%d", &items[i].weight);

        items[i].ratio =
        (double)items[i].profit / items[i].weight;

        items[i].index = i;
    }

    printf("Enter the max capacity: ");
    scanf("%d", &m);

    greedy(items, n, m);

    return 0;
}
