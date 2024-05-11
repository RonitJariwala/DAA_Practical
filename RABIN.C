#include<stdio.h>
#include<conio.h>
#include<string.h>
#define d 10
char st[100],pat[100];

void rabinKarp(char st[],char pat[],int q){
	int m,n,i,j,hashP=0,hashS=0,h=1,found=0;
	m=strlen(st);
	n=strlen(pat);
	for(i=0;i<n-1;i++)
		h=(h*d)%q;
	//calculate hash value for pattern and text
	for(i=0;i<n;i++){
		hashP=(hashP*d+pat[i])%q;
		hashS=(hashS*d+st[i])%q;
	}
	//find the match
	for(i=0;i<=m-n;i++){
		if(hashP==hashS){
			for(j=0;j<n;j++){
				if(st[i+j]!=pat[j])
					break;
			}
			if(j==n){
				printf("Pattern is found at position: %d\n",i);
				found=1;
			}
		}
		if(i<m-n){
			hashS=(d*(hashS-st[i]*h)+st[i+n])%q;
			if(hashS<0)	hashS=hashS+q;
		}
	}
	if(!found)  printf("\nPattern not found");
}


void main(){
	int q=13;
	printf("\nEnter the string:");
	scanf("%s",st);
	printf("\nEnter the pattern u are looking:");
	scanf("%s",pat);
	rabinKarp(st,pat,q);
	getch();
}

