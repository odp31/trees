import heapq

def prims_algorithm(graph):

  mst = []
  visited = set()
  pq = [(0,0)] # (weight, vertex)

  while pq:
    weight, vertex = heapq.heappop(pq)

    if vertex in visited:
      continue

    visited.add(vertex)
    for neighbor, edge_weight in graph[vertex]:
      if neighbor not in visited:
        heapq.heappush(pq, (edge_weight, neighbor))
        mst.append((vertex, neighbor, edge_weight))

  return mst 

# Example usage:
graph = {
    0: [(1, 2), (3, 6)],
    1: [(0, 2), (2, 3), (4, 5)],
    2: [(1, 3), (3, 4)],
    3: [(0, 6), (2, 4), (4, 2)],
    4: [(1, 5), (3, 2)]
}
mst = prims_algorithm(graph)
print(mst)
