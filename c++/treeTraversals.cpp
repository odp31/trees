#include <iostream>
#include <stack>
#include <queue>
#include <memory>

struct Node {
  int data;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;

  Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class TreeTraversal {
private:
  std::unique_ptr<Node> root;

public:
  TreeTraveral() : root(nullptr) {}

  // function to set root of tree
  void setRoot(std::unique_ptr<Node> rootNode) {
    root = std::move(rootNode);
  }
  // recursive traversals
  void inorderRecursive(const std::unique_ptr<Node> & node) {
    if(node) {
      inorderRecursive(node->left);
      std::cout << node->data << " ";
      inorderRecursive(node->right);
    }
  }
  void preorderTraversal(const std::unique_ptr<Node>& node) {
    if(node){
      std::cout << node->data << " ";
      preorderRecursive(node->left);
      preorderRecursive(node->right);
    }
  }
  void postorderRecursive(const std::unique_ptr<Node>& node) {
    if(node) {
      postorderRecursive(node->left);
      postorderRecursive(node->right);
      std::cout << node->data << " ";
    }
  }
  int main() {
    TreeTraversal tree;

    std::unique_ptr<Node> root = std::make_unique<Node>(1);
    root->left = std::make_unique<Node>(2);
    root->right = std::make_unique<Node>(3);
    root->left->left = std::make_unique<Node>(4);
    root->left->right = std:make_unique<Node>(5);

    tree.setRoot(std::move(root));

    tree.inorderRecursive();
    tree.preorderRecursive();


    return 0;
  }

