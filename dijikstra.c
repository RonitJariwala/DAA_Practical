#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX_VERTICES 100
int dist[MAX_VERTICES],prev[MAX_VERTICES],graph[MAX_VERTICES][MAX_VERTICES],Q[MAX_VERTICES],i,j,u,v,V,count,src;

int minDistance(int dist[],int Q[],int V){
    int minDist=INT_MAX,minIndex;
    for(i=0;i<V;i++){
        if(Q[i]==1 && dist[i]<minDist){
            minDist=dist[i];
            minIndex=i;
        }
    }
    return minIndex;
}

void dijikstra(int graph[MAX_VERTICES][MAX_VERTICES],int V,int src){
    for(i=0;i<V;i++){
        dist[i]=INT_MAX;
        prev[i]=-1;
        Q[i]=1;
    }
    dist[src]=0;
    for(count=0;count<V-1;count++){
        u=minDistance(dist,Q,V);
        Q[u]=0;
        for(v=0;v<V;v++){
            if(graph[u][v] && Q[v] && dist[u]!=INT_MAX && dist[u]+graph[u][v]<dist[v]){
                dist[v]=dist[u]+graph[u][v];
                prev[v]=u;
            }
        }
    }
    printf("Vertex\tDistance from source\n");
    for(i=0;i<V;i++){
        printf("%d\t\t%d\n",i,dist[i]);
    }
}

void main(){
    printf("Enter number of vertices:");
    scanf("%d",&V);
    printf("Enter the adjacency matrix:\n");
    for(i=0;i<V;i++){
        for(j=0;j<V;j++){
            scanf("%d",&graph[i][j]);
        }
    }
    printf("Enter the source vertex:");
    scanf("%d",&src);
    dijikstra(graph,V,src);
}
