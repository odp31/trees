#include <iostream>
#include <memory>


//node structure for bst
struct Node {
  int data;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;

  Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BST {
private:
  std::unique_ptr<Node> root;

  //helper functions (recursive)
  std::unique_ptr<Node> insertRecursive(std::unique_ptr<Node> node, int value);
  void inorderRecursive(const std::unique_ptr<Node>& node);
  void preorderRecursive(const std::unique_ptr<Node>& node);
  void postorderRecursive(const std::unique_ptr<Node>& node);
  std::unique_ptr<Node> searchRecursive(const std::unique_ptr<Node>& node,int value);
  std::unique_ptr<Node> findMin(std::unique_ptr<Node> node);
  std::unique_ptr<Node> deleteRecursive(std::unique_ptr<Node> node, int value);

  void freeTree(std::unique_ptr<Node> node);


public:
  BST() : root(nullptr) {}

  // public interface
  void insert(int value);
  void inorder();
  void preorder();
  void postorder();
  bool search(int value);
  void remove(int value);
};

void BST::insert(int value) {
  root = insertRecursive(std::move(root), value);
}

std::unique_ptr<Node> BST::insertRecursive(std::unique_ptr<Node> node, int value) {
  if(!node) {
    return std::make_unique<Node>(value);
  }
  if(value < node->data) {
    node->left = insertRecursive(std::move(node->left), value);
  } else if (value > node->data) {
    node->right = insertRecursive(std::move(node->right),value);
  }
  return node;
}

void BST::inorder() {
  inorderRecursive(root);
  std::cout << std::endl;
}

void BST::inorderRecursive(const std::unique_ptr<Node>& node) {
  if(node) {
    inorderRecursive(node->left);
    std::cout<< node->data << " ";
    inorderRecursive(node->right);
  }
}
void BST::preorder() {
  preorderRecursive(root);
  std::cout << std::endl;
}

void BST::preorderRecursive(const std::unique_ptr<Node>& node) {
  if(node) {
    std::cout << node->data << " ";
    preorderRecursive(node->left);
    preorderRecursive(node->right);
  }
}

void BST::postOrder() {
  postorderRecursive(root);
  std::cout << std::endl;
}

void BST::postorderRecursive(const std::unique_ptr<Node>& node) {
  if(node) {
    postorderRecursive(node->left);
    postorderRecursive(node->right);
    std::cout << node->data << " ";
  }
}

bool BST::search(int value) {
  return searchRecursive(root, value) != nullptr;
}

std::unique_ptr<Node> BST::searchRecursive(const std::unique_ptr<Node> & node, int value) {
  if(!node) {
    return nullptr;
  }
  if(value == node->data) {
    return node;
  } else if(value < node->data) {
    return searchRecursive(node->left, value);
  } else {
    return searchRecursive(node->right, value);
  }
}

void BST::remove(int value) {
  root = deleteRecursive(std::move(root), value);
}


std::unique_ptr<Node> BST::deleteRecursive(std::unique_ptr<Node> node, int value) {
  if(!node) {
    return nullptr;
  }
  if(value < node->data){
    node->left = deleteRecursive(std::move(node->left), value);
  } else if (value > node->data) {
    node->right = deleteRecursive(std::move(node->right, value);
  } else {
    if(!node->left) {
      return std::move(node->right);
    } else if(!node->right) {
      return std::move(node->left);
    }
    // node with 2 children, get inorder successor
    std::unique_ptr<Node> minNode = findMin(std::move(node->right));
    node->data = minNode->data;
    node->right = deleteRecursive(std::move(node->right), minNode->data);
  }
  return node;
}

std::unique_ptr<Node> BST::findMin(std::unique_ptr<Node> node){
  while(node->left) {
    node = std::move(node->left);
  }
  return node;
}


int main() {
  BST bst;

  bst.insert(50);
  bst.insert(30);
  bst.insert(20);  
  bst.insert(40);
  bst.insert(70);
  bst.insert(60);
  bst.insert(80);

  std::cout << "inorder traversal: ";
  bst.inorder();

  std::cout << "preorder traversal:";
  bst.preorder();

  std::cout << "postorder traversal";
  bst.postorder();

  std::cout << "search for 40: " << (bst.search(40) ? "Found" : "Not Found") << std::endl;
  std::cout << "search for 90: " << (bst.search(90) ? "Found" : "Not Found") << std::endl;

  bst.remove(30);
  std::cout << "inorder after removing 30: ";
  bst.inorder();

  return 0;
}
