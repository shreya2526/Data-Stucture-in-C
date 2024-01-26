#include <stdio.h>
int main()
{
    int *ptr; 
    int a[10], i, n;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    ptr = &a[0];
    printf("Enter the elements of array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &*(ptr + i));
    }
    printf("Display the array: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", *(ptr + i));
    }
    return 0;
}