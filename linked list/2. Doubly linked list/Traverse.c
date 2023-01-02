#include <stdio.h>
#include <stdlib.h>

// fuction declaration

void create(int);
int traverse();

// making node

struct node
{
    int data;
    struct node *prev;
    struct node *next;
} * head, *last;

// main fuction

void main()
{
    int choice = 1, data, n;
    head = NULL;
    last = NULL;
    printf("\n\n\n======TRAVERSE IN DOUBLY LIKNKED LIST======\n\n\n");
    printf("1.Create List\n2.Traverse\n3.Quit\n");
    do
    {
        printf("Enter your choice? ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the no of node you want to insert: \n");
            scanf("%d", &n);
            create(n);
            break;
        case 2:
            traverse();
            break;
        case 3:
            printf("Quitting");
            exit(0);
            break;
        default:
            printf("\nPlease enter valid choice\n");
            break;
        }

    } while (choice != 3);
}
void create(int n)
{

    int i, data;
    struct node *newNode;

    if (n >= 1)
    {
        /*
         * Create and link the head node
         */
        head = (struct node *)malloc(sizeof(struct node));

        printf("Enter data of 1 node: ");
        scanf("%d", &data);

        head->data = data;
        head->prev = NULL;
        head->next = NULL;

        last = head;

        /*
         * Create and link rest of the n-1 nodes
         */
        for (i = 2; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            printf("Enter data of %d node: ", i);
            scanf("%d", &data);

            newNode->data = data;
            newNode->prev = last; // Link new node with the previous node
            newNode->next = NULL;

            last->next = newNode; // Link previous node with the new node
            last = newNode;       // Make new node as last/previous node
        }

        printf("\nDOUBLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
    printf("\nNode Inserted Successfully!!\n");
}
int traverse()
{
    struct node *ptr;
    if (head == NULL)
    {
        printf("\nEmpty List\n");
    }
    else
    {
        ptr = head;
        while (ptr != NULL)
        {
            printf("DATA= %d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}