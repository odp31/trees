# Prims; greedy algoritm that finds min spanning tree for a weighted, undirected graph 
# starts from a source vertex and gradually builds MST by adding edges with minimum weight 

import heapq
def primMST(graph):
  V = len(graph)
  key = [float('inf')] * V
  parent = [None] * V
  key[0] = 0
  pq = [(0, 0)] # (weight, vertex)

  while pq:
    weight, u = heapq.heappop(pq)
    for v, w in enumerate(graph[u]):
      if w > 0 and key[v] > w:
        key[v] = w
        parent[v] = u
        heapq.heappush(pq, (w, v))

  mst = []
  for v in range(1, V):
    mst.append((parent[v], v, key[v]))
  return mst 


# Kruskals algorithm: greedy algorithm that finds minimum spanning tree for a weighted, undirected graph
# sorts all edges in increasing order of their weight and picks the smallest weight edge from this sorted edge and adds it to the MST
# as long as it doesn't create a cycle 

class Graph:
  def __init__(self, vertices):
    self.V = vertices
    self.graph = []

  def add_edge(self, u, v, w):
    self.graph.append([u,v,w])

  def find_parent(self, parent, i):
    if parent[i] == i:
      return i 
    return self.find_parent(parent, parent[i])

  def union_find(self, parent, rank, x, y):
    xroot = self.find_parent(parent, x)
    yroot = self.find_parent(parent, y)

    if rank[xroot] < rank[yroot]:
      parent[xroot]  = yroot
    elif rank[xroot] > rank[yroot]:
      parent[yroot] = xroot
    else:
      parent[yroot] = xroot
      rank[xroot] += 1

  def KruskalMST(self):
    result = []
    i = 0
    e = 0

    self.graph = sorted(self.graph, key=lambda, item: item[2])

    parent = [i for i in range(self.V)]
    rank = [0] * self.V
    while e < self.V - 1:
      u, v, w = self.graph[i]
      i += 1
      x = self.find_parent(parent, u)
      y = self.find_parent(parent, v)
      if x != y:
        e += 1
        result.append([u, v, w])
        self.union_find(parent, rank, x, y)
    return result 
