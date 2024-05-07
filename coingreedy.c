#include <stdio.h>
#include <stdlib.h>

int denomination[]={1,2,5,10,20,50,100,500,1000};
int n=sizeof(denomination)/sizeof(denomination[0]);

int compare(const void *a, const void *b) {
    return (*(int *)b -*(int *)a);
}

void findMin(int V){
    qsort(denomination,n,sizeof(int),compare); 
    int ans[100],ans_index=0,i;
    for(i=0;i<n;i++){
        while(V>=denomination[i]){
            V-=denomination[i];
            ans[ans_index++]=denomination[i];
        }
    }
    for(i=0;i<ans_index;i++){
        printf("%d ",ans[i]);
    }
}

void main(){
    int n=93;
    printf("Following is minimal number of change for %d: ",n);
    findMin(n);
}