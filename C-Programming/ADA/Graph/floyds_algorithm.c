#include <stdio.h>
#include <stdlib.h>
#define INF 999

void main(){
    int n,i,j,k;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the cost Adjacency matrix: ");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d", &a[i][j]);
            if(i!=j && a[i][j]==0)
                a[i][j] = INF;
        }
    }
    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(a[i][k]!=INF && a[k][j]!=INF && a[i][j]> a[i][k]+a[k][j])
                    a[i][j] = a[i][k]+a[k][j];
            }
        }
    }
    printf("The shortest path matrix is : \n");
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++)
            printf(" %d ", a[i][j]);
        printf("\n");
    }
}
