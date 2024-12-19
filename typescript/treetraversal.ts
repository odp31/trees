interface TreeNode<T> {
  value: T;
  left: TreeNode<T> | null;
  right: TreeNode<T> | null;
}

class TreeTraversal<T> {
  private root: TreeNode<T> | null;
  constructor(root: TreeNode<T> | null) {
    this.root = root;
  }

  public inorderTraversal(node: TreeNode<T> | null = this.root): void {
    if (node) {
      this.inorderTraversal(node.left);
      console.log(node.value);
      this.inorderTraversal(node.right);
    }
  }

  public preorderTraversal(node: TreeNode<T> | null = this.root): void {
    if (node) {
      console.log(node.value);
      this.preorderTraversal(node.left);
      this.preorderTraversal(node.right);
    }
  }

  public postorderTraversal(node: TreeNode<T> | null = this.root): void {
    if(node) {
      this.postorderTraversal(node.left);
      this.postorderTraversal(node.right);
      console.log(node.value);
    }
  }
}

// example usage
const root: TreeNode<number> = {
  value: 1, 
  left: {
    value: 2, 
    left: null,
    right: null
  }, 
  right: {
    value: 3, 
    left: null, 
    right: null
  }
};

const traversal = new TreeTraversal(root);
console.log("inorder traversal");
traversal.inorderTraversal();

console.log("preorder traversal");
traversal.preorderTraversal();

console.log("postorder traversal");
traversal.postorderTraversal(); 
