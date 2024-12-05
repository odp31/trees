class Node {
  constructor(data) {
    this.data = data;
    this.left = null;
    this.right = null;
  }
}

class BinaryTree {
  constructor() {
    this.root = null;
  }
  insert(data) {
    this.root = this._insertRecursive(this.root, data);
  }
  _insertRecursive(root, data) {
    if(root === null) {
      root = new Node(data);
      return root;
    } else if(data < root.data) {
      root.left = this._insertRecursive(root.left, data);
    } else if(data > root.data) {
      root.right = this._insertRecursive(root.right, data);
    }
    return root;
  }
  inorderTraversal() {
    this._inorderRecursive(this.root);
  }
  _inorderRecursive(root) {
    if(root !== null) {
      this._inorderRecursive(root.left);
      console.log(root.data);
      this._inorderRecursive(root.right);
    }
  }
}
// example usage
const tree = new BinaryTree();
tree.insert(50);
tree.insert(30);
tree.insert(70);
tree.insert(20);
tree.insert(40);
tree.insert(60);
treen.insert(80);

tree.inorderTraversal();       //output; 20 30 40 50 60 70 80
