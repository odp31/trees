// each node as at most two children 

public class BinaryTree {
  public class Node {
    int data;
    Node left, right;

    public Node(int item) {
      data = item;
      left = right = null;
    }
  }
  Node root;
  public BinaryTree() {
    root = null;
  }
  // function to insert new node with given key
  public void insert(int key) {
    root = insertRec(root, key);
  }
  // recursive function to insert a new node with key in BST
  Node insertRec(Node root, int key) {
    // if tree is empty, return new node
    if(root == null) {
      root = new Node(key);
      return root;
    }
    // otherwise, recur down tree
    if(key < root.data)
      root.left = insertRec(root.left, key);
    else if(key > root.data)
      root.right = insertRec(root.right, key);
    return root;
  }
  // utility function to print inorder traversal
  public void inorder() {
    inorderRec(root);
  }
  // utility function to do inorder traversal of the tree
  void inorderRec(Node root) {
    if(root != null) {
      inorderRec(root.left);
      System.out.println(root.data + " ");
      inorderRec(root.right);
    }
  }
}
