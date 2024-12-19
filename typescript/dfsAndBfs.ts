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


// example usage
const graph = new Map<string, string[]>();
graph.set('A', ['B', 'C']);
graph.set('B', ['D', 'E']);
graph.set('C', ['F']);
graph.set('D', ['G']);
graph.set('E', ['H']);
graph.set('F', ['I']);
graph.set('G', ['J']);
graph.set('H', []);
graph.set('I', []);
graph.set('J', []);

console.log("dfs traversal: ");
dfs(graph, 'A');

console.log("\nBFS traversal:");
bfs(graph, 'A');

