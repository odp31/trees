enum Color {
  RED,
  BLACK
}

class Node<T> {
  value: T;
  color: Color;
  left: Node<T> | null;
  right: Node<T> | null;
  parent: Node<T> | null;

  constructor(value: T) {
    this.value = value;
    this.color = Color.RED;
    this.left = null;
    this.right = null;
    this.parent = null;
  }
}

class RedBlackTree<T> {
  root: Node<T> | null;

  constructor() {
    this.root = null;
  }

  private rotateLeft(x: Node<T>): void {
    const y = x.right!;
    x.right = y.left;
    if(y.left) {
      y.left.parent = x;
    }
    y.parent = x.parent;
    if(!x.parent) {
      this.root = y;
    } else if (x === x.parent.left) {
      x.parent.left = y;
    } else {
      x.parent.right = y;
    }
    y.left = x;
    x.parent = y;
  }

  private rotateRight(x: Node<T>): void {
    const y = x.left!;
    x.left = y.right;
    if(y.right) {
      y.right.parent = x;
    }
    y.parent = x.parent;
    if(!x.parent) {
      this.root = y;
    } else if (x === x.parent.right) {
      x.parent.right = y;
    } else {
      x.parent.left = y;
    }
    y.right = x;
    x.parent = y;
  }

  private fixUp(x: Node<T>): void {
    while(x && x.parent && x.parent.color === Color.RED) {
      const uncle = x.parent.parent!.left === x.parent ? x.parent.parent!.right : x.parent.parent!.left;

      if(uncle && uncle.color === Color.RED) {
        x.parent.color = Color.BLACK;
        uncle.color = Color.BLACK;
        x.parent.parent!.color = Color.RED;
        x = x.parent.parent!;
      } else {
        if(x === x.parent.right) {
          x = x.parent;
          this.rotateLeft(x);
        }
        x.parent!.color = Color.BLACK;
        x.parent.parent!.color = Color.RED;
        this.rotateRight(x.parent.parent!);
      }
    }
    this.root!.color = Color.BLACK;
  }

  insert(value: T): void {
    const newNode = new Node(value);
    if(!this.root) {
      this.root = newNode;
    } else {
      let current = this.root;
      while (true) {
        if(value < current.value) {
          if(!current.left) {
            current.left = newNode;
            newNode.parent = current;
            break;
          } else {
            current = current.left;
          }
        } else {
          if(!current.right) {
            current.right = newNode;
            newNode.parent = current;
            break;
          } else {
            current = current.right;
          }
        }
      }
      this.fixUp(newNode);
    }
  }
}
