#include <stdio.h>
#include <stdlib.h>

# DFS: topological sorting, cycle dection in graphs, solving puzzles 
# BFS: finding shortest path in an unweighted graph
struct Node {
  int data;
  struct Node* left, *right;
};

void DFS(struct Node* root) {
  if (root == NULL)
    return;

  printf("%d ", root->data);
  DFS(root->left);
  DFS(root->right);
}



void BFS(struct Node* root) {
  if (root == NULL)
    return;
  struct Node* queue[100];
  int front = 0, rear = 0;

  queue[rear++] = root;
  while(front < rear) {
    struct Node* temp = queue[front++];
    printf("%d ", temp->data);

    if (temp->left != NULL)
      queue[rear++] = temp-<left;
    if(temp->right != NULL
      queue[rear++] = temp->right;


      }
}
