#include <stdio.h>

// main function

void main()
{
    int a[20], i, j, n, min = 0, temp = 0, count = 0;

    printf("\n\n====SELECTION SORTING====\n\n\n");

    // taking inputs

    printf("Enter the no of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // printing unsoreted list

    printf("\nThe given list is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    // Sorting program

    for (i = 0; i < n - 1; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        if (min != i)
        {
            temp = a[i];
            a[i] = a[min];
            a[min] = temp;
        }
        count++;
    }

    // printing sorted list

    printf("\n\nSorted list: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n\nTook %d passes to sort", count);
}