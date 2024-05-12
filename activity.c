#include<stdio.h>
#include<conio.h>
void activitySelection(int s[],int f[],int n){
    int i=0,j;
    printf("Selected activities:\n");
    printf("A[%d] ",i+1);
    for(j=1;j<n;j++){
        if(s[j]>=f[i]){
            printf("A[%d] ",j+1);
            i=j;
        }
    }
}
void main(){
    int i,n,s[10],f[10];
    printf("Enter number of activities:");
    scanf("%d",&n);
    printf("Enter start time:\n");
    for(i=0;i<n;i++){
        printf("Start time for activty A[%d]: ",i+1);
        scanf("%d",&s[i]);
    }
    printf("Enter finish time:\n");
    for(i=0;i<n;i++){
        printf("Finish time for activity A[%d]: ",i+1);
        scanf("%d",&f[i]);
    }
    activitySelection(s,f,n);
    getch();
}    
