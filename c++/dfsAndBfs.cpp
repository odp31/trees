#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

// adjacency list representation of a graph 
vector<vector<int>> adjList;

// function to perform DFS
void dfs(int node, vector<bool>& visited) {
  visited[node] = true;
  cout << node << " ";

  for(int neighbor : adjList[node]) {
    if(!visited[neighbor]) {
      dfs(neighbor, visited);
    }
  }
}

// function to perform BFS
void bfs(int node) {
  int n = adjList.size();
  vector<bool> visited(n, false);
  queue<int> q;

  visited[node] = true;
  q.push(node);

  while(!q.empty()) {
    int current = q.front();
    q.pop();
    cout << current << " ";

    for(int neighbor : adjList[current]) {
      if (!visited[neighbor]) {
        visited[neighbor] = true;
        q.push(neighbor);
      }
    }
  }
}

int main() {
  int n = 5;
  adjList.resize(n);

  adjList[0].push_back(1);
  adjList[0].push_back(3);
  adjList[1].push_back(2);
  adjList[1].push_back(4);
  adjList[3].push_back(4);

  cout << "DFS: ";
  vector<bool> visited(n, false);
  dfs(0, visited);
  cout << endl;

  cout << "BFS: ";
  bfs(0);
  cout << endl;

  return 0;
}
