#include<stdio.h>
int a[10],n,max,min;
void maxmin(int i,int j){
	int mid,max1,min1;
	if (i==j){
		max=min=a[i];
	}
	else if(i==j-1){
		if(a[i]>a[j]){
			max=a[i];
			min=a[j];
		}
		else{
			max=a[j];
			min=a[i];
		}
	}
	else{
		mid=(i+j)/2;
		maxmin(i,mid);
		max1=max;
		min1=min;
		maxmin(mid+1,j);
		if(max1>max)
			max=max1;
		if(min1<min)
			min=min1;
		
	}
}
int main(){
	int i;
	printf("Enter no of element: ");
	scanf("%d",&n);
	printf("Enter elements in array: ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	maxmin(0,n-1);
	printf("Maximum=%d\nMinimum=%d",max,min);
	
}
