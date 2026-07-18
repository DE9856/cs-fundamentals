#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define INF 999

int cost[MAX][MAX], parent[MAX];

int find(int i){
    while(parent[i]!=i)
        i = parent[i];
    return i;
}

int uni(int i, int j){
    if(i!=j){
        parent[j] = i;
        return 1;
    }
    return 0;
}

int main(){
    int i,j,a,b,u,v,min,mincost=0,n,ne=1;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    for(int i=0;i<n;i++)
        parent[i]=i;

    printf("Enter the cost adjacency matrix: ");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d", &cost[i][j]);
            if(cost[i][j]==0)
                cost[i][j]=INF;
        }
    }

    while(ne<n){
        min = INF;
        for(i=0;i<n;i++){
            
            for(j=0;j<n;j++){
                if(i!=j && cost[i][j]<min){
                    min = cost[i][j];
                    a=u = i;
                    b=v = j;
                }
            }
        }
        u = find(u);
        v = find(v);
        if(uni(u,v)){
            printf("Edge %d: %d -> %d = %d\n",ne++,a,b,min);
            mincost+=min;
        }
        cost[a][b] = cost[b][a] = INF;

    }

    printf("The minimum cost is: %d", mincost);
}



\\OR

#include <stdio.h>
#include <stdlib.h>
#define MAX 100

typedef struct {
	int u, v, weight;
} edge;

typedef struct{
	int parent;
	int rank;
} subset;

int find(subset subsets[], int i){
	if (subsets[i].parent != i)
		subsets[i].parent = find(subsets, subsets[i].parent);
	return subsets[i].parent;
}

void unionsort(subset subsets[], int x, int y){
	int rootX = find(subsets, x);
	int rootY = find(subsets, y);
	if (subsets[rootX].rank < subsets[rootY].rank)
		subsets[rootX].parent = rootY;
	else if (subsets[rootX].rank > subsets[rootY].rank)
		subsets[rootY].parent = rootX;
	else {
		subsets[rootY].parent = rootX;
		subsets[rootX].rank++;
	}
}

int compare(const void *a, const void *b){
	return ((edge *)a)->weight - ((edge *)b)->weight;
}

void kruskal(edge edges[], int V, int E){
	edge result[V];
	int e = 0, i = 0;
	qsort(edges, E, sizeof(edge), compare);
	subset subsets[V];
	for (int v = 0; v < V; v++) {
		subsets[v].parent = v;
		subsets[v].rank = 0;
	}
	while (e < V - 1 && i < E) {
		edge next = edges[i++];
		int x = find(subsets, next.u);
		int y = find(subsets, next.v);
		if (x != y) {
			result[e++] = next;
			unionsort(subsets, x, y);
		}
	}
	printf("Minimum Spanning Tree: \n");
	int total = 0;
	for (i = 0; i < e; i++) {
		printf("%d -- %d == %d\n", result[i].u+1, result[i].v+1, result[i].weight);
		total += result[i].weight;
	}
	printf("Total Cost: %d\n", total);
}


int main(){
	int V;
	int graph[MAX][MAX];
	printf("Enter the number of vertices: ");
	scanf("%d", &V);
	printf("Enter the adjacency matrix: ");
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			scanf("%d", &graph[i][j]);
		}
	}
	edge edges[MAX * MAX];
	int E = 0;
	for (int i = 0; i < V; i++) {
		for (int j = i + 1; j < V; j++) {
			if (graph[i][j] != 0) {
				edges[E].u = i;
				edges[E].v = j;
				edges[E].weight = graph[i][j];
				E++;
			}
		}
	}
	kruskal(edges, V, E);
	return 0;
}
