function primMST(graph)
{
  const V = graph.length;
  const parent = new Array(V);
  const key = new Array(V);
  const mstSet = new Array(V);

  // initialize all keys as ifinite and mstSet[] as false
  for(let i = 0; i < V; i++)
    {
      key[i] = Infinity;
      mstSet[i] = false;
    }
  // always include first vertex in MST
  // make key 0 so that this vertex is picked as first vertex
  key[0] = 0;
  parent[0] = -1; // first node is always root of MST

  for(let count = 0; count < V - 1; count++)
    {
      let min = Infinity, min_index;
      for(let v = 0; v < V; v++)
        if(mstSet[v] === false && key[v] < min)
          min = key[v], min_index = v;
      // add picked vertex to MST set
      mstSet[min_index] = true;
      for(let v = 0; v < V; v++)
        {
          if(graph[min_index][v] && mstSet[v] === false && graph[min_index][v] < key[v])
            parent[v] = min_index, key[v] = graph[min_index][v];
        }
    }
  // print constructed mst
  printMST(parent, graph, V);
}

function printMST(parent, graph, V)
{
  console.log("edge \tWeight");
  for(let i = 1; i < V; i++)
    console.log(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
}
// Example usage:
const graph = [
  [0, 2, 0, 6, 0],
  [2, 0, 3, 8, 5],
  [0, 3, 0, 0, 7],
  [6, 8, 0, 0, 9],
  [0, 5, 7, 9, 0]
];

primMST(graph);
