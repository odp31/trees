class Node
  {
    constructor(data)
    {
      this.data = data;
      this.left = null;
      this.right = null;
    }
  }
// in order traversal
function inorderTraversal(root)
{
  if(root == null)
  {
    return;
  }
  inorderTraversal(root.left);
  console.log(root.data);
  inorderTraversal(root.right);
}

// pre order traversal 
function preorderTraversal(root)
{
  if (root === null)
  {
    return;
  }
  console.log(root.data);
  preorderTraversal(root.left);
  preorderTraversal(root.right);
}

// post order traversal 
function postorderTraversal(root)
{
  if(root === null)
  {
    return; 
  }
  postorderTraversal(root.left);
  postorderTraversal(root.right);
  console.log(root.data);
}

// example usage 
const root = new Node(1);
root.left = new Node(2);
root.right = new Node(3);
root.left.left = new Node(4);
root.left.right = new Node(5);


inorderTraversal(root); // output; 4 2 5 1 3 
preorderTraversal(root); // output; 1 2 4 5 3 
postorderTraversal(root); // output; 4 5 2 3 1 
