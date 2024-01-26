#include <stdio.h>
#include <stdlib.h>
#define max 7
int dequeue[max];
int front = -1;
int rear = -1;
void insert_frontend(int item);
void insert_rearend(int item);
int delete_frontend();
int delete_rearend();
void display();
int isEmpty();
int isFull();
int main()
{
    int item, choice;
    while (1)
    {
        printf("1.Insert an element: \n");
        printf("2.Delete an element from front end: \n");
        printf("2.Delete an element from rear end: \n");
        printf("3.Display an element: \n");
        printf("4.Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("input the element: ");
            scanf("%d", &item);
            insert_frontend(item);
            break;
        case 2:
            printf("input the element: ");
            scanf("%d", &item);
            insert_rearend(item);
            break;
        case 3:
            printf("deleted elements are: %d\n", delete_frontend());
            break;
        case 4:
            printf("deleted elements are: %d\n", delete_rearend());
            break;
        case 5:
            display();
            break;
        case 6:
            exit(1);
        default:
            printf("Wrong choice");
        }
    }
    printf("front= %d, rear = %d\n", front, rear);
    display();
}
void insert_frontend(int item)
{
    if (isFull())
    {
        printf("Queue overflow!");
        return;
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (front == 0)
    {
        front = max - 1;
    }
    else
    {
        front = front - 1;
        dequeue[front] = item;
    }
}
void insert_rearend(int item)
{
    if (isFull())
    {
        printf("Queue overflow!");
        return;
    }
    else if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == max - 1)
    {
        front = max - 1;
    }
    else
    {
        rear = rear + 1;
        dequeue[rear] = item;
    }
}
int delete_frontend()
{
    int item;
    if (isEmpty())
    {
        printf("Queue is underflow");
        exit(1);
    }
    item = dequeue[front];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else
    {
        if (front == max - 1)
        {
            front = 0;
        }
        else
        {
            front = front + 1;
            return item;
        }
    }
}
int delete_rearend()
{
    int item;
    if (isEmpty())
    {
        printf("Queue is underflow");
        exit(1);
    }
    int dequeue[rear];
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = max - 1;
    }
    else
    {
        rear = rear - 1;
        return item;
    }
}
int isFull()
{
    if (front == 0 && rear == (max - 1) || (front == rear == 1))
        return 1;
    else
        retrun 0;
}
int isEmpty()
{
    if (front == -1){
        retrun 1;
    }else{
        return 0;
    }
}
void display()
{
    int i;
    if (isEmpty())
    {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements are:\n");
    i = front;
    if (front <= rear)
    {
        while (i <= rear)
        {
            printf("%d", dequeue[i++]);
        }
        i = 0;
        while (i <= rear)
        {
            printf("%d", dequeue[i++]);
        }
        printf("\n");
    }
    else
    {
        while (i <= max - 1)
        {
            printf("%d", dequeue[i++]);
        }
        i = 0;
        while (i <= rear)
        {
            printf("%d", dequeue[i++]);
        }
        printf("\n");
    }
}

