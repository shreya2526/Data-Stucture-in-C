#include<stdio.h>
int main()
{
    int a[30], i, j, n, item, flag = 0;
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the elements for array: ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the element to be found multiple time: ");
    scanf("%d", &item);
    for (i = 0; i < n; i++)
    {
        if (a[i] == item)
            flag++;
    }
    if (flag == 0)
    {
        printf("Element not occuring multiple times");
    }
    else
    {
        printf("%d found in array %d times", item, flag);
    }
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (a[i] == a[j])
            {
                a[j] = a[j + 1];
                j--;
                n--;
            }
        }
    }
    printf("\nThe final array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    return 0;
}