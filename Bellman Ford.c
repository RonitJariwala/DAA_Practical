#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

#define MAX_VERTICES 100

int d[MAX_VERTICES], graph[MAX_VERTICES][MAX_VERTICES],i,j,u,v,V,src = 0;

// Bellman-Ford algorithm to store adjacency matrix
void bellmanFord(int graph[MAX_VERTICES][MAX_VERTICES], int V, int src) {
    // Initialize distances from src to all other vertices as INFINITY
    for(i = 0; i < V; i++) {
        d[i] = INT_MAX;
    }
    d[src] = 0;

    // Relax all edges V-1 times
    for(i = 0; i < V-1; i++) {
        for(u = 0; u < V; u++) {
            for(v = 0; v < V; v++) {
                if(graph[u][v] != 0 && d[u] != INT_MAX && d[u] + graph[u][v] < d[v]) {
                    d[v] = graph[u][v] + d[u];
                }
            }
        }
    }

    // Check for negative weight
    for(u = 0; u < V; u++) {
        for(v = 0; v < V; v++) {
            if(graph[u][v] != 0 && d[u] != INT_MAX && d[u] + graph[u][v] < d[v]) {
                printf("Graph contains negative weight\n");
                return;
            }
        }
    }

    printf("Vertex distances from source:\n");
    for(i = 0; i < V; i++) {
        printf("%d \t\t %d\n", i, d[i]);
    }
}

int main() {
    printf("Enter number of vertices: ");
    scanf("%d", &V);
    printf("Enter the adjacency matrix:\n");
    for(i = 0; i < V; i++) {
        for(j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    bellmanFord(graph, V, src);
    return 0;
}
