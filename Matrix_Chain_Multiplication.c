#include <stdio.h>
#include <stdlib.h>
#define INF 9999
int **m, **s, *p;
int n;
void matrix_chain()
{
    int i, l, j, k, q;
    for (i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }
    for (l = 2; l <= n; l++)
    {
        for (i = 1; i <= n - l + 1; i++)
        {
            j = i + l - 1;
            m[i][j] = INF;
            for (k = i; k < j; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
    printf("Minimum cost of Multiplication is : %d\n",q);
}

void par(int i, int j)
{
    if (i == j)
    {
        printf("A%d:", i);
    }
    else
    {
        printf("(");
        par(i, s[i][j]);
        par(s[i][j] + 1, j);
        printf(")");
    }
}

int main()
{
    int d, i, j;
    printf("Enter the number of dimension (No of matrix + 1): ");
    scanf("%d", &d);
    p=(int*)malloc(d*sizeof(int));
    m=(int**)malloc(d*sizeof(int*));
    s=(int**)malloc(d*sizeof(int*));
    printf("No of matrix is : %d\n",d-1);
    printf("Enter %d dimensions: ", d);
    for (i = 0; i < d; i++)
    {
        scanf("%d", &p[i]);
        m[i]=(int*)malloc(d*sizeof(int));
    	s[i]=(int*)malloc(d*sizeof(int));
    }
    n = d - 1;
    matrix_chain();
    printf("Optimal pattern: ");
    par(1, n);
    printf("\nThe content of m table is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i <= j)
                printf("%d\t", m[i][j]);
            else
            printf("\t");
        }
        printf("\n");
    }
    printf("\nThe content of s table is:\n");
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i < j)
                printf("%d\t", s[i][j]);
            else
            printf("\t");
        }
        printf("\n");
    }
}
