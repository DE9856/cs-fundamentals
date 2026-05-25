#include <stdio.h>
#include <stdlib.h>
#define INF 999

void prim(int adj[10][10], int n){
    int min;
    int u = 0, v=0;
    int cost = 0;
    int visited[10] = {0};
    visited[1]=1;

    while(1){
        min = INF;
        for(int i=1;i<=n;i++){
            if(visited[i]){
                for(int j=1;j<=n;j++){
                    if(!visited[j] && adj[i][j]<min){
                        min = adj[i][j];
                        u=i;
                        v=j;
                    }
                }
            }
        }
        if(min==INF)
            break;
        visited[v] = 1;
        printf("\nEdge: ( %d -> %d ): %d", u, v, min);
        cost+=min;
    }
    printf("\nThe minimum cost is: %d",cost);
}

void main(){
    int adj[10][10];
    int n;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: ");
    for(int i=1;i<=n;i++)
        for(int j = 1;j<=n;j++){
            scanf("%d", &adj[i][j]);
            if(i!=j && adj[i][j]==0)
                adj[i][j] = INF;
        }
    printf("Prim's Algorithm: ");
    prim(adj,n);
}
