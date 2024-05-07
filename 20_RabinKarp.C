#include <stdio.h>
#include <string.h>
#define d 256
#define q 101

void rabinKarp(char *pattern, char *text) {
    int m,n,hashP=0,hashT=0,h=1,found=0,i,j;	
    m=strlen(pattern);
    n=strlen(text);
    for(i=0;i<m-1;i++)
        h=(h*d)%q;
    for(i=0;i<m;i++){
        hashP=(d * hashP + pattern[i])%q;
        hashT=(d * hashT + text[i])%q;
    }
    for(i=0;i<=n-m;i++) {
        if(hashP==hashT){
            for(j=0;j<m;j++){
                if(text[i+j]!=pattern[j])
                    break;
            }
            if(j==m){
                printf("Pattern found at index %d\n",i);
                found=1;
            }
        }
        if(i<n-m){
            hashT=(d*(hashT-text[i]*h)+text[i + m])%q;
            if(hashT<0)
                hashT+=q;
        }
    }
    if(!found)
        printf("Pattern not found in the text.\n");
}
void main(){
    char pattern[]="abc";
    char text[]="abcxyzabcdabxabcdabcy";
    rabinKarp(pattern,text);
}
