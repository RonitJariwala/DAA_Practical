#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int coinChange(int coins[],int n,int amount){
    int need=0,i;
    for(i=0;i<n;i++){
        while(amount>=coins[i]){
            amount=amount-coins[i];
            need++;
        }
    }
    return need;
}

void main(){
    int amt,n,i,min,*coins;	clrscr();
    printf("Enter the number of coins:");
    scanf("%d",&n);
    *coins =(int*)malloc(n*sizeof(int));
    printf("Enter the denominations of coins separated by space:");
    for(i=0;i<n;i++){
        scanf("%d",&coins[i]);
    }
    printf("Enter the amount to make change for:");
    scanf("%d",&amt);
    min=coinChange(coins,n,amt);
    printf("Minimum number of coins required: %d\n",min);
    free(coins);
    getch();
}
