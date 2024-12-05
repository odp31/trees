#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left, *right;
};

// function to create new node
struct Node* newNode(int data) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
  return node;
}
// function to insert a new node
void insert(struct Node** root, int data) {
  if(*root == NULL) {
    *root = newNode(data);
    return;
  }
  if(data < (*root)->data) {
    insert(&(*root)->right, data);
  }
}
// function to perform inorder traversal 
void inorderTraversal(struct Node* root) {
  if(root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}

// function to perform preorder traversal
void preorderTraversal(struct Node* root) {
  if(root != NULL) {
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}
// function to perform postorder traversal
void postorderTraversal(struct Node* root) {
  if(root != NULL) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
  }
}

int main() {
  struct Node* root = NULL;
  insert(&root, 50);
  insert(&root, 30);
  insert(&root, 20);
  insert(&root, 40);
  insert(&root, 70);
  insert(&root, 60);
  insert(&root, 80);


  printf("inorder traversal: ");
  inorderTraversal(root);
  printf("\n");

  printf("preorder traversal: ");
  preorderTraversal(root);
  printf("\n");

  printf("postorder traversal: ");
  postorderTraversal(root);
  printf("\n");

  return 0;
}
