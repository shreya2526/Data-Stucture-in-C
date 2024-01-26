#include <stdio.h>

// fuction declaration

void merge_sort(int, int);
void merge_array(int, int, int, int);

int a[20], n;

// maiin function

void main()
{
    int i;

    printf("\n\n\n==== MERGE SORT ====\n\n\n");

    // taking inputs

    printf("Enter the no of elements to sort: ");
    scanf("%d", &n);
    printf("\nEnter %d Elements for Sorting\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // printing unsoreted list

    printf("\nYour Data   :");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }

    merge_sort(0, n - 1);

    // printing sorted list

    printf("\n\nSorted Data :");
    for (i = 0; i < n; i++)
    {
        printf("\t%d", a[i]);
    }
}

// dividing list into halves

void merge_sort(int i, int j)
{
    int m;

    if (i < j)
    {
        m = (i + j) / 2;

        merge_sort(i, m);
        merge_sort(m + 1, j);

        // Merging two arrays

        merge_array(i, m, m + 1, j);
    }
}

// merging sorted list

void merge_array(int e, int b, int c, int d)
{
    int t[50];
    int i = e, j = c, k = 0;

    while (i <= b && j <= d)
    {
        if (a[i] < a[j])
            t[k++] = a[i++];
        else
            t[k++] = a[j++];
    }

    // collect remaining elements

    while (i <= b)
        t[k++] = a[i++];

    while (j <= d)
        t[k++] = a[j++];

    for (i = e, j = 0; i <= d; i++, j++)
        a[i] = t[j];
}