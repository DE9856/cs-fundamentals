#include <stdio.h>
#include <stdlib.h>
#define MAX 100

int s[MAX],x[MAX],n,d;

void sumofsubset(int p, int k, int r){
    if(k>n)
        return;
    x[k]=1;
    if(p+s[k]==d){
        for(int i=1;i<=n;i++){
            if(x[i])
                printf(" %d ", s[i]);    
        }
        printf("\n");
        x[k]=0;
    }
    else if(k+1<=n && p+s[k]+s[k+1]<=d){
        sumofsubset(p+s[k], k+1, r-s[k]);
    }
    x[k] = 0;
    if(k+1<=n && (p+r-s[k]>=d) && (p+s[k+1]<=d)){
        sumofsubset(p,k+1,r-s[k]);
    }
}

void main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int sum=0;
    printf("Enter the elements: ");
    for(int i=1;i<=n;i++){
        scanf("%d", &s[i]);
        sum+=s[i];
    }
    printf("Enter the target sum: ");
    scanf("%d", &d);
    if(sum<d || s[1]>d)
        printf("No subsets available");
    else
        sumofsubset(0,1,sum);
}
