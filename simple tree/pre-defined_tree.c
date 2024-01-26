#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *createNode(int data)
{
    struct node *p;
    p = (struct node *)malloc(sizeof(struct node));
    p->data = data;
    p->left = NULL;
    p->right = NULL;
    return p;
}

// printing the tree in in-order

void InPrint(struct node *tree)
{
    if (tree->left)
        InPrint(tree->left);
    printf("%d\t", tree->data);
    if (tree->right)
        InPrint(tree->right);
}

// printing tree in pre-order

void PrePrint(struct node *tree)
{
    if (tree == NULL)
        return;
    printf("%d\t", tree->data); // printinf root node
    PrePrint(tree->left);       // printing left node
    PrePrint(tree->right);      // printing right node
}

// printing tree in post-order

void PostPrint(struct node *tree)
{
    if (tree == NULL)
        return;
    PostPrint(tree->left);
    PostPrint(tree->right);
    printf("%d\t", tree->data);
}

void main()
{
    struct node *root = createNode(2); // root node
    root->left = createNode(3);        // left child
    root->right = createNode(4);       // right child

    // printing tree
    printf("\nPre-order tree:\n");
    PrePrint(root);
    printf("\n");
    printf("In-order tree:\n");
    InPrint(root);
    printf("\n");
    printf("Post-order tree:\n");
    PostPrint(root);
    printf("\n");
}
