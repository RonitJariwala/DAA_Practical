#include<stdio.h>
#include<conio.h>
int partition(int a[],int lb,int ub);
void quickSort(int a[],int lb,int ub);
void main(){
	int i,n,a[10],lb,ub;   clrscr();
	printf("\nRonit Jariwala S050");
	printf("\nEnter number of elements in array:");
	scanf("%d",&n);
	printf("Enter value:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nArray before sorting:");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	quickSort(a,0,n-1);
	printf("\nArray after sorting:");
	for(i=0;i<n;i++){
		printf("%d ",a[i]);
	}
	getch();
}
void quickSort(int a[],int lb,int ub){
	int loc;
	if(lb<ub){
		loc=partition(a,lb,ub);
		quickSort(a,lb,loc-1);
		quickSort(a,loc+1,ub);
	}
}
int partition(int a[],int lb,int ub){
	int pivot,start,end,temp;
	pivot=a[lb];
	start=lb;
	end=ub;
	while(start<end){
		while(a[start]<=pivot) start++;
		while(a[end]>pivot) end--;
		if(start<end){
			temp=a[start];
			a[start]=a[end];
			a[end]=temp;
		}
	}
	temp=a[lb];
	a[lb]=a[end];
	a[end]=temp;
	return end;
}
