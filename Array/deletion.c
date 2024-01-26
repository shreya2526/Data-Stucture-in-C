#include <stdio.h>

void main()
{
    int a[25], size, choice, i, pos, pos1, data, item;
    printf("\n\n\n    ARRAY INSERTION AND DELETION    \n\n\n");
    printf("Enter the size of array: ");
    scanf("%d", &size);
    if (size > 25)
        printf("Array overflow\nArray size is 25\n");
    else if (size == 0)
    {
        printf("\nPlease enter size in between 1 to 25\n");
    }
    else
    {
        printf("\nEnter the elements: "); // traversal
        for (i = 0; i < size; i++)
        {
            scanf("%d", &a[i]);
        }
        printf("\nElements of array are: \n");
        for (i = 0; i < size; i++)
        {
            printf("%d\t", a[i]);
        }

        while (choice != 7)
        {
            printf("\n1.Add at beg\n2.Add at end\n3.Add at mid\n4.Delete at beg\n5.Delete at end\n6.Delete at mid\n7.Quit\nEnter your choice: ");
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
                if (size == 0)
                {
                    printf("invalid position\n");
                }
                else
                {
                    item = a[0];
                    printf("The deleted element is: %d\n", item);
                    for (i = 0; i < size - 1; i++)
                    {
                        a[i] = a[i + 1];
                    }
                    size--;
                    printf("Now elements of array are: \n");
                    for (i = 0; i < size; i++)
                    {
                        printf("%d\t", a[i]);
                    }
                }
                break;
            case 5:
                if (size == 0)
                {
                    printf("\nEmpty array\n");
                }
                else
                {
                    size--;
                    item = a[size];
                    printf("The deleted element is: %d\n", item);
                    printf("Now elements of array are: \n");
                    for (i = 0; i < size; i++)
                    {
                        printf("%d\t", a[i]);
                    }
                }
                break;
            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos1);
                if (pos1 == 0 || pos1 > size)
                {
                    printf("invalid position\n");
                }
                else
                {
                    item = a[pos1 - 1];
                    printf("The deleted element is: %d\n", item);
                    for (i = pos1 - 1; i < size - 1; i++)
                    {
                        a[i] = a[i + 1];
                    }
                    size--;
                    printf("Now elements of array are: \n");
                    for (i = 0; i < size; i++)
                    {
                        printf("%d\t", a[i]);
                    }
                }
                break;
            case 7:
                printf("Quitting\n");
                break;
            default:
                printf("wrong choice\n");
                break;
            }
        }
    }
}
