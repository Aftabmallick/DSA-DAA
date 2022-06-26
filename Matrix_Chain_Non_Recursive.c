#include<stdio.h>
int d,p[10],s[10][10];
void matrix_chain(){
	int m[10][10],i,j,k,l,q,n;
	n=d-1;
	for(i=1;i<=n;i++){
		m[i][i]=0;
	}
	for(l=2;l<=n;l++){
		for(i=1;i<=n-l+1;i++){
			j=i+l-1;
			m[i][j]=99999999;
			for(k=i;k<j;k++){
				q=m[i][k]+m[k+1][j]+p[i+1]*p[k]*p[j];
				if(q<m[i][j]){
					m[i][j]=q;
					s[i][j]=k;
				}
			}
		}
	}
	printf("Multiplication Table: \n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i<=j)
				printf("\t%d",m[i][j]);
			else
			printf("\t");
		}
			printf("\n");
		}
	printf("\nK Table: \n");
	for(i=1;i<=n;i++){
		for(j=1;j<=n;j++){
			if(i<j)
				printf("\t%d",s[i][j]);
			else
				printf("\t");
		}
			printf("\n");
		}
}
void print_optimal_paren(int low ,int high){
	if(low==high)
		printf("A%d",low);
	else{
		printf("(");
		print_optimal_paren(low ,s[low][high]);
		print_optimal_paren(s[low][high]+1,high);
		printf(")");
	}
}
int main(){
	int i;
	
	printf ("Enter no of dimensions: ");
	scanf("%d",&d);
	printf("Enter the dimnsions: ");
	for(i=0;i<d;i++)
		scanf("%d",&p[i]);
	matrix_chain();
	print_optimal_paren(1,d-1);
	return 0;
}
