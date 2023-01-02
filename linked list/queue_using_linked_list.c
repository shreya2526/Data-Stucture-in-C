#include <stdio.h>
#include <stdlib.h>

// function declaration

void insert(int);
void delete ();
void peek(); // display the value of front
void display();

// creating node

struct node
{
    int data;
    struct node *next;
};
struct node *front = 0;
struct node *rear = 0;

// main function

void main()
{
    int choice, data;
    printf("\n\n\n====QUEUE IMPLEMENTATION USING LINKED LIST====\n\n\n");

    // menu driven function

    while (choice != 5)
    {
        printf("1.Insertion\n2.Deletion\n3.Peek\n4.Display\n5.Quit\n\n");
        printf("Enter your choice: "); // taking input
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to insert: \n");
            scanf("%d", &data);
            insert(data);
            break;
        case 2:
            delete ();
            break;
        case 3:
            peek();
            break;
        case 4:
            display();
            break;
        case 5:
            printf("Quitting");
            break;

        default:
            printf("Wrong choice!");
            break;
        }
    }
}

// Insertion function

void insert(int data)
{
    struct node *newnode = malloc(sizeof(struct node));
    newnode->data = data;
    newnode->next = NULL;
    if (front == 0 && rear == 0) // if queue is empty
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
    printf("%d has been inserted in queue\n\n",newnode->data);
}

// deletion function

void delete ()
{
    if (front == 0 && rear == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        struct node *temp = front;
        printf("%d has been deleted\n\n", front->data);
        front = front->next;
        free(temp);
    }
}
// display function

void display()
{
    struct node *p;
    if (front == 0 && rear == 0)
    {
        printf("Queue is empty\n\n");
    }
    else
    {
        p = front;
        while (p != 0)
        {
            printf("data: %d\n", p->data);
            p = p->next;
        }
        printf("\n\n");
    }
}

// peek function

void peek()
{
    if (front == 0 && rear == 0)
    {
        printf("Queue is empty");
    }
    else
    {
        printf("Peeked data: %d\n\n", front->data);
    }
}