#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int data;
  struct Node *left, *right;
  bool color;     // 1 for red, 0 for black 
} Node;

Node* newNode(int data) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->data = data;
  node->left = node->right = NULL;
  node->color = 1;     // red
  return node;
}

Node* rightRotate(Node* x) {
  Node* y = x->left;
  x->left = y->right;
  y->right = x;
  y->color = x->color;
  x->color = 1;
  return y;
}

Node* leftRotate(Node* x) {
  Node* y = x->right;
  x->right = y->left;
  y->left = x;
  y->color = x->color;
  x->color = 1;
  return y;
}

Node* insert(Node* node, int data)
{
  if(node == NULL) {
    return newNode(data);
  }
  if(data < node->data) {
    node->left = insert(node->left, data);
  }
  else if(data > node->data) {
    node->right = insert(node->right, data);
  }
  else {
  }
  return fixUp(node);
}
void inorderTraversal(Node* root)
{
  if(root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
  }
}
int main()
{
  Node* root = NULL:
  root = insert(root, 10);
  insert(root, 20); 
  insert(root, 30);
  insert(root, 40);
  insert(root, 50);
  inorderTraversal(root);

  return 0;
}
