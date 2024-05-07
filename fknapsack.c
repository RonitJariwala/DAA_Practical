#include <stdio.h>
void knapsack(int n,float weight[],float profit[],float capacity){
    float a[20],tp=0;
    int i,j,m;
    m=capacity;  //capacity=15
    for(i=0;i<n;i++){
            a[i]=0.0;
    }
    for(i=0;i<n;i++){
            if(weight[i]>m) break;
            else{
                    a[i]=1.0;
                    tp=tp+profit[i];
                    m=m-weight[i];
            }
    }
    if(i<n)
        a[i]=m/weight[i];
    tp=tp+(a[i]*profit[i]);
    printf("\nThe resultant vector is:");
    for(i=0;i<n;i++){
        printf("%f\t",a[i]);
    }
    printf("\nMaximum profit is: %f",tp);
}
int main() {
    float weight[20],profit[20],ratio[20],temp,capacity;
    int n,i,j;
    printf("\nEnter number of objects: ");
    scanf("%d",&n);
    printf("\nEnter weight and profit of each object: ");
    for(i=0;i<n;i++){
            scanf("%f %f",&weight[i],&profit[i]);
    }
    printf("\nEnter capacity of knapsack:");
    scanf("%f",&capacity);
    for(i=0;i<n;i++){
            ratio[i]=profit[i]/weight[i];
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(ratio[j]<ratio[j+1]){
                temp=ratio[j];
                ratio[j]=ratio[j+1];
                ratio[j+1]=temp;
                
                temp=weight[j];
                weight[j]=weight[j+1];
                weight[j+1]=temp;
                
                temp=profit[j];
                profit[j]=profit[j+1];
                profit[j+1]=temp;
            }
        }
    }
    knapsack(n,weight,profit,capacity);
    return 0;
}