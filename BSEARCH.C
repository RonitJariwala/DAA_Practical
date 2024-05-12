#include<stdio.h>
#include<conio.h>
int binarySearch(int a[],int low,int high,int data);
void main(){
	int a[100],i,n,result,key;
	clrscr();
	printf("\nRonit Jariwala S050");
	printf("\nBinary Search");
	printf("\nEnter number of elements in an array:");
	scanf("%d",&n);
	printf("Enter value:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	printf("\nEnter element to search for:");
	scanf("%d",&key);
	result=binarySearch(a,0,n-1,key);
	if(result==-1) printf("\nElement not found");
	else printf("\nElement found at %d index",result);
	getch();
}
int binarySearch(int a[],int low,int high,int data){
	int mid;
	if(low<=high){
		mid=low+(high-low)/2;
		if(a[mid]==data)
			return mid;
		else if(a[mid]<data)
			return binarySearch(a,mid+1,high,data);
		else
			return binarySearch(a,low,mid-1,data);
	}
	return -1;
}










