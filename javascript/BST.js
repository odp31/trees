class BST
  {
    constructor()
    {
      this.root = null;
    }
    insert(value)
    {
      this.root = this._insertRecusrive(this.root, value);
    }
    _insertRecursive(node, value)
    {
      if (node === null)
      {
        node = new Node(value);
      }
      else if(value < node.value)
      {
        node.left = this._insertRecursive(node.left, value);
      }
      else if(value > node.value)
      {
        node.right = this._insertRecursive(node.right, value);
      }
      return node;
    }
    search(value)
    {
      return this._searchRecursive(this.root, value);
    }
    searchRecurisve(node,value)
    {
      if (node === null)
      {
        return false;
      }
      else if (value === node.value)
      {
        return true;
      }
      else if(value < node.value)
      {
        return this._searchRecursive(node.left, value);
      }
      else
      {
        return this._searchRecursive(node.right, value);
      }
    }
    findMin(node)
    {
      if(node === null)
      {
        return null;
      }
      while(node.left !== null)
        {
          node = node.left;
        }
      return node.value;
    }
    findMax(node)
    {
      if(node === null)
      {
        return null;
      }
      while(node.right !== null)
        {
          node = node.right;
        }
      return node.value;
    }
    

