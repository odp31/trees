#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// structure to represent a weighted edge in the graph 
struct Edge {
  int src, dest, weight;
};

// function to compare edges based on weights
bool compareEdges(const Edge& a, const Edge&b) {
  return a.weight < b.weight;
}

// function to find parent of a node in disjoint set
int findParent(vector<int>& parent, int node) {
  if(parent[node] != node) {
    parent[node] = findParent(parent, parent[node]);
  }
  return parent[node];
}

// function to perform union of two sets in disjoint set 
void unionSets(vector<int>& parent, int x, int y) {
  int xRoot = findParent(parent, x);
  int yRoot = findParent(parent, y);
  parent[xRoot] = yRoot;
}

// function to find MST usking kruskal's
vector<Edge> kruskalMST(vector<Edge>& edges, int V) {
  vector<Edge> mst;
  sort(edges.begin(), edges.end(), compareEdges);

  // create disjoint set
  vector<int> parent(V);
  for(int i = 0; i < V; ++i) {
    parent[i] = i;
  }

  int edgeCount = 0;
  for(const Edge& edge : edges) {
    int x = edge.src;
    int y = edge.dest;
    int xRoot = findParent(parent, x);
    int yRoot = findParent(parent, y);

    // if including this edge does not create a cycle
    if(xRoot != yRoot) {
      mst.push_back(edge);
      unionSets(parent, xRoot, yRoot);
      edgeCount++;
    }
    // if we have included V-1 edges, we have the MST
    if(edgeCount == V - 1) {
      break;
    }
  }
  return mst;
}

int main() {
  int V = 4;
  vector<Edge> edges = {
{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}
};

vector<Edge> mst = kruskalMST(edges, V);
cout << "edges in MST: " << endl;
for(const Edge& edge : mst) {
  cout << edge.src << " -- " << edge.dest << " : " << edge.weight << endl;
}

return 0;
}
