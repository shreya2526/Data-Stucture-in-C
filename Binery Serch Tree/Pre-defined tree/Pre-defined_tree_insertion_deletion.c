#include<stdio.h>
#include<stdlib.h>

//creating tree node

struct node{
   int key;
   struct node *left, *right;
};

//function declaration

struct node* newNode(int);
void inordertraversal(struct node *root);
struct node* insert(struct node* node, int key);
struct node * minValueNode(struct node* node);
struct node* deleteNode(struct node* root, int key);

//new node function

struct node *newNode(int item){
   struct node *temp = (struct node *)malloc(sizeof(struct node));
   temp->key = item;
   temp->left = temp->right = NULL;
   return temp;
}

//traverse


void inordertraversal(struct node *root){
   if (root != NULL){
      inordertraversal(root->left);
      printf("%d ", root->key);
      inordertraversal(root->right);
   }
}

//insertion

struct node* insert(struct node* node, int key){
   if (node == NULL) return newNode(key);
      if (key < node->key)
         node->left = insert(node->left, key);
      else
         node->right = insert(node->right, key);
   return node;
}

//finding min value of tree

struct node * minValueNode(struct node* node){
   struct node* current = node;
   while (current && current->left != NULL)
      current = current->left;
   return current;
}

//deletion

struct node* deleteNode(struct node* root, int key){
   if (root == NULL) return root;
      if (key < root->key)
         root->left = deleteNode(root->left, key);
      else if (key > root->key)
         root->right = deleteNode(root->right, key);
   else{
      if (root->left == NULL){
         struct node *temp = root->right;
         free(root);
         return temp;
      }
      else if (root->right == NULL){
         struct node *temp = root->left;
         free(root);
         return temp;
      }
      struct node* temp = minValueNode(root->right);
      root->key = temp->key;
      root->right = deleteNode(root->right, temp->key);
   }
   return root;
}

//main function

void main(){
   struct node *root = NULL;
   root = insert(root, 50);
   root = insert(root, 30);
   root = insert(root, 20);
   root = insert(root, 40);
   root = insert(root, 70);
   root = insert(root, 60);
   root = insert(root, 80);
   printf("\nInorder traversal of the given tree: ");
   inordertraversal(root);
   printf("\nDelete 20");
   root = deleteNode(root, 20);
   printf("\nInorder traversal of the modified tree: ");
   inordertraversal(root);
   printf("\nDelete 30");
   root = deleteNode(root, 30);
   printf("Inorder traversal of the modified tree: ");
   inordertraversal(root);
   printf("\nDelete 50");
   root = deleteNode(root, 50);
   printf("Inorder traversal of the modified tree: ");
   inordertraversal(root);
}