#include <stdio.h>
int main()
{
    int a[100], b[100], c[100], size1, size2, i, k;

    // taking elements for array1//

    printf("Enter the size of array 1: ");
    scanf("%d", &size1);
    printf("Enter the elements: ");
    for (i = 0; i < size1; i++)
    {
        scanf("%d", &a[i]);
        c[i]= a[i];
    }
    k=i;

    // taking elements for array2//

    printf("Enter the size of array 2: ");
    scanf("%d", &size2);
    printf("Enter the elements: ");
    for (i = 0; i < size2; i++)
    {
        scanf("%d", &b[i]);
        c[k]=b[i];
        k++;
    }

   //printing merged array//

    printf("Merged array is: ");
    for(i=0; i<k ; i++)
    {
        printf("%d ",c[i]);
    }

    return 0;
}