#include <stdio.h>
#include <stdlib.h>
#define INF 999

int n,a[20][20], s[20],p[20],d[20];

void dijkstra(int src){
    for(int i =0;i<n;i++){
        s[i] = 0;
        d[i] = a[src][i];
        p[i] = src;
    }

    s[src] = 1;
    for(int i =0;i<n-1;i++){
        int min = INF;
        int u;
        for(int j = 0;j<n;j++){
            if(!s[j] && d[j]<min){
                min = d[j];
                u=j;
            }
        }
        s[u] = 1;
        for(int v = 0;v<n;v++){
            if(!s[v] && d[u]+a[u][v]<d[v]){
                d[v] = d[u]+a[u][v];
                p[v] = u;
            }
        }        
    }
}

void main(){
    int src;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the cost adjacency matrix: ");
    for(int i =0;i<n;i++){
        for(int j = 0;j<n;j++){
            scanf("%d", &a[i][j]);
            if(i!=j && a[i][j]==0)
                a[i][j] = INF;
        }   
    }
    printf("Enter source: ");
    scanf("%d", &src);
    dijkstra(src);
    printf("Shortest Path from source %d: \n", src);
    for(int i = 0;i<n;i++)
        printf("%d -> %d: %d\n", src,i,d[i]);
}
