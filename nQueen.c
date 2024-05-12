#include<stdio.h> 
#include<math.h> 
#include<conio.h>
int x[20],c=0;

int place(int k,int i){
    int j;
    for(j=1;j<=k-1;j++){
        if((x[j]==i) || abs(x[j]-i)==abs(j-k))
            return 0; 
    }
    return 1; 
}

void print(int n) {
    int i,j;
    printf("\n");
    for(i=1;i<=n;++i) {
        printf("\t%d",i); 
    }
    printf("\n");
    for(i=1;i<=n;i++){
        printf("%d",i);
        for(j=1; j<=n; ++j){
            if(x[j]==i)
                printf("\tQ"); 
            else
                printf("\t*");
        }
        printf("\n");
    }
}

void nqueen(int k,int n){
    int i,j;
    for(i=1;i<=n;i++){
        if(place(k,i)==1){ 
            x[k]=i; 
            if(k==n){ 
                c++;
                printf("\nSolution %d\n",c);
                print(n);
            }
            else{ 
                nqueen(k+1,n);
            }
        }
    }
}

void main(){
    int k=1,n; 
    printf("Enter number of queens:"); 
    scanf("%d",&n); 
    nqueen(k,n); 
    getch();
}
