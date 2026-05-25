#include <stdio.h>
#include <stdlib.h>
#define INF 999

void prim(int n,int a[n][n]){
    int min;
    int u = 0,v=0;
    int cost=0;
    int visited[n];
    for(int i =0;i<n;i++)
        visited[i] = 0; 
    visited[0] = 1;

    while(1){
        min = INF;
        for(int i =0;i<n;i++){
            if(visited[i]){
                for(int j = 0;j<n;j++){
                    if(!visited[j] && a[i][j]<min){
                        min = a[i][j];
                        u = i;
                        v = j;
                    }
                }
            }
        }
        if(min==INF)
            break;
        printf("\nEdge ( %d -> %d ): %d", u+1,v+1,min);
        cost+=min;
        visited[v] = 1;
    }
    printf("The total path cost: %d", cost);
}

void main(){
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    int a[n][n];
    printf("Enter the cost adjacency matrix: ");
    for(int i = 0;i<n;i++){
        for(int j =0;j<n;j++){
            scanf("%d", &a[i][j]);
            if(i!=j && a[i][j]==0)
                a[i][j] = INF;
        }
    }
    printf("Prim's Algorithm: ");
    prim(n,a);
}
