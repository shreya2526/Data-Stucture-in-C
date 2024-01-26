#include <stdio.h>
int main()
{
    int a[50], size, num, pos, i;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements of array: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("Enter the number you want to insert: ");
    scanf("%d", &num);
    printf("Enter the position: ");
    scanf("%d", &pos);
    for (i = size - 1; i >= pos - 1; i--)
    {
        a[i + 1] = a[i];
    }
    a[pos - 1] = num;
    size++;
    printf("Elements in array are: ");
    for (i = 0; i < size; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}