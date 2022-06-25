#include<stdio.h>
void swap(float* a, float* b)
{
    float t = *a;
    *a = *b;
    *b = t;
}
void knapsack(int n,float weight[],float profit[],float capacity){
	int i,j;
	float x[10],totalprofit=0,cap;
	cap=capacity;
	for(i=0;i<n;i++)
		x[i]=0.0;
	for(i=0;i<n;i++){
		if(weight[i]>cap)
			break;
		else{
			x[i]=1.0;
			totalprofit+=profit[i];
			cap-=weight[i];
		}
	}
	if(i<n)
		x[i]=cap/weight[i];
	totalprofit+=x[i]*profit[i];
	printf("\nThe result vector:\t");
	for(i=0;i<n;i++){
		printf("%f\t", x[i]);
	}
	printf("\nMaximum profit is: %f", totalprofit);
}
int main(){
	float weight[10],profit[10],ratio[10],capacity;
	int n,i,j;
	printf("Enter no of items:\t");
	scanf("%d",&n);
	printf("Enter weight and profit:\n\tWeight\tProfit\n\t");
	for(i=0;i<n;i++){
		scanf("%f %f",&weight[i],&profit[i]);
		printf("\t");
	}
	printf("\nEnter Capacity of knapsack:\t");
	scanf("%f",&capacity);
	//ratio calculation
	for(i=0;i<n;i++)
		ratio[i]=profit[i]/weight[i];
	//sorting 
	for(i=0;i<n;i++)
		for(j=i+1;j<n;j++){
			if(ratio[i]<ratio[j]){
				swap(&ratio[i],&ratio[j]);
				swap(&weight[i],&weight[j]);
				swap(&profit[i],&profit[j]);
			}
		}
	knapsack(n,weight,profit,capacity);
}
