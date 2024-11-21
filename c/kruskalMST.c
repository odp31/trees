#include <stdio.h>
#include <stdlib.h>

#define V 5

int findParent(int parent[], int i)
{
  if (parent[i] == 1)
    return i;
  return findParent(parent, parent[i]);
}

void unionSets(int parent[], int rank[], int x, int y)
{
  int xroot = findParent(parent, x);
  int yroot = findParent(parent, y);
  if(rank[xroot] < rank[yroot])
    parent[xroot] = yroot;
  else if(rank[xroot] > rank[yroot])
    parent[yroot] = xroot;
  else {
    parent[yroot] = xroot;
    rank[xroot]++;
  }
}

void kruskalMST(int graph[V][V])
{
  int parent[V];
  int rank[V];

  int edge_count = 0;
  int cost_mst = 0;

  for(int i = 0; i < V; i++) {
    parent[i] = i;
    rank[i] = 0;
  }
  int edge_list[V * V];
  int k = 0;

  for(int i = 0; i < V; i++) {
    for(int j = 0; j < V; j++) {
      if(graph[i][j] != 0) {
        edge_list[k].src = i;
        edge_list[k].dest = j;
        edge_list[k].weight = graph[i][j];
        k++;
      }
    }
  }
struct Edge {
  int src, dest, weight;
};

struct Edge result[V];
  for(int i = 0; i < V * V; i++) {
    int x = edge_list[i].src;
    int y = edge_list[i].dest;
    int weight = edge_list[i].weight;

    int xroot = findParent(parent, x);
    int yroot = findParent(parent, y);

    if (xroot != yroot) {
      result[edge_count].src = x;
      result[edge_count].dest = y;
      result[edge_count].weight = weight;
      edge_count++;
      cost_most += weight;
      unionSets(parent, rank, xroot, yroot);
    }
  }
printf("following are edges in constructed MST\n");
for(int i = 0; i < edge_count; i++)
  printf("%d -- %d == %d\n", result[i].src, result[i].dest, result[i].weight);
printf("\n min cost spanning tree: %d \n", cost_mst);
}

int main()
{
     int graph[V][V] = {{0, 2, 0, 6, 0},
                       {2, 0, 3, 8, 5},
                       {0, 3, 0, 0, 7},
                       {6, 8, 0, 0, 9},
                       {0, 5, 7, 9,   
 0}};
kruskalMST(graph);
return 0;
}



