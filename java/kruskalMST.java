public static void kruskalMST(int graph[][], int V)
  {
  // create a PQ to store edges
  PriorityQueue<Edge> pq = new PriorityQueue<>(V, Comparator.comparingInt(o -> o.weight));
  // add all edges to pq
  for(int i = 0; i < V; i++) {
    for(int j = 0; j < V; j++) {
      if (graph[i][j] != 0) {
        pq.add(new Edge(i, j, graph[i][j]));
      }
    }
  }
  // create parent array to keep track of subsets 
  int parent[] = new int[V];
  for (int i = 0; i < V; i++) {
    parent[i] = i;
  }
  // create a disjoint set data structure
  DisjointSet ds = new DisjointSet(V);
  // num edges to be taken is equal to v - 1
  int edgeCount = 0;
  while(!pq.isEmpty() && edgeCount < V - 1) {
    Edge edge = pq.poll();
    // check if adding this edge creates a cycle
    int x = ds.findParent(edge.src);
    int y = ds.findParent(edge.dest);

    if(x != y) {
      edgeCount++;
      System.out.println(edge.src + " - - " + edge.dest + " == " + edge.weight);
      ds.union(x,y);
    }
  }
}

// a class to represent a graph edge
static class Edge{
  int src, dest, weight;

  public Edge(int src, int dest, int weight) {
    this.src = src;
    this.dest = dest;
    this.weight = weight;
  }
}

// a class to represent a disjoint set data structure 
static class DisjointSet {
  int[] parent, rank;
  int n;
  public DisjointSet(int n) {
    this.n = n;
    parent = new int[n];
    rank = new int[n];

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      rank[i] = 0;
    }
  }
  // find parent of a node using path compression
  int findParent(int x) {
    if (parent[x] == x) {
      return x;
    }
    return parent[x] = findParent(parent[x]);
  }
  // union of 2 sets using rank by size
  void union(int x, int y)
  {
    int xRoot = findParent(x);
    int yRoot = findParent(y);
    if(rank[xRoot] < rank[yRoot]){
      parent[xRoot] = yRoot;
    }
    else if (rank[yRoot] < rank[xRoot])
    {
      parent[yRoot] = xRoot;
    }
    else
    {
      parent[yRoot] = xRoot;
      rank[xRoot]++;
    }
  }
}
