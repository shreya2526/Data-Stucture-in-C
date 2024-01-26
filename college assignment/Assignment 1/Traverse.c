#include <stdio.h>
int main()
{
    int a[50], size, i, num, pos, size;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements of array: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("The Traverse of array is: ");

    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}