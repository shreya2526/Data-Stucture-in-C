#include <stdio.h>
int main()
{
    int a[40], i, n, key, low, mid, high;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    printf("Enter the elements for array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to search: ");
    scanf("%d", &key);
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    while (low <= high)
    {
        if (a[mid] < key)
            low = mid + 1;
        else if (a[mid] == key)
        {
            printf("%d element found at %d position", key, (mid + 1));
            break;
        }
        else
            high = mid - 1;
        mid = (low + high) / 2;
    }
    if (low > high)
        printf("Not Found!");

    return 0;
}