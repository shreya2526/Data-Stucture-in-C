#include <stdio.h>
int main()
{
    int row, col, i, j, a[10][10], count = 0;
    printf("Enter row: \n");
    scanf("%d", &row);
    printf("Enter column: \n");
    scanf("%d", &col);
    printf("Enter element of Matrix: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    printf("Elements are: \n");
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
    /*checking sparse of matrix*/
    for (i = 0; i < row; i++)
    {
        for (j = 0; j < col; j++)
        {
            if (a[i][j] == 0)
                count++;
        }
    }
    if (count > ((row * col) / 2))
    {
        printf("Matrix is a sparse matrix \n");
        printf("Non-zero elements are: ");
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (a[i][j] != 0)
                    printf("%d\t", a[i][j]);
            }
        }
        printf("\nPostions of non-zero elements in row are: \n");
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (a[i][j] != 0)
                    printf("%d\t", (i + 1));
            }
        }
        printf("\nPostions of non-zero elements in column are: \n");
        for (i = 0; i < row; i++)
        {
            for (j = 0; j < col; j++)
            {
                if (a[i][j] != 0)
                    printf("%d\t", (j + 1));
            }
        }
    }
    else
        printf("Matrix is not sparse matrix\n");
    return 0;
}