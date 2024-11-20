# DFS: explores as deep as possible along a branch before backtracking 
def dfs(graph, start):
  visited = set()
  stack = [start]

  while stack:
    vertex = stack.pop()
    if vertex not in visited:
      visited.add(vertex)
      print(vertex)
      for neighbor in graph[vertex]: 
        stack.append(neighbor)

# example usage
graph - {
  'A': ['B', 'C'],
  'B': ['D', 'E'],
  'C: ['F'],
  'D': [],
  'E': ['F'],
  'F' : []
}

dfs(graph, 'A')

# BFS: explores all neighbors at present depth before moving on to next depth level 
from collections import deque
def bfs(graph, start):
  visited = set()
  queue = deque([start])

  while queue:
    vertex = queue.popleft()
    if vertex not in visited:
      visited.add(vertex)
      print(vertex)
      for neighbor in graph[vertex]:
        queue.append(neighbor)

# example usage
bfs(graph, 'A')
