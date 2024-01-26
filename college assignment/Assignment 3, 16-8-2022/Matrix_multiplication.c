#include <stdio.h>
int main()
{
    int a[30][30], b[30][30], c[30][30], i, j, k, m, n, p, q;
    printf("Enter the row and column no for matrix A: ");
    scanf("%d %d", &m, &n);
    printf("Enter the row and column no for matrix B: ");
    scanf("%d %d", &p, &q);
    if (n != p && m != q)
    {
        printf("FORMULA: Row of 1st matrix must be equal to Column of 2nd matrix and Column of 1st matrix must be equal to Row of 2nd matrix");
    }
    else
    {
        printf("Enter the element for A matrix: ");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < n; j++)
            {
                scanf("%d", &a[i][j]);
            }
        }
        printf("A matrix is: \n");
        for (i = 0; i < m; i++)
        {

            for (j = 0; j < n; j++)
            {
                printf("%d\t", a[i][j]);
            }
            printf("\n");
        }
        printf("Enter the element for B matrix: ");
        for (i = 0; i < p; i++)
        {
            for (j = 0; j < q; j++)
            {
                scanf("%d", &b[i][j]);
            }
        }
        printf("B matrix is: \n");
        for (i = 0; i < p; i++)
        {

            for (j = 0; j < q; j++)
            {
                printf("%d\t", b[i][j]);
            }
            printf("\n");
        }
        for (i = 0; i < (m, p); i++)
        {
            for (j = 0; j < (n, q); j++)
            {
                for (k = 0; k < (m, p); k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        printf("Multiplied result is: \n");
        for (i = 0; i < m; i++)
        {
            for (j = 0; j < q; j++)
            {
                printf("%d\t", c[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}