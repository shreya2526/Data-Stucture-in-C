#include<stdio.h>
#include<stdlib.h>
#define max 10
int stack[max];
int top=-1;

void push(int item);
int pop();
int peek();
int isfull();
int isempty();
void display();

void main(){
    int choice, item;
    printf("1. Push element from stack\n");
    printf("2. Pull element in stack\n");
    printf("3. Peek top element of stack\n");
    printf("4. Display element of stack\n");
    printf("5. Quit\n");

    while(1){
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch(choice){
            case 1:
                printf("Enter value you want to push: ");
                scanf("%d",&item);
                push(item);
                break;
            case 2:
                item =pop();
                printf("Item removed: %d\n",item);
                break;
            case 3: 
                item=peek();
                printf("Item at the top of the stack: %d\n",item);
                break;
            case 4:
                display();
                break;
            case 5: 
                printf("Quiting\n");
                exit(0); 
            default:
            printf("Wrong choice");      
        }
    }
}
void push(int item){
    if(isfull()){
        printf("Stack overflow");
        exit(1);
    }
    top+=1;
    stack[top]=item;
}
int pop(){
    if(isempty()){
        printf("Stack underflow");
        exit(1);
    }
    int item= stack[top];
    top-=1;
    return item;
}
int peek(){
    return stack[top];
}
int isempty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
int isfull(){
    if(top== max){
        return 1;
    }
    return 0;
}
void display(){
    int i;
    printf("Items of stack are: \n");
    for(i=top;i>=0;i--){
        printf("%d\n",stack[i]);
    }
}