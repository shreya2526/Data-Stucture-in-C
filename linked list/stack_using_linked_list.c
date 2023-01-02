#include <stdio.h>
#include <stdlib.h>

// function declaration

void push(int);
void pop();
void display();

// creating node

struct node
{
    int data;
    struct node *next;
};
struct node *top = 0;

// main function

void main()
{
    int choice, i, data;
    printf("\n\n\n====STACK IMPLEMENTATION USING LINKED LIST====\n\n\n");

    // main driven function

    while (choice != 4)
    {
        printf("1.Push\n2.Pop\n3.Display\n4.Quit\n\n");
        printf("Enter your choice: "); // taking input
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            push(data);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            printf("Quitting");
            break;

        default:
            printf("Wrong choice!");
            break;
        }
    }
}

// push function

void push(int data)
{
    struct node *new = malloc(sizeof(struct node));
    new->data = data;
    new->next = top;
    top = new;
    printf("%d has been inserted\n\n", new->data);
}

// pop function

void pop()
{
    struct node *temp = top;
    if (top == 0)
    {
        printf("stack is empty");
    }
    else
    {
        printf("%d has been deleted\n\n", top->data);
        top = top->next;
        free(temp);
    }
}

// display function

void display()
{
    struct node *p = top;
    if (top == 0)
    {
        printf("List is empty\n\n");
    }
    else
    {
        p = top;
        while (p != 0)
        {
            printf("data: %d\t", p->data);
            p = p->next;
        }
        printf("\n\n");
    }
}