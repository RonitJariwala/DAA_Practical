#include<stdio.h>
#include<string.h>
#include<conio.h>

void KMP_prefix(char* P,int m,int* pi){
    int i=1,j=0;
    pi[0]=-1;

    while(i<m){
        while(j>=0 && P[i]!=P[j]){
            j=pi[j];
        }
        i++; j++;
        pi[i]=j;
    }
}

void KMP_match(char* P,char* T,int m,int n,int* pi){
    int i=0,j=0;
    while (i<n){
        while (j>=0 && T[i]!=P[j]){
            j=pi[j];
        }
        i++; j++;
        if (j==m){
            printf("Pattern found at index %d\n",i-j);
            j=pi[j];
        }
    }
    if(j==m){
        printf("Pattern found at index %d\n",i - j);
    }else{
        printf("Pattern not found in text/Pattern Ended\n");
    }
}

void main(){
    int m,n,pi[100];
    char text[]="RONIT";
    char pattern[]="T";    clrscr();
    m=strlen(pattern);
    n=strlen(text);
    pi[m + 1];

    KMP_prefix(pattern,m,pi);
    KMP_match(pattern,text,m,n,pi);
    getch();
}
