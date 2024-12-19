function dfs<T>(graph: Map<T, T[]>, start: T, visited: Set<T> = new Set()): void {
  visited.add(start);
  console.log(start);

  for(const neighbor of graph.get(start)!) {
    if(!visited.has(neighbor)) {
      dfs(graph, neighbor, visited);
    }
  }
}

function bfs<T>(graph: Map<T, T[]>, start: T): void {
  const queue: T[] = [start];
  const visited = new Set<T>();
  visited.add(start);

  while(queue.length > 0) {
    const current = queue.shift()!;
    console.log(current);

    for(const neighbor of graph.get(current)!) {
      if(!visited.has(neighbor)) {
        visited.add(neighbor);
        queue.push(neighbor);
      }
    }
  }
}
