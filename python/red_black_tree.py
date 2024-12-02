class Node:
  def __init__(self, data):
    self.data = data
    self.left = None
    self.right = None
    self.color = True 


class RedBlackTree:
  def __init__(self):
    self.root = None

  def insert(self, data):
    self.root = self._insert(self.root, data)
    self.root.color = False # root node is always black

  def insert(self, node, data):
    if node is None:
      return Node(data)

    if data < node.data:
      node.left = self._insert(node.left, data)
    elif data > node.data:
      node.right = self._insert(node.right, data)

    return self.balance(node)

  def balance(self, node):
    # left left case
    if self.isRed(node.left) and self.isRed(node.left.left):
      return self.rightRotate(node)

    # right right case
    if self.isRed(node.right) and self.isRed(node.right.right):
      return self.leftRotate(node)

    # left right case
    if self.isRed(node.left) and self.isRed(node.right):
      self.flipColors(node)

    return node

  def leftRotate(self, x):
    y = x.right
    x.right = y.left
    y.left = x
    y.color = x.color
    x.color = True
    return y


  def rightRotate(self, x):
    y = x.left
    x.left = y.right
    y.right = x
    y.color = x.color
    x.color = True
    return y


  def flipColors(self, node):
    node.color = not node.color
    node.left.color = not node.left.color
    node.right.color = not node.right.color 

  def isRed(self, node):
    if node is None:
      return False
    return node.color 
