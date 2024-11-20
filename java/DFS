// DFS: explores as deep as possible along branch before backtracking 

import java.util.*;

public class DFS
{
  public static void dfs(int[][] graph, int v, boolean[] visited)
  {
    visited[v] = true;
    System.out.print(v + " " );

    for (int i = 0; i < graph[v].length; i++)
    {
      if(graph[v][i] == 1 && !visited[i])
      {
        dfs(graph, i, visited);
      }
    }
  }
  public static void main(String[] args)
  {
    int graph[][] = {{0, 1, 0, 0, 0},
                        {1, 0, 1, 1, 0},
                        {0, 1, 0, 0, 0},
                        {0, 1, 0, 0, 1},
                        {0, 0, 0, 1, 0}};
    boolean[] visited = new boolean[5];
    dfs(graph, 0, visited);
  }
}
