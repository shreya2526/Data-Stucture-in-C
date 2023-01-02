#include <stdio.h>
#include <stdlib.h>

// Structure of a node

struct node
{
    int data;          // Data
    struct node *next; // Address
} * head;

// function declaration

void createList(int);
void Del_Beg();
void displayList();
void Del_End();
void Del_At_n(int);
void Del_add_First();

// main function

void main()
{
    int n, choice, pos;

    printf("\n\n\n======DELETION PROGRAM IN SINGLY LINKED LIST======\n\n\n1.Create the list\n2.Deletion-At Beginning\n3.Deletion-At certain postion\n4.Deletion-At End\n5.Delete and add at first\n6.Quit\n");

    while (choice != 6)
    {

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the no of nodes you want to insert: ");
            scanf("%d", &n);
            createList(n);
            displayList();
            break;
        case 2:
            Del_Beg();
            displayList();
            break;
        case 3:
            printf("Enter the position you want to delete: ");
            scanf("%d", &pos);
            Del_At_n(pos);
            displayList();
            break;
        case 4:
            Del_End();
            displayList();
            break;
        case 5:
            Del_add_First();
            displayList();
            break;
        case 6:
            printf("Quitting");
            break;
        default:
            printf("Error! please choose option in between 1-5");
            break;
        }
    }
}

// creating list

void createList(int n)
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

        // In data of node from the user

        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data; // Link the data field with data
        head->next = NULL; // Link the address field to NULL

        temp = head;

        // Create n nodes and adds to linked list

        for (i = 2; i <= n; i++)
        {
            newNode = (struct node *)malloc(sizeof(struct node));

            // If memory is not allocated for newNode
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

// Deletion of first node

void Del_Beg()
{
    struct node *toDelete;

    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        head = head->next;

        printf("\nData deleted = %d\n", toDelete->data);

        // Clears the memory occupied by first node

        free(toDelete);

        printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
    }
}

// Displays the entire list

void displayList()
{
    struct node *temp;

    // If the list is empty i.e. head = NULL

    if (head == NULL)
    {
        printf("List is empty.\n");
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

// Deletion of last node

void Del_End()
{
    struct node *toDelete, *secondLastNode;

    if (head == NULL)
    {
        printf("List is already empty.");
    }
    else
    {
        toDelete = head;
        secondLastNode = head;

        // Traverse to the last node of the list

        while (toDelete->next != NULL)
        {
            secondLastNode = toDelete;
            toDelete = toDelete->next;
        }

        if (toDelete == head)
        {
            head = NULL;
        }
        else
        {
            // Disconnect link of second last node with last node

            secondLastNode->next = NULL;
        }

        // Delete the last node

        free(toDelete);

        printf("SUCCESSFULLY DELETED LAST NODE OF LIST\n");
    }
}

// Deletion at certain position

void Del_At_n(int pos)
{
    int k = 1;
    struct node *p, *q;
    if (head == NULL)
    {
        printf("List Empty");
        return;
    }
    p = head;
    if (pos == 1)
    {
        head = head->next;
        free(p);
        return;
    }
    else
    {
        while ((p != NULL) && k < pos)
        {
            k++;
            q = p;
            p = p->next;
        }
        if (p == NULL)
        {
            printf("Position does not exist\n");
            return;
        }
        else
        {
            q->next = p->next;
            free(p);
        }
        return;
    }
}

void Del_add_First(){
   struct node* temp=head;
   while(temp->next->next!=NULL){
    temp=temp->next;
   } 
   temp->next->next=head;
   head=temp->next;
   temp->next=NULL;
}