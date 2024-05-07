#include<stdio.h>
#include<conio.h>
#define M 100
void mergeSort(int a[],int lb,int ub);
void merge(int a[],int lb,int mid,int ub);
void main(){
	int i,n,a[M];
	clrscr();
	printf("\nRonit Jariwala S050");
	printf("\nEnter number of elements in array:");
	scanf("%d",&n);
	printf("Enter value:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nElements before sorting:");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	mergeSort(a,0,n-1);
	printf("\nElements after sorting:");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	getch();
}
void mergeSort(int a[],int lb,int ub){
	int mid;
	if(lb<ub){
		mid=(lb+ub)/2;
		mergeSort(a,lb,mid);
		mergeSort(a,mid+1,ub);
		merge(a,lb,mid,ub);
	}
}
void merge(int a[],int lb,int mid,int ub){
	int i=lb,j=mid+1,k=lb,b[M];
	while(i<=mid && j<=ub){
		if(a[i]<=a[j]){
			b[k]=a[i];
			i++;
		}else{
			b[k]=a[j];
			j++;
		}k++;
	}
	if(i>mid){
		while(j<=ub){
			b[k]=a[j];
			j++; k++;
		}
	}else{
		while(i<=mid){
			b[k]=a[i];
			k++; i++;
		}
	}
	//copying sorted array from b[] into a[]
	for(i=lb;i<=ub;i++){
		a[i]=b[i];
	}
}
