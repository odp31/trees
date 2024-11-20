class TreeNode:
  def __init__(self, val = 0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

  def inorder_traversal(root):
    if root:
      inorder_traversal(root.left)
      print(root.val)
      inorder_traveral(root.right)

  def preorder_traverasal(root):
    if root:
      print(root.val)
      preorder_traversal(root.left)
      preorder_traversal(root.right)

  def postorder_traversal(root):
    if root:
      postorder_traversal(root.left)
      postorder_traversal(root.right)
      print(root.val)

# example usage
root = TreeNode(1)
root.left = TreeNode(2)
root.right = TreeNode(3)
root.left.left = TreeNode(4)
root.left.right = TreeNode(5)

print("In order traversal:")
inorder_traversal(root)

print("\n pre order traversal: ")
preorder_traversal(root)

print("\n post order traversal: ")
postorder_traversal(root)
