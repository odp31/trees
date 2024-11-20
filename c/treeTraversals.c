// systematic ways to visit each node in a tree exactly once 
// 3 main types; inorder, preorder, post order

// inorder traversal
// left, root, right 

void inorderTraversal(struct Node* root) {
  if (root != NULL) {
    inorderTraversal(root->left);
    printf("%d ", root-> data);
    inorderTraversal(root->right);
  }
}

// preorder traversal 
// root, left, right

void preorderTraversal(struct Node* root) {
  if (root != NULL) {
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
  }
}

// postorder traversal 
// left, right, root

void postorderTraversal(struct Node* root) {
  if (root != NULL) {
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
  }
}
