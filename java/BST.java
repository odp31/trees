// tree data structure where each node has at most 2 children, referred to as left child and right child
// left child's value is always less than parent node value 
// right childs value is always greater

class TreeNode
  {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int val)
    {
      this.val = val;
    }
  }

public class BST
  {
    private TreeNode root; 
    public void insert(int val)
    {
      root = insertRecursive(root, val);
    }
    private TreeNode insertRecursive(TreeNode root, int val)
    {
      if(root == null)
      {
        return new TreeNode(val);
      }
      if(val < root.val)
      {
        root.left = insertRecursive(root.left, val);
      }
      else if(val > root.val)
      {
        root.right = insertRecursive(root.right, val);
      }
      return root;
    }
    public boolean search(int val)
    {
      return searchRecursive(root, val);
    }
    private boolean searchRecursive(TreeNode root, int val)
    {
      if(root == null)
      {
        return false;
      }
      if(root.val == val)
      {
        return true;
      }
      else if(val < root.val)
      {
        return searchRecursive(root.left, val);
      }
      else
      {
        return searchRecursive(root.right, val);
      }
    }
    public void inorderTraversal()
    {
      inorderTraversalRecursive(root);
    }
    private void inorderTraversalRecursive(TreeNode root)
    {
      if (root != null)
      {
        inorderTraversalRecursive(root.left);
        System.out.print(root.val + " ");
        inorderTraversalRecursive(root.right);
      }
    }
    public TreeNode deleteNode(TreeNode root, int key)
    {
      if(root == null)
      {
        return null;
      }
      if (key < root.val)
      {
        root.left = deleteNode(root.left, key);
      }
      else if(key > root.val)
      {
        root.right = deleteNode(root.right, key);
      }
      else
      {
        // node with one or no child
        if (root.left == null)
        {
          return root.right;
        }
        else if(root.right == null)
        {
          return root.left;
        }
        // node with 2 children; get inorder successor (smallest node in right subtree)
        TreeNode temp = minValueNode(root.right);
        root.val = temp.val;
        root.right = deleteNode(root.right, temp.val);
      }
      return root;
    }
    private TreeNode minValueNode(TreeNode node)
    {
      TreeNode current = node;
      while(current.left != null)
        {
          current = current.left;
        }
      return current;
    }
    
  }
