#include<stdio.h>
int i,w,k[10][10],w;

int max(int i,int j){
    if(i>j)
        return i;
    else
        return j;
}
int knapsack(int n,int m,int p[],int wt[]){
    k[n+1][m+1];
    for(i=0;i<=n;i++){
        for(w=0;w<=m;w++){
            if(i==0 || w==0)
                k[i][w]=0;
            else if(wt[i]<=w)
                k[i][w]=max(k[i-1][w],p[i]+k[i-1][w-wt[i]]);
            else
                k[i][w]=k[i-1][w];
        }
    }
    return k[n][m];
}
void main(){
    int n,profit[10],weight[10],capacity,maxP;
    printf("Enter number of items:");
    scanf("%d",&n);
    printf("Enter profits and weights of each items:");
    for(i=1;i<=n;i++){
        scanf("%d%d",&profit[i],&weight[i]);
    }
    printf("Enter capacity of knapsack");
    scanf("%d",&capacity);
    maxP=knapsack(n,capacity,profit,weight);
    printf("\nMax Profit is: %d\n",maxP);
}