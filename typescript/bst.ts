class Node<T> {
  value: T;
  left: Node<T> | null;
  right: Node<T> | null;

  constructor(value: T) {
    this.value = value;
    this.left = null;
    this.right = null;
  }
}

class BinarySearchTree<T> {
  root: Node<T> | null;

  constructor() {
    this.root = null;
  }
  insert(value: T): void {
    const newNode = new Node(value);

    if(!this.root) {
      this.root = newNode;
      return;
    }
    let current = this.root;
    let parent: Node<T> | null = null;

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
  search(value: T): Node<T> | null {
    let current = this.root;
    while (current) {
      if (value === current.value) {
        return current;
      } else if (value < current.value) {
        current = current.left;
      } else {
        current = current.right;
      }
    }
    return null;
  }
}
