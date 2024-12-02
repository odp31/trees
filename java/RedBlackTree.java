public class RedBlackTree<T extends Comparable<T>>
  {
    private Node<T> root;
    private static class Node<T> {
      T data;
      Node<T> left, right;
      boolean color;

      Node(T data) {
        this.data = data;
        this.color = true;
      }
    }
    public void insert(T data)
    {
      root = insert(root, data);
      root.color = false;
    }
    private Node<T> insert(Node<T> node, T data) {
      if(node == null) {
        return new Node<>(data);
      }
      if(data.compareTo(node.data) < 0) {
        node.left = insert(node.left, data);
      }
      else if(data.compareTo(node.data) > 0) {
        node.right = insert(node.right, data);
      }
      else {
      }
      return balance(node);
    }
    private Node<T> balance(Node<T> node)
    {
      if(isRed(node.right) && !isRed(node.left)) {
        node = rotateLeft(node);
      }
      if(isRed(node.left) && isRed(node.left.left)) {
        node = rotateRight(node);
      }
      if(isRed(node.left) && isRed(node.right)) {
        flipColors(node);
      }
      return node;
    }
    private Node<T> rotateLeft(Node<T> x) {
      Node<T> y = x.right;
      x.right = y.left;
      y.left = x;
      y.color = x.color;
      x.color = true;
      return y;
    }
    private Node<T> rotateRight(Node<T> x) {
      Node<T> y = x.left;
      x.left = y.right;
      y.right = x;
      y.color = x.color;
      x.color = true;
      return y;
    }
    private void flipColors(Node<T> node)
    {
      node.color = !node.color;
      node.left.color = !node.left.color;
      node.right.color = !node.right.color;
    }
    private boolean isRed(Node<T> x) {
      if(x == null) {
        return false;
      }
      return x.color;
    }
  }
