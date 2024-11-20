import java.util.*;

public class PrimsAlgorithm
  {
    public static void primMST(int graph[][], int V)
    {
      // create a PQ to store vertices and their current key values
      PriorityQueue<Node> pq = new PriorityQueue<>(V, Comparator.comparingInt(o-> o.key));
      // create array to store constructed MST 
      int parent[] = new int[V];
      // create boolean array to track vertices included in MST
      boolean inMST[] = new boolean[V];
      // initialize all keys as infinite and stpSet[] as false 
      for (int i = 0; i < V; i++) {
        pq.add(new Node(i, Integer.MAX_VALUE));
        inMST[i] = false;
      }
      // include first vertex in MST
      pq.remove();
      pq.add(new Node(0, 0));
      parent[0] = -1;

      // looping till MST size becomes V
      while (!pq.isEmpty()) {
        // extract vertex with min key value
        Node node = pq.poll();
        int u = node.vertex;
        inMST[u] = true;

        // update key value and parent index of adjacent vertices of the picked vertex
        // consider only those vertices which are not yet included in MST
        for(int v = 0; v < V; v++) {
          // graph[u][v] is non zero only for adjacent vertices
          // graph[u][v] is weight of edge from u to v 
          if (graph[u][v] != 0 && !inMST[v] && graph[u][v] < pq.peek().key){
            // updating key value and parent index of v in the pq
            pq.remove(new Node(v, graph[u][v]));
            pq.add(new Node(v, graph[u][v]));
            parent[v] = u;
          }
        }
      }
      printMST(parent, V, graph); // print constructed MST
    }
    // utility function to print constructed MST stored in parent[]
    public static void printMST(int parent[], int V, int graph[][]){
      System.out.println("Edge \tWeight");
      for(int i = 1; i < V; i++) {
        System.out.println(parent[i] + " - " + i + "\t" + graph[i][parent[i]]);
      }
    }
    // class to represent a node in the pq
    static class Node {
      int vertex;
      int key;

      public Node(int vertex, int key) {
        this.vertex = vertex;
        this.key = key;
      }
    }
  }
      
            
    
