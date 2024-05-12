#include<stdio.h>
#include<conio.h>
int i,j,k,p,table[10][10],sol[10],minCount;


int min(int a,int b){
    return (a<b) ? a:b;
}

int minCoins(int coins[],int m,int v){
    table[m+1][v+1];
    for(i=0;i<=m;i++)
        table[i][0]=0;
    for(i=0;i<=v;i++)
        table[0][i]=i;
    for(i=1;i<=m;i++){
        for(j=1;j<=v;j++){
            if(coins[i-1]>j)
                table[i][j]=table[i-1][j];
            else
                table[i][j]=min(table[i-1][j],1+table[i][j-coins[i-1]]);
        }   
    }
    printf("Capacity/Coins\t\n");
    printf("\t\t");
    for(i=0;i<=v;i++){
        printf("%d\t",i);
    }
    printf("\n");
    for(i=1;i<=m;i++){
        printf("%d\t\t",coins[i-1]);
        for(j=0;j<=v;j++){
            printf("%d\t",table[i][j]);
        }
        printf("\n");
    }
    i=m;
    j=v;
    p=0;
    sol[m+1];
    while(j>0){
        if(table[i][j]==table[i-1][j])
            i=i-1;
        else{
            j=j-coins[i-1];
            sol[p]=coins[i-1];
            p++;
        }
    }
    printf("coins used:");
    for(k=0;k<p;k++){
        printf("%d",sol[k]);
    }
    printf("\n");
    return table[m][v];
}
void main(){
    int coins[100],m,v;
    printf("Enter the number of coins:");
    scanf("%d",&m);
    printf("Enter coins:");
    for(i=0;i<m;i++){
        scanf("%d",&coins[i]);
    }
    printf("Enter total amount:");
    scanf("%d",&v);
    minCount=minCoins(coins,m,v);
    printf("Minimum number of coins are required: %d\n",minCount);
    getch();
}
