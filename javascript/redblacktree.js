class Node {
  constructor(key) {
    this.key = key;
    this.left = null;
    this.right = null;
    this.color = 'RED';
  }
}
class RedBlackTree {
  constructor() {
    this.root = null;
  }
  // helper function to rotate a node to the left
  leftRotate(node) {
    const rightChild = node.right;
    node.right = rightChild.left;
    rightChild.left = node;
    rightChild.color = node.color;
    node.color = 'RED';
    return rightChild;
  }
  // helper function to rotate node to right
  rightRotate(node) {
    const leftChild = node.left;
    node.left = leftChild.right;
    leftChild.right = node;
    leftChild.color = node.color;
    node.color = 'RED';
    return leftChild;
  }
  // helper function to fix tree after insertion
  fixUp(node) {
    while(node !== this.root && node.color === 'RED' && node.parent.color=== 'RED') {
      const parent = node.parent;
      const grandparent = parent.parent;
      // case 1; parent is left child of grandparent
      if(parent === grandparent.left) {
        const uncle = grandparent.right;

        // case 1a; parent is left child of grandparent
        if(parent === grandparent.left) {
          const uncle = grandparent.right;

        if(uncle && uncle.color === 'RED') {
          parent.color = 'BLACK';
          uncle.color = 'BLACK';
          grandparent.color = 'RED';
          node = grandparent;
        }
          else {
            if(node === parent.right) {
              node = parent;
              this.leftRotate(node);
            }
            parent.color = 'BLACK';
            grandparent.color = 'RED';
            this.rightRotate(grandparent);
          }
        } else {
        }
      }
      this.root.color = 'BLACK';
    }
    insert(key) {
      const newNode = new Node(key);
      if(this.root === null) {
        this.root = newNode;
      } else {
        let current = this.root;
        let parent = null;
        while(current) {
          parent = current;
          if (key < current.key) {
            current = current.left;
          }
          else if (key > current.key) {
            current = current.right;
          }
          else {
            return;
          }
        }
        newNode.parent = parent;
        if(key < parent.key) {
          parent.left = newNode;
        } else {
          parent.right = newNode;
        }
      }
      this.fixUp(newNode);
    }
  }
