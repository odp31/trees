# BST: tree data structure where each node has at most two children, referred to as left child and right child
# left child's value is always < parent node's value and right child's value is always >

class TreeNode:
  def __init__(self, val=0, left=None, right=None):
    self.val = val
    self.left = left
    self.right = right

class BST:
  def __init__(self):
    self.root = None
    
  def insert(self, val):
    if self.root is None:
      self.root = TreeNode(val)
    else:
      self._insert_recursive(self.root, val)

  def _insert_recursive(self, node, val):
    if val < node.val:
      if node.left is None:
        node.left = TreeNode(val)
      else:
        self._insert_recursive(node.left, val)
    else:
      if node.right is None:
        node.right = TreeNode(val)
      else:
        self._insert_recursive(node.right, val)


  def search(self, val):
    return self._search_recursive(self.root, val)

  def _search_recursive(self, node, val):
    if node is None:
      return False
    if node.val == val:
      return True
    elif val < node.val:
      return self._search_recursive(node.left, val)
    else:
      return self._search_recursive(node.right, val)

  def inorder_traversal(self):
    self._inorder_recursive(self.root)

  def _inorder_recursive(self, node):
    if node:
      self._inorder_recursive(node.left)
      print(node.val, end="")
      self._inorder_recursive(node.right)

# example usage
bst = BST()
bst.insert(50)
bst.insert(30)
bst.insert(70)
bst.insert(20)
bst.insert(40)
bst.insert(60)
bst.insert(80)
print("in order traversal: ")
bst.inorder_traversal()


  
