#include <iostream>
#include <memory>


enum class Color { RED, BLACK };

struct Node {
  int data;
  Color color;
  std::unique_ptr<Node> left;
  std::unique_ptr<Node> right;
  Node* parent;

  Node(int value) : data(value), color(Color::RED), left(nullptr), right(nullptr), parent(nullptr) {}
};

class RedBlackTree {
private:
  std::unique_ptr<Node> root;

  // helper functions
  void rotateLeft(Node* node);
  void rotateRight(Node* node);

  void fixInsert(Node* node);
  void fixDelete(Node* node);
  void inorderRecursive(const std::unique_ptr<Node>& node);
  Node* findMin(Node* node);
  Node* findSuccessor(Node* node);
  void transplant(Node* u, Node* v);

public:
  RedBlackTree() : root(nullptr) {}
  void insert(int data);
  void remove(int data);
  void inorder();
  bool search(int data);
};

void RedBlackTree::rotateLeft(Node* node) {
  Node* rightChild = node->right.get();
  node->right = std::move(rightChild->left);
  if(node->right) {
    node->right->parent = node;
  }
  rightChild->parent = node->parent;
  if(!node->parent) {
    root.reset(rightChild);
  } else if(node == node->parent->left.get()) {
    node->parent->left.reset(rightChild);
  } else {
    node->parent->right.reset(rightChild);
  }
  rightChild->left.reset(node);
  node->parent = rightChild;
}

void RedBlackTree::rotateRight(Node* node) {
  Node* leftChild = node->left.get();
  node->left = std::move(leftChild->right);
  if(node->left) {
    node->left->parent = node;
  }
  leftChild->parent = node->parent;
  if(!node->parent) {
    root.reset(leftChild);
  } else if(node == node->parent->left.get()) {
    node->parent->left.reset(leftChild);
  } else {
    node->parent->right.reset(leftChild);
  }
  leftChild->right.reset(node);
  node->parent = leftChild;
}

void RedBlackTree::fixInsert(Node* node) {
  while(node->parent && node->parent->color == Color::RED) {
    if(node->parent == node->parent->parent->left.get()) {
      Node* uncle = node->parent->parent->right.get();
      if(uncle && uncle->color == Color::RED) {
        node->parent->color = Color::BLACK;
        uncle->color = Color::BLACK;
        node->parent->parent->color = Color::RED;
        node = node->parent->parent;
      } else {
        if(node == node->parent->right.get()) {
          node = node->parent;
          rotateLeft(node);
        }
        node->parent->color = Color::BLACK;
        node->parent->parent->color = Color:RED;
        rotateRight(node->parent->parent);
      }
    } else {
        Node* uncle = node->parent->parent->left.get();
        if(uncle && uncle->color == Color::RED) {
          node->parent->color = Color::BLACK;
          uncle->color = Color::BLACK;
          node->parent->parent->color = Color::RED;
          node = node->parent->parent;
        } else {
          if(node == node->parent->left.get()) {
            node = node->parent;
            rotateRight(node);
          }
          node->parent->color = Color::BLACK;
          node->parent->parent->color = Color::RED;
          rotateLeft(node->parent->parent);
        }
    }
  }
  root->color = Color::BLACK;
}

void RedBlackTree::inorder() {
    inorderRecursive(root);
    std::cout << std::endl;
}

void RedBlackTree::inorderRecursive(const std::unique_ptr<Node>& node) {
    if (node) {
        inorderRecursive(node->left);
        std::cout << node->data << " ";
        inorderRecursive(node->right);
    }
}

bool RedBlackTree::search(int data) {
  Node* current = root.get();
  while(current){
    if(data == current->data) return true;
    else if(data < current->data) current = current->left.get();
    else current = current->right.get();
  }
  return false;
}

Node* RedBlackTree::findMin(Node* node) {
    while (node->left) {
        node = node->left.get();
    }
    return node;
}

Node* RedBlackTree::findSuccessor(Node* node) {
    if (node->right) {
        return findMin(node->right.get());
    }
    Node* parent = node->parent;
    while (parent && node == parent->right.get()) {
        node = parent;
        parent = parent->parent;
    }
    return parent;
}

void RedBlackTree::transplant(Node* u, Node* v) {
    if (!u->parent) {
        root.reset(v);
    } else if (u == u->parent->left.get()) {
        u->parent->left.reset(v);
    } else {
        u->parent->right.reset(v);
    }
    if (v) {
        v->parent = u->parent;
    }
}

void RedBlackTree::remove(int data) {
    Node* z = root.get();
    while (z && z->data != data) {
        if (data < z->data) {
            z = z->left.get();
        } else {
            z = z->right.get();
        }
    }

    if (!z) return; // Node not found

    Node* y = z;
    Color yOriginalColor = y->color;
    Node* x;

    if (!z->left) {
        x = z->right.get();
        transplant(z, z->right.get());
    } else if (!z->right) {
        x = z->left.get();
        transplant(z, z->left.get());
    } else {
        y = findSuccessor(z);
        yOriginalColor = y->color;
        x = y->right.get();
        if (y->parent == z) {
            if(x)x->parent = y;
        } else {
            transplant(y, y->right.get());
            y->right = std::move(z->right);
            if(y->right)y->right->parent = y;
        }
        transplant(z, y);
        y->left = std::move(z->left);
        y->left->parent = y;
        y->color = z->color;
    }
    if (yOriginalColor == Color::BLACK && x) fixDelete(x);
}

void RedBlackTree::fixDelete(Node* x) {
    while (x != root.get() && (x == nullptr || x->color == Color::BLACK)) {
        if (x == x->parent->left.get()) {
            Node* w
        }
    }
}
}

