#include<stdio.h>
#define INF 9999
void prims(int g[10][10],int n){
	int visited[10],i,j,k,v1,v2,mincost=0,min;
	for(i=0;i<n;i++)
		visited[i]=0;
	visited[0]=1;
	for(k=0;k<n-1;k++){
		min=INF;
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(g[i][j]!=INF && visited[i]==1 && visited[j]==0){
					if(g[i][j]<min){
						min=g[i][j];
						v1=i;
						v2=j;
					}
				}
			}
		}
		visited[v1]=1;
		visited[v2]=1;
		mincost+=min;
	}
	printf("\nMinimum Cost : %d",mincost);
}
int main(){
	int  a[10][10],i,j,n;
	printf("Enter the no of vertices: ");
	scanf("%d",&n);
	printf("Enter adjacency matrix:\n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j]==0)
				a[i][j]=INF;
		}		
	}
	prims(a,n);
}
