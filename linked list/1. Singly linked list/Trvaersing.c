#include<stdio.h>
#include<stdlib.h>

//structure of a node
struct node{
    int data; //data
    struct node *next;  //address
}*head;

//function to create and display a linked list
void createList(int n);
void traverseList();
int main(){
    int i,n;
    printf("enter the number of nodes you want to insert: ");
    scanf("%d",&n);

    createList(n);
    printf("\ndata in the list: ");
    traverseList();
    return 0;
}

//create a list of n nodes

void createList(int n){
    struct node *newNode, *temp;
    int data, i;
    head = (struct node *)malloc(sizeof(struct node));

    //terminate if memeory not available
    if(head==NULL){
        printf("\nUnable to allocate memory");
        exit(0);
    }

    //input data from the user
    printf("Enter the data of node 1: ");
    scanf("%d",&data);
    head ->data = data; //link data field with data
    head->next = NULL; //link address field with null

    //create n-1 node and add to list
    temp=head;
    for(i=2;i<=n;i++){
        newNode=(struct node *)malloc(sizeof(struct node));
        //if memory is not allocate for new memory
        if(newNode==NULL){
            printf("\nUnable to allocate memory");
            break;
        }
        printf("Enter the data of node: ");
        scanf("%d",&data);
        newNode->data=data; //link data field of newNode
        newNode->next=NULL; //make sure new node points to null
        temp->next=newNode; //link previous with newNode
        temp=temp->next;  //make current node as previous node
    }
}

//Display entire list
void traverseList(){
    struct node *temp;
    //return if list is empty
    if(head==NULL){
        printf("List is empty");
        return;
    }
    temp = head;
    while(temp!=NULL){
        printf("\nData= %d\n",temp->data);  //print data of current node
        temp= temp->next;
    }
}