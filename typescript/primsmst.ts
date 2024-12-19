interface Edge {
  src: number;
  dest: number;
  weight: number;
}

function primsMST(graph: Edge[], V: number): number {
  const key = new Array(V).fill(Infinity);
  const mstSet = new Array(V).fill(false);
  key[0] = 0; 

  let mstCost = 0;

  for(let count = 0; count < V - 1; count++) {
    let min = Infinity;
    let min_index = -1;

    for(let v = 0; v < V; v++) {
      if(mstSet[v] === false && key[v] < min) {
        min = key[v];
        min_index = v;
      }
    }
    mstSet[min_index] = true;
    mstCost += key[min_index];

    for(let v = 0; v < V; v++) {
      if(mstSet[v] === false && key[v] < min) {
        min = key[v];
        min_index = v;
      }
    }
    mstSet[min_index] = true;
    mstCost += key[min_index];

    for(let v = 0; v < V; v++) {
      if(graph[min_index][v] && mstSet[v] === false && graph[min_index][v] < key[v]) {
        key[v] = graph[min_index][v];
      }
    }
  }
  return mstCost;
}
