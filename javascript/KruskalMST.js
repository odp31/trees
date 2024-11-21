class Graph
  {
    constructor(vertices)
    {
      this.V = vertices;
      this.graph = [];
    }
    addEdge(u, v, w)
    {
      this.graph.push([u, v, w]);
    }
    findParent(parent, i)
    {
      if(parent[i] == -1)
        return i;
      return this.findParent(parent, parent[i]);
    }
    union(parent, x, y)
    {
      let xset = this.findParent(parent, x);
      let yset = this.findParent(parent, y);
      if (xset != yset)
        parent[xset] = yset;
    }
    KruskalMST()
    {
      // sort edges by weight
      this.graph.sort((a, b) => a[2] - b[2]);
      // create parent array to keep track of subsets
      let parent = new Array(this.V);
      for(let i = 0; i < this.V; i++)
        parent[i] = -1;
      let result = [];
      let edge_count = 0;
      let i = 0; 

      while(edge_count < this.V - 1)
        {
          let u = this.graph[i][0];
          let v = this.graph[i][1];
          let w = this.graph[i][2];
          i++;

          let x = this.findParent(parent, u);
          let y = this.findParent(parent, v);

          if( x!= y)
          {
            result.push([u, v, w]);
            edge_count++;
            this.union(parent, x, y);
          }
        }
      // print constructed MST
      console.log("following are the edges in the constructed MST");
      for(let i = 0; i < result.length; i++)
        {
          console.log(result[i][0] + " -- " + result[i][1] + " == " + result[i][2]);
        }
    }
  }
// example usage
let g = new Graph(5);
g.addEdge(0, 1, 2);
g.addEdge(0, 3, 6);
g.addEdge(1, 2, 3);
g.addEdge(1, 3, 8);
g.addEdge(1, 4, 5);
g.addEdge(2, 4, 7);
g.KruskalMST();
          
