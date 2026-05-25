#include <stdio.h>
#define MAX 50
int s[MAX], x[MAX], d,n;

void sumofsubsets(int p, int k, int r){
    if(k>n)
        return;
    x[k] = 1;
    if(p+s[k]==d){
        for(int i =1;i<=k;i++){
            if(x[i])
                printf(" %d ", s[i]);
        }
        printf("\n");
    }
    else if(k+1<=n && (p+s[k]+s[k+1]<=d)){
        sumofsubsets(p+s[k], k+1, r-s[k]);
    }
    if(k+1<=n && (p+r-s[k]>=d) && (p+s[k+1]<=d)){
        x[k] = 0;
        sumofsubsets(p,k+1,r-s[k]);
    }
}

void main(){
    int sum = 0;
    printf("Enter length of the array: ");
    scanf("%d", &n);
    printf("Enter the elements in ascending order: ");
    for(int i =1;i<=n;i++){
        scanf("%d", &s[i]);
        sum+=s[i];
    }
    printf("Enter the sum value: ");
    scanf("%d", &d);
    if(sum<d || s[1]>d)
        printf("No subsets possible.");
    else
        sumofsubsets(0,1,sum);
}
