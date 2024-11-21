function dfs(graph, startNode, visited = new Set())
{
  visited.add(startNode);
  console.log(startNode);

  for(const neighbor of graph[startNode])
    {
      if (!visited.has(neighbor))
      {
        dfs(graph, neighbor, visited);
      }
    }
}
