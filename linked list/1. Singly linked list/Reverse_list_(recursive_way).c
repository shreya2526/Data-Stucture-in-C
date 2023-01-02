#include<stdio.h>
#include<stdlib.h>

void add_beg();
void add_end();
void add_mid();
void reverse();
void display();

struct node{
    int info;
    struct node* link;
}*head;

void main(){
    int data, choice,pos;
    printf("\n\n\n      REVERSE THE LINKED LIST     \n\n\n");
    while(choice!=6){
        printf("\n1.Add at beg\n2.Add at end\n3.At at mid\n4.Reverse the list\n5.Display list\n6.Quit\nEnter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            add_beg();
            break;
        case 2:
            add_end();
            break;
        case 3:
            add_mid();
            break;
        case 4:
            reverse();
            break;
        case 5:
            display();
            break;
        case 6:
            printf("Quitting");
            break;
        default:
            printf("Wrong choice");
            break;
        }
    }
}

void display(){
    struct node* temp;
    temp=head;
    while(temp!=NULL){
        printf("%d\t",temp->info);
        temp=temp->link;
    }
    printf("\n");
}


void add_beg(){
    int data;
    struct node* temp=malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d",&data);
    temp->info=data;
    temp->link=head;
    head=temp;
    printf("%d has been inserted\n",temp->info);
}

void add_end(){
    int data;
    struct node* newnode=malloc(sizeof(struct node));
    struct node* temp;
    printf("Enter data: ");
    scanf("%d",&data);
   if(newnode==NULL){
    printf("Unable to allocate memory");
   }
   else{
    newnode->info=data;
    newnode->link=NULL;
    temp=head;
    while(temp!=NULL && temp->link!=NULL){
        temp=temp->link;
    }
    temp->link=newnode;
    printf("%d has been inserted\n",newnode->info);
   }
}

void add_mid(){
    int data,pos;
    printf("Enter data: ");
    scanf("%d",&data);
    printf("Enter position: ");
    scanf("%d",&pos);
    struct node* temp=head;
    struct node* new=malloc(sizeof(struct node));
    new->info=data;
    new->link=NULL;
    pos--;
    while(pos!=1){
        temp=temp->link;
        pos--;
    }
    new->link=temp->link;
    temp->link=new;
    printf("%d has been inserted\n",new->info);
}

void reverse(){
    struct node *pn, *cn, *nn;  //pn:- previous node, cn:- current node, nn:- next node
    pn=NULL;
    cn=nn=head;
    while(nn!=NULL){
        nn=nn->link;
        cn->link=pn;
        pn=cn;
        cn=nn;
    }
    head=pn;
    printf("List has reversed successfully\n");
}