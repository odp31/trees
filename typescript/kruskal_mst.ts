interface Edge {
  src: number;
  dest: number;
  weight: number;
}

class DisjointSet {
  parent: number[];
  rank: number[];

  constructor(n: number) {
    this.parent = new Array(n);
    this.rank = new Array(n);

    for(let i = 0; i < n; i++) {
      this.parent[i] = i;
      this.rank[i] = 0;
    }
  }
  findParent(x: number): number {
    if (this.parent[x] == x) {
      return x;
    }
    return this.parent[x] = this.findParent(this.parent[x]);
  }
  union(x: number, y: number): void {
    x = this.findParent(x);
    y = this.findParent(y);

    if(this.rank[x] < this.rank[y]) {
      this.parent[x] = y;
    } else if (this.rank[x] > this.rank[y]) {
      this.parent[y] = x;
    } else {
      this.parent[y] = x;
      this.rank[x]++;
    }
  }
}
function kruskalMST(edges: Edge[]): number {
  edges.sort((a, b) => a.weight - b.weight);
  const n = edges.length;
  const ds = new DisjointSet(n);
  let mstCost = 0;

  for(const edge of edges) {
    const x = edge.src;
    const y = edge.dest;
    const weight = edge.weight;

    if(ds.findParent(x) !== ds.findParent(y)) {
      mstCost += weight;
      ds.union(x, y);
    }
  }
  return mstCost;
}
