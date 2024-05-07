// Online C compiler to run C program online
#include <stdio.h>
#include<stdlib.h>

void main(){
    int cost[10][10],visited[10]={0},i,j,n,no_e=1,min,a,b,min_cost=0;
    printf("**Prims Algortihm***\n");
    printf("Enter number of nodes:");
    scanf("%d",&n);
    printf("Enter cost adjaceny matrix:");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&cost[i][j]);
            if(cost[i][j]==0)   cost[i][j]=1000;
        }
    }
    visited[1]=1;
    while(no_e<n){
        min=1000;
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(cost[i][j]<min){
                    min=cost[i][j];
                    a=i; b=j;
                }
            }
        }
        if(visited[b]==0){
            printf("\n=>%d to %d cost = %d",a,b,min);
            min_cost += min;
            no_e++;
        }
        visited[b]=1;
        cost[a][b]=cost[b][a]=1000;
    }
    printf("\nTotal cost of Spanning Tree: %d",min_cost);
}