#include <stdio.h>

void main()
{
    int a[25], size, choice, i, pos, data;
    printf("\n\n\n    ARRAY INSERTION    \n\n\n");
    printf("Enter the size of array: ");
    scanf("%d", &size);
    if (size > 25)
        printf("Array overflow\nArray size is 25\n");
    else
    {
        printf("\nEnter the elements: "); // traversal
        for (i = 0; i < size; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("Elements of array are: \n");
        for (i = 0; i < size; i++)
        {
            printf("%d\t", a[i]);
        }

        while (choice != 4)
        {
            printf("\n1.Add at beg\n2.Add at end\n3.Add at mid\n4.Quit\nEnter your choice: ");
            scanf("%d", &choice);
            switch (choice)
            {
            case 1:
                printf("Enter the data: ");
                scanf("%d", &data);
                for (i = size - 1; i >= 0; i--)
                {
                    a[i + 1] = a[i];
                }
                a[0] = data;
                size++;
                printf("Now elements of array are: \n");
                for (i = 0; i < size; i++)
                {
                    printf("%d\t", a[i]);
                }
                break;
            case 2:
                printf("Enter the data: ");
                scanf("%d", &data);
                a[size] = data;
                size++;
                printf("Now elements of array are: \n");
                for (i = 0; i < size; i++)
                {
                    printf("%d\t", a[i]);
                }
                break;
            case 3:
                printf("Enter the data: ");
                scanf("%d", &data);
                printf("Enter the position: ");
                scanf("%d", &pos);
                for (i = size - 1; i >= pos - 1; i--)
                {
                    a[i + 1] = a[i];
                }
                a[pos - 1] = data;
                size++;
                printf("Now elements of array are: \n");
                for (i = 0; i < size; i++)
                {
                    printf("%d\t", a[i]);
                }
                break;
            case 4:
                printf("Quitting\n");
                break;
            default:
                printf("wrong choice\n");
                break;
            }
        }
    }
}
