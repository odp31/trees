#include <iostream>
#include <queue>

using namespace std; 

// define structure of a node in binary tree
struct Node {
  int data;
  Node* left;
  Node* right;

  Node(int data) {
    this-> data = data;
    left = nullptr;
    right = nullptr;
  }
};

class BinaryTree {
public:
  Node* root;

  // constructor
  BinaryTree() {
    root = nullptr;
  }

  // function to insert a new node
  void insert(int data) {
    root = insertRecursive(root, data);
  }
  // recursive helper function for insertion
  Node* insertRecursive(Node* root, int data) {
    if(root == nullptr) {
      root = new Node(data);
      return root;
    }
    if(data < root-> data) {
      root->left = insertRecursive(root->left, data);
    } else if (data > root->data) {
      root->right = insertRecursive(root->right, data);
    }
    return root;
  }

  // function to perform inorder traversal
  void inorderTraversal() {
    inorderTraversalRecursive(root);
  }
  // recursive helper function for inorder traversal 
  void inorderTraversalRecursive(Node* root) {
    if (root != nullptr) {
      inorderTraversalRecursive(root->left);
      cout << root->data << " ";
      inorderTraversalRecursive(root->right);
    }
  }

  // function to perform preorder traversal
  void preorderTraversal() {
    preorderTraversalRecursive(root);
  }

  // recursive helper function for preorder traversal
  void preorderTraversalRecursive(Node* root) {
    if(root != nullptr) {
      cout << root->data << " ";
      preorderTraversalRecursive(root->left);
      preorderTraversalRecursive(root->right);
    }
  }

  // function to perform postorder traversal
  void postorderTraversal() {
    postorderTraversalRecursive(root);
  }

  // recursive helper function for postorder traversal
  void postorderTraversalRecursive(Node* root) {
    if(root != nullptr) {
      postorderTraversalRecursive(root->left);
      postorderTraversalRecursive(root->right);
      cout << root-> data << " ";
    }
  }

  // function to perform level order traversal (bfs)
  void levelOrderTraversal() {
    if(root == nullptr) {
      return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
      Node* current = q.front();
      q.pop();
      cout << current->data << " ";

      if(current->left != nullptr) {
        q.push(current->left);
      }
      if(current->right != nullptr) {
        q.push(current->right);
      }
    }
  }


  // function to search for a given value in the tree
  bool search(int data) {
    return searchRecursive(root, data);
  }

  // recursive helper function for searching
  bool searchRecursive(Node* root, int data) {
    if(root == nullptr) {
      return false;
    }
    if(root->data == data) {
      return true;
    }
    if(data < root->data) {
      return searchRecursive(root->left, data);
    } else {
      return searchRecursive(root->right, data);
    }
  }

  // function to find minimum value in tree
  int findMin() {
    if(root == nullptr) {
      return -1;
    }

    Node* current = root;
    while(current->left != nullptr) {
      current = current->left;
    }

    return current->data;
  }

  // function to find maximum value in tree
  int findMax() {
    if(root == nullptr) {
      return -1;
    }

    Node* current = root;
    while(current->right != nullptr) {
      current = current->right;
    }
    return current->data;
  }

  // function to calculat3e height of a tree
  int height() {
    return heightRecursive(root);
  }

  // recursive helper function to calculate height
  int heightRecursive(Node* root) {
    if(root == nullptr) {
      return 0;
    }

    int leftHeight = heightRecursive(root->left);
    int rightHeight = heightRecursive(root->right);

    return 1 + max(leftHeight, rightHeight);
  }
};

int main() {
  BinaryTree tree;

  tree.insert(50);
  tree.insert(30);
  tree.insert(20);
  tree.insert(40);
  tree.insert(70);
  tree.insert(60);
  tree.insert(80);

  cout << "Inorder Traversal: ";
  tree.inorderTraversal();
  cout << endl;

  cout << "preorder traversal: ";
  tree.preorderTraversal();
  cout << endl;

  cout << "postorder traversal: ";
  tree.postorderTraversal();
  cout << endl;

  cout << "level order traversal: ";
  tree.levelOrderTraversal();
  cout << endl;

  cout << "search for 40: " << (tree.search(40) ? "Found" : "Not Found") << endl;
  cout << "search for 100: " << (tree.search(100) ? "Found" : "Not Found") << endl;

  cout << "minimum value: " << tree.findMin() << endl;
  cout << "maximum value: " << tree.findMax() << endl;

  cout << "height of the tree: " << tree.height() << endl;

  return 0;
}
