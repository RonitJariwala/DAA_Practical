#include<conio.h>
#include <stdio.h>
#include<limits.h>

int matrixChain(int p[],int n){
    int m[n][n],i,j,k,q,d;
    for(i=1;i<n;i++)
        m[i][i]=0;
    // D is chain length
    for(d=1;d<n-1;d++){
        for(i=1;i<n-d;i++){
            j=i+d;
            m[i][j]=INT_MAX;
            for(k=i;k<j;k++){
                q = m[i][k] + m[k+1][j] + p[i-1] * p[k] * p[j];  
                if(q<m[i][j])
                    m[i][j]=q;
            }
        }
    }
    return m[1][n-1];
}
void main(){
    int i,n,a[10];
    printf("Enter number of matrices:");
    scanf("%d",&n);
    printf("Enter dimensions of matrices:");
    for(i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    printf("Minimum number of multiplications needed to multiply the chain of matrices is %d\n", matrixChain(a,n));
    getch();
}
