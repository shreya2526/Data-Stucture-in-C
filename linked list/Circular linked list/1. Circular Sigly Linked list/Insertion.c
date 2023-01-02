#include <stdio.h>
#include <stdlib.h>

// calling function

struct node *createlist(struct node *);
struct node *add_To_empty(struct node *, int);
struct node *add_at_end(struct node *, int);
void Ins_beg(struct node *);
void Ins_end(struct node *);
void Ins_At_N(struct node *, int, int);
struct node *circularSingly(int);

// creating node

struct node
{
    int data;
    struct node *next;
};

// main fuction

void main()
{
    int choice, pos, data;
    struct node *tail;
    tail = circularSingly(data);
    printf("\n\n\n=====CIRCULAR SINGLY LINKED LIST:- INSERTION PROGRAM======\n\n\n");

    while (choice != 5)
    {
        printf("1.Create list\n2.Insertion- At beginning\n3.Insertion-At end\n4.Insertion- At n postion\n5.Quit\n                                                                                                                                                                                                 ");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            tail = createlist(tail);
            printf("DOUBLY LINKED LIST HAS CREATED SUCESSFULLY");
            break;
        case 2:
            Ins_beg(tail);
            printf("Node has inserted at the beginning successfully");
            break;
        case 3:
            Ins_end(tail);
            printf("Node has inserted at the end sucessfully");
            break;
        case 4:
            printf("Enter the position you want to insert the node: ");
            scanf("%d", &pos);
            printf("Enter the data for the node: ");
            scanf("%d", &data);
            Ins_At_N(tail, pos, data);
            break;
        case 5:
            printf("Quitting");
            break;
        default:
            printf("Error! Invalid option, please choose option between 1 to 5");
            break;
        }
    }
}

struct node *circularSingly(int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

// creating list

struct node *createlist(struct node *tail)
{
    int i, n, data;
    printf("Enter the number of nodes of the linked list: ");
    scanf("%d", &n);
    if (n == 0)
    {
        return tail;
    }
    printf("Enter the data for element 1: ");
    scanf("%d", &data);
    tail = add_To_empty(tail, data);
    for (i = 1; i < n; i++)
    {
        printf("Enter the data for element %d: ");
        scanf("%d", &data);
        tail = add_at_end(tail, data);
    }
    return tail;
}

// inserion at beginning function

void Ins_beg(struct node *tail)
{
    struct node *newP;
    newP->next = tail->next;
    tail->next = newP;
}

// Insertion at the end functipn

void Ins_end(struct node *tail)
{
    struct node *p = tail->next;
    do
    {
        printf("%d", p->data);
        p = p->next;
    } while (p != tail->next);
}

// Insertion at the N postion

void Ins_At_N(struct node *tail, int pos, int data)
{
    int i;
    struct node *p, *newP;
    p = tail->next;
    while (pos > 1)
    {
        p = p->next;
        pos--;
    }
    newP->next = p->next;
    p->next = newP;
    if (p == tail)
    {
        tail = tail->next;
    }
    // if(tail==NULL){
    //     printf("Error, List is empty!\n");
    // }
    // else{
    //     p=tail;
    //     i=1;
    //     while(i<pos-1 && p!=NULL){
    //         p=p->next;
    //         i++;
    //     }
    //     if(pos==1){
    //        Ins_beg(tail);
    //     }
    //     else if(p==)
    // }
}

// add_to_empty function

struct node *add_To_empty(struct node *tail, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->next = temp;
    return temp;
}

// add_to_end function

struct node *add_at_end(struct node *tail, int data)
{
    struct node *newP = malloc(sizeof(struct node));
    newP->data = data;
    newP->next = NULL;
    newP->next = tail->next;
    tail->next = newP;
    tail = tail->next;
    return tail;
}
