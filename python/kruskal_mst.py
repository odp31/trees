# time complexity - O(E log V) - e = edges, v = vertices 

def kruskal_mst(graph):
  mst = set()
  parent = [i for i in range(len(graph))]
  rank = [0] * len(graph)

  def find_parent(node):
    parent[node] = find_parent(parent[node])
    return parent[node]

  def union(u, v):
    pu, pv = find_parent(u), find_parent(v)
    if rank[pu] < rank[pv]:
      parent[pu] = pv
    elif rank[pu] > rank[pv]:
      parent[pv] = pu
    else:
      parent[pv] = pu
      rank[pu] += 1

  edges = []
  for u in graph:
    for v, w in graph[u]:
      edges.append((w, u, v))

  edges.sort()

  for weight, u, v in edges:
    if find_parent(u) != find_parent(v):
      mst.add((u,v))
      union(u,v)

  return mst 
