#include <stdio.h>
#include <stdlib.h>

void main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int a[10][10];
    printf("Enter the path matrix: ");
    for(int i =0;i<n;i++)
        for(int j = 0;j<n;j++)
            scanf("%d", &a[i][j]);
    for(int k = 0;k<n;k++)
        for(int i = 0;i<n;i++)
            for(int j=0;j<n;j++)
                a[i][j] = a[i][j] || (a[i][k] && a[k][j]);   
    printf("\nTransitive Closure Matrix is: \n");
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++)
            printf(" %d ", a[i][j]);
        printf("\n");
    }
}
