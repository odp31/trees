// BFS: explores all neighbors at present depth before moving on to next depth level 

import java.util.*; 

public class BFS
  {
    public static void bfs(int[][] graph, int s, int V)
    {
      boolean[] visited = new boolean[V];
      LinkedList<Integer> queue = new LinkedList<>();

      visited[s] = true;
      queue.add(s);

      while(queue.size() != 0)
        {
          s = queue.poll();
          System.out.print( s + " ");

          for (int i = 0; i < V; i++)
            {
              if (graph[s][i] == 1 && !visited[i])
              {
                visited[i] = true;
                queue.add(i);
              }
            }
        }
    }
    public static void main(String[] args)
    {
      int graph[][] = {{0, 1, 1, 1, 0},
                        {1, 0, 1, 0, 0},
                        {1, 1, 0, 1, 1},
                        {1, 0, 1, 0, 1},
                        {0, 0, 1, 1, 0}};
      bfs(graph, 0, 5);
    }
  }

      
