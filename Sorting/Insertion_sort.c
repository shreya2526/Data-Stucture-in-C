#include <stdio.h>

void main()
{
    int i, j, temp, n, a[30];

    printf("\n\nEnter the no of elements: ");
    scanf("%d", &n);

    printf("\nEnter the element to sort: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]); // taking input
    }

    printf("\nList before sorting:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]); // printing the list before sorting
    }

    // sorting function
    
    for (i = 0; i < n; i++)
    {
        temp = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }

    printf("\nList after sorting:");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]); // printing after sorting
    }
}