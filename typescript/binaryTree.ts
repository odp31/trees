class BinaryTreeNode<T> {
  value: T;
  left: BinaryTreeNode<T> | null;
  right: BinaryTreeNode<T> | null;

  constructor(value: T) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

class BinaryTree<T> {
  root: BinaryTreeNode<T> | null;

  constructor() {
    this.root = null;
  }
  insert(value: T): void {
    const newNode = new BinaryTreeNode(value);
    if(!this.root) {
      this.root = newNode;
      return;
    }
    let current = this.root;
    let parent: BinaryTreeNode<T> | null = null;

    while(current) {
      parent = current;
      if(value < current.value) {
        current = current.left;
      } else {
        current = current.right;
      }
    }
    if(value < parent!.value) {
      parent!.left = newNode;
    } else {
      parent!.right = newNode;
    }
  }
}
