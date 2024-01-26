#include <stdio.h>
int main()
{
    int a[50], size, pos, num, item, i;
    printf("Enter size of array: ");
    scanf("%d", &size);
    printf("Enter elements of array: ");
    for (i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("From what position you want to delete: ");
    scanf("%d", &pos); 
    for (i = pos - 1; i < size - 1; i++)
    {
        a[i] = a[i + 1];
    }
    printf("The resultant array is: \n");
    for (i = 0; i < size - 1; i++)
    {
        printf(" %d \n", a[i]);
    }

return 0;
}