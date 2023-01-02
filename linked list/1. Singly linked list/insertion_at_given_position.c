#include <stdio.h>
#include <stdlib.h>

// function declaration

void createlist(int n);
struct node *ins_at_n(struct node *, int data, int pos);
void display();

struct node
{
    int data;
    struct node *next;
} * head;

void main()
{
    int n, data, pos;
    printf("Enter the number of node you want to insert: ");
    scanf("%d", &n);
    createlist(n); // calling function to create the list
    printf("\nData in the list: ");
    display(); // calling funtion to display the entered list
    printf("Enter the position you want to insert the node: ");
    scanf("%d", &pos);
    printf("Enter the data you want to insert in %d node: ", pos);
    scanf("%d", &data);
    ins_at_n(head, data, pos); // calling the function to create node at N postition
    printf("Final list after adding node: ");
    display(); // calling the function to print the resultant list
}

// creating the list

void createlist(int n)
{
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));
    // If unable to allocate memory for head node
    if (head == NULL)
    {
        printf("Unable to allocate memory.");
    }
    else
    {
        // Reads data of node from the user
        printf("Enter the data of node 1: ");
        scanf("%d", &data);
        head->data = data; // Link the data field with data
        head->next = NULL; // Link the address field to NULL
        temp = head;
        // Create n nodes and adds to linked list
        for (i = 2; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));
            /* If memory is not allocated for newNode */
            if (newNode == NULL)
            {
                printf("Unable to allocate memory.");
                break;
            }
            else
            {
                printf("Enter the data of node %d: ", i);
                scanf("%d", &data);
                newNode->data = data; // Link the data field of newNode with data
                newNode->next = NULL; // Link the address field of newNode with NULL
                temp->next = newNode; // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }
        printf("SINGLY LINKED LIST CREATED SUCCESSFULLY\n");
    }
}

// display the list

void display()
{
    struct node *temp;
    // If the list is empty i.e. head = NULL
    if (head == NULL)
    {
        printf("List is empty.");
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {
            printf("Data = %d\n", temp->data); // Print data of current node
            temp = temp->next;                 // Move to next node
        }
    }
}

// inserting node at N position

struct node *ins_at_n(struct node *head, int data, int pos)
{
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    ptr2->data = data;
    ptr2->next = NULL;
    pos--; //it'll help to traverse the list
    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;
}