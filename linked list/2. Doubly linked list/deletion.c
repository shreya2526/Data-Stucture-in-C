#include<stdio.h>
#include<stdlib.h>

//calling function

struct node* createlist(struct node*, int);
struct node* delAtBeg(struct node*);
struct node* delAtEnd(struct node*);
struct node* delInter(struct node*, int);
void print(struct node*);

//making node

struct node{
    struct node* prev;
    int data;
    struct node* next;
};

//main program

void main(){
    int choice, n, position;
    struct node* head=NULL;    
    printf("======DOUBLY LINKED LIST DELETION PROGRAM======\n\n\n\n\n1.Create list\n2.Delete the first node\n3.Delete last node\n4.Delete intermediate node\n5.Display the result\n6.Quit\n");
    while(choice!=6){
        printf("Enter your choice: ");
        scanf("%d",&choice);
    switch(choice){
        case 1:
            printf("Enter the number of nodes you want to insert: ");
            scanf("%d",&n);
            head = createlist(head, n);
            break;
        case 2: 
            head = delAtBeg(head);
            break;
        case 3:
            head=delAtEnd(head);
            break;
        case 4: 
            printf("Enter position you want to delete: ");
            scanf("%d",&position);
            head=delInter(head,position);
            break;
        case 5:
            print(head);
            break;
        case 6: 
            printf("Quitting");
            break;
        default:
        printf("Error! Invalid choice. Please choose between 0-6");
    }
    }

}

//creating list

struct node* createlist(struct node* head, int n){
    struct node* last=NULL;
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
    return head;
}

//delete 1st node

struct node* delAtBeg(struct node* head){
    printf("Deleted node: %d\n",head->data);
    head=head->next;
    head->prev=NULL;
    return head;
}

//delete end node

struct node* delAtEnd(struct node* head){
    struct node* temp=malloc(sizeof(struct node));
    struct node* temp2=malloc(sizeof(struct node));
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    printf("Deleted node: %d\n",temp->data);
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    //free(temp2);
    return head;
}

//delete intermediate node

struct node* delInter(struct node* head, int position){
    struct node* temp=malloc(sizeof(struct node));
    struct node* temp2=malloc(sizeof(struct node));
    temp=head;
    if(position==1){
        head=delAtBeg(head);
        return head;     
    }
    while(position>1){
        temp=temp->next;
        position--;
    }
    if(temp->next==NULL){
        head=delAtEnd(head);
    }
    else{
        printf("Deleted node: %d\n",temp->data);
        temp2=temp->prev;
        temp2->next=temp->next;
        temp->next->prev=temp2;
        temp=NULL;
        temp2=NULL;
        free(temp);
    }
    return head;
}

//printing the list

void print(struct node* head){
    struct node* ptr=head;
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}