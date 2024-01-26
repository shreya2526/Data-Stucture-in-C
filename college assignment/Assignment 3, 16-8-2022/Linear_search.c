#include <stdio.h>
int main()
{
    int a[40], i, n, key;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements for array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    for (i = 0; i < n; i++)
    {
        if (a[i] == key)
            break;
    }
    if (i < n)
    {
        printf("%d element found at %d position", key, (i + 1));
    }
    else
    {
        printf("Element not found!");
    }
    return 0;
}