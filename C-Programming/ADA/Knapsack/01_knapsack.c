#include <stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))

int profit[20], weight[20], dp[20][20];
int n,m;

void kp(){
    for(int i=0;i<=n;i++){
        for(int w = 0;w<=m;w++){
            if(i==0 || w==0)
                dp[i][w] = 0;
            else if(weight[i-1]<=w)
                dp[i][w] = max(dp[i-1][w], profit[i-1]+dp[i-1][w-weight[i-1]]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }
    printf("The max profit is: %d\nSolution: ",dp[n][m]);
    int r = dp[n][m];
    int w = m;
    int x[20] = {0};
    for(int i = n; i>0 && r>0 ;i--){
        if(r!=dp[i-1][w]){
            x[i-1] = 1;
            r-=profit[i-1];
            w-=weight[i-1];
        }
    }
    for(int i = 0;i<n;i++)
        printf(" %d ", x[i]);
}

void main(){
    printf("Enter the number of objects: ");
    scanf("%d", &n);
    printf("Enter the profits: ");
    for(int i =0;i<n;i++)
        scanf("%d", &profit[i]);
    printf("Enter the weights: ");
    for(int i = 0;i<n;i++)
        scanf("%d", &weight[i]);
    printf("Enter the capacity: ");
    scanf("%d", &m);
    kp();
}
