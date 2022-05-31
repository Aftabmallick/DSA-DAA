#include<stdio.h>
#include<stdlib.h>
int **g,*visited,n;
void dfs(int v){
	int j;
	printf("%d\t",v);
	visited[v]=1;
	for(j=0;j<n;j++){
		if(!visited[j] && g[v][j]==1)
		dfs(j);
	}
}

int main(){
	int i,j;
	printf("Enter no of vertices : ");
	scanf("%d",&n);
	visited=(int*)malloc(n*sizeof(int));
	g=(int**)malloc(n*sizeof(int*));
	printf("Enter adjacent matrix: \n");
	for(i=0;i<n;i++){
		visited[i]=0;
		g[i]=(int*)malloc(n*sizeof(int));
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			scanf("%d",&g[i][j]);
		}
	}
	printf("DFS spanning tree: ");
	dfs(0);	
	
}
