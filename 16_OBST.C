#include <stdio.h>
#include <limits.h>
#define MAX_NODES 100

void optimalBST(float p[], int n){
    int i,j,k,length;
    float C[MAX_NODES][MAX_NODES],sum[MAX_NODES+1],cost;
    sum[0]=0;
    for(i=1;i<=n;i++){
        C[i][i]=p[i];
        sum[i]=sum[i-1]+p[i];
    }
    for(length=2;length<=n;length++) {
        for(i=1;i<=n-length+1;i++) {
            j=i+length-1;
            C[i][j]=INT_MAX;
            for (k=i;k<=j;k++){
                cost=C[i][k - 1]+C[k + 1][j]+sum[j]-sum[i - 1];
                if(cost<C[i][j]){
                    C[i][j]=cost;
                }
            }
        }
    }
    printf("Optimal BST cost: %.2f\n",C[1][n]);
}
int main(){
    int n,i;
    float p[MAX_NODES];
    printf("Enter the number of nodes: ");
    scanf("%d",&n);
    printf("Enter the probabilities for each node:\n");
    for (i=1;i<=n;i++){
        scanf("%f",&p[i]);
    }
    optimalBST(p,n);
    return 0;
}
