#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node *left, *right;
};

struct Node* newNode(int item) {
  struct Node* node = (struct Node*)malloc(sizeof(struct Node));
  node -> data = item;
  node -> left = node -> right = NULL;
  return node;
}

void inorderTraversal(struct Node* root) {
  if(root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root-> data);
    inorderTraversal(root->right);
  }
}

struct Node* insert(struct Node* node, int key)
{
  if(node == NULL)
    return newNode(key);
  if(key < node->data)
    node->left = insert(node->left, key);
  else
    node->right = insert(node->right, key);
  return node;
}

// function to search a given key in BST
// base cases- root is null or key is present at root 
struct Node* search(struct Node* root, int key) {
  if (root == NULL | | root -> data == key)
    return root;
  if(key > root->data)
    return search(root->right, key);
  else
    return search(root->left, key);
}

int main (){
  struct Node* root = NULL;
  root = insert(root, 50);
  insert(root, 30);
  insert(root, 20);
  insert(root, 40);
  insert(root, 70);
  insert(root, 60);
  insert(root, 80); 

  printf("inorder traversal of tree: ");
  inorderTraversal(root);

  int key = 40;
  struct Node* foundNode = search(root, key);
  if(foundNode != NULL) {
    printf("\n%d found in the tree\n", key);
  }
  else {
    printf("\n%d not found in the tree\n", key);
  }
return 0;
}
