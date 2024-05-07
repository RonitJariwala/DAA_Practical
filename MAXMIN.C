#include<stdio.h>
#include<conio.h>
int max,min,a[100];
void maxMin(int i,int j){
	int max1,min1,mid;
	if(i==j){
		max=min=a[i];
	}
	else if(i==j-1){
		if(a[i]<a[j]){
			max=a[j]; min=a[i];
		}
		else{
			max=a[i]; min=a[j];
		}
	}
	else{
		mid=(i+j)/2;
		maxMin(i,mid);
		max1=max; min1=min;
		maxMin(mid+1,j);
		if(max<max1){
			max=max1;
		}
		if(min>min1){
			min=min1;
		}
	}
}
void main(){
	int i,n;
	printf("\nEnter number of elements in array:");
	scanf("%d",&n);
	printf("Enter value:");
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	maxMin(0,n-1);
	printf("\nMaximum element is %d and minimum element is %d",max,min);
	getch();
}

