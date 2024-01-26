#include<stdio.h>
#include<stdlib.h>

// function declaration

void createList(int n);                            //for create list
struct node* Ins_beg(struct node*,int data);      //for inserting node at beginning
void Ins_end(int data);                          //for inserting node at ending
void Ins_At_N(int data, int pos);               //for inserting node at intermediate position
void Display();                                //for displaying the list

//creating node

struct node{
    int data;
    struct node* next;
}*head;

//main fuction

void main(){
    int n,data,choice,pos;
    printf("\n\n\n========INSERTION FUNCTION IN SINGLY LINKED LIST=======\n\n\n1.Creating list\n2.Insertion-At Beginning\n3.Insertion-At Ending\n4.Insertion-At N position\n5.Quit\n");
    while(choice!=5)
    {
        printf("\nEnter your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the total number of nodes you want to insert: ");
            scanf("%d",&n);
            createList(n);
            Display();
            break;
        case 2:
            printf("Enter the data of first node: ");
            scanf("%d",&data);
            head=Ins_beg(head,data);
            Display();
            break;
        case 3: 
            printf("Enter the data you want to insert at last node: ");
            scanf("%d",&data);
            Ins_end(data);
            Display();
            break; 
        case 4:
            printf("Enter the position you want to insert the node: ");
            scanf("%d",&pos);
            printf("Enter the data for %d node: ",pos);
            scanf("%d",&data);
            Ins_At_N(data,pos);
            Display();
            break; 
        case 5:
            printf("Quitting");
            break;      
        default:
            printf("Error! Invalid option, please choose option between 1-5");
            break;
        }
    }
}

//creating the list

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

        // Input data of node from the user
        
        printf("Enter the data of node 1: ");
        scanf("%d", &data);

        head->data = data;                                              // Link data field with data
        head->next = NULL;                                             // Link address field to NULL
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
                newNode->data = data;                             // Link data field of newNode with data
                newNode->next = NULL;                            // Link address field of newNode with NULL
                temp->next = newNode;                           // Link previous node i.e. temp to the newNode
                temp = temp->next;
            }
        }
        printf("\nSINGLY LINKED LIST CREATED SUCCESSFULLY\n\n");
    }
}

// Creating a new node and inserting at the beginning of the linked list.

struct node* Ins_beg(struct node* head, int data){
    struct node *ptr=malloc(sizeof(struct node));
    ptr->data=data;                                                        //set ptr value
    ptr->next=NULL;                                                       //set as end of list
    if (head == NULL)                                             //then list is empty, so set as head node
    {
        head=ptr;
        head->next=NULL;
    }
    else                                                               //else add to the left of list
    {
        ptr->next = head;                                               // Link address part
        head = ptr;                                                     // Make ptr as first node
        printf("\nDATA INSERTED SUCCESSFULLY\n\n");
    }
    return head;
   
}

//Displaying the entire list

void Display(){
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
            printf("Data = %d\n", temp->data);                     // Print data of current node
            temp = temp->next;                                    // Move to next node
        }
    }
}

//Inserting node at the end

void Ins_end(int data){
    struct node *newNode, *temp;
    newNode = (struct node*)malloc(sizeof(struct node));
    if(newNode == NULL){
        printf("Unable to allocate memory.");
    }
    else{
        newNode->data = data;                                         // Link the data part
        newNode->next = NULL; 
        temp = head;
        
        // Traverse to the last node
        
        while(temp != NULL && temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;                                          // Link address part
        printf("\nDATA INSERTED SUCCESSFULLY\n\n");
    }
}


//Inserting node at N intermediate position

void Ins_At_N(int data, int pos){
    struct node *ptr = head;
    struct node *ptr2 = malloc(sizeof(struct node));
    if(ptr==NULL){
        printf("Unable!");
    }
    else{
        ptr2->data = data;
    ptr2->next = NULL;                                   //as the new node address is currently initized by NULL
    pos--;                                                          //it'll help to traverse the list
    while (pos != 1)
    {
        ptr = ptr->next;
        pos--;
    }
    ptr2->next = ptr->next;
    ptr->next = ptr2;
    printf("\nDATA INSERTED SUCCESSFULLY!\n\n");
    }
}