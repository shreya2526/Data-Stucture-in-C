#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *l;
    struct tree *r;
}*root;

void preorder(struct tree *);
void inorder(struct tree *);
void postorder(struct tree *);
void link(int);

struct tree *create(int data)
{
    struct tree *p = malloc(sizeof(struct tree));
    p->data = data;
    p->l = NULL;
    p->r = NULL;
    return p;
}

void main()
{
    int choice, data;
    printf("\n\n===== CHARACTER BINERY TREE =====\n\n");
    printf("1.Create tree\n2.Print in Pre-order\n3.Print in In-order\n4.Print in Post-order\n5.Exit");
    while (choice != 5)
    {
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter data: ");
            scanf("%d", &data);
            create(data);
            link(data);
            break;
        case 2:
            preorder(root);
            break;
        case 3:
            inorder(root);
            break;
        case 4:
            postorder(root);
            break;
        case 5:
            printf("Quitting\n");
            break;
        default:
            printf("\nInvalid choice\n");
            break;
        }
    }
}

void preorder(struct tree *n)
{
    if (n == NULL)
        printf("Null");
    // return;
    printf("%d\t", root->data);
    preorder(n->l);
    preorder(n->r);
}

void inorder(struct tree *n)
{
    if (n->l)
        inorder(n->l);
    printf("%d\t", n->data);
    if (n->r)
        inorder(n->r);
}

void postorder(struct tree *n)
{
    if (n == NULL)
        return;
    postorder(n->l);
    postorder(n->r);
    printf("%d\t", n->data);
}

void link(int data)
{
    if (root == NULL)
        root->data = data;
    else
        root->l=create(data);
        root->r=create(data);
}