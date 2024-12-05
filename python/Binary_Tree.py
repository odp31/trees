class Node:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None

class BinaryTree:
  def __init__(self):
    self.root = None

  def insert(self, data):
    self.root = self._insert_recursive(self.root, data)

  def _insert_recursive(self, root, data):
    if root is None:
      return Node(data)
    else:
      if data < root.data:
        root.left = self._insert_recursive(root.left, data)
      else:
        root.right = self._insert_recursive(root.right, data)
    return root

  def inorder_traversal(self):
    self._inorder_recursive(self.root)

  def _inorder_recursive(self, root):
    if root:
      self._inorder_recursive(root.left)
      print(root.data, end= " ")
      self._inorder_recursive(root.right)


# example usage
tree = BinaryTree()
tree.insert(50)
tree.insert(30)
tree.insert(70)
tree.insert(20)
tree.insert(40)
tree.insert(60)
tree.insert(80)

tree.inorder_traveral()    #output; 20 30 40 50 60 70 80
