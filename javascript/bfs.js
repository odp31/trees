function bfs(graph, startNode)
{
  const visited = new Set();
  const queue = [startNode];

  while (queue.length > 0)
    {
      const currentVertex = queue.shift();
      console.log(currentVertex);
      visited.add(currentVertex);

      for(const neighbor of graph[currentVertex])
        {
          if(!visited.has(neighbor))
          {
            visited.add(neighbor);
            queue.push(neighbor);
          }
        }
    }
}
// Example usage:
const graph = {
  0: [1, 2],
  1: [2],
  2: [0, 3],
  3: [3]
};

bfs(graph, 0) // output = 0 1 2 3 
