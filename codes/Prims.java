import java.util.*;

public class Prims {
    public static class Edge {
        int src, dest, wt;

        public Edge(int src, int dest, int wt) {
            this.src = src;
            this.dest = dest;
            this.wt = wt;
        }
    }

    public static class Pair implements Comparable<Pair> {
        int node;
        int cost;

        public Pair(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }

        @Override
        public int compareTo(Pair p2) {
            return this.cost - p2.cost;
        }
    }

   public static void prims(ArrayList<Edge> graph , int src ,int V){
        PriorityQueue<Pair> pq = new PriorityQueue<>();  // Worst case Max E No, Of Edges (O()
        boolean vis[] = new boolean[V];
        pq.add(new Pair(0,0));

        while(!pq.isEmpty()){
                Pair curr = pq.remove();
                if(!vis[curr.node]){
                        vis[curr.node] = true;
                        cost += curr.cost;
                        for(Edge e : curr.node ){
                                if(!vis[e.dest]){
                                        pq.add(new Pair(e.dest,e.wt))
                                }
                        }
                }
        }
   }

    public static void createGraph(ArrayList<Edge>[] graph) {
        for (int i = 0; i < graph.length; i++) {
            graph[i] = new ArrayList<Edge>();
        }

        graph[0].add(new Edge(0, 1, 2));
        graph[0].add(new Edge(0, 2, 4));

        graph[1].add(new Edge(1, 3,7));
        graph[1].add(new Edge(1, 2, 1));

        graph[2].add(new Edge(2, 4, 3));

        graph[3].add(new Edge(3, 5, 1));

        graph[4].add(new Edge(4, 3, 2));
        graph[4].add(new Edge(4, 5, 5));
    }

    public static void BFS(ArrayList<Edge>[] graph, int V) {
        Queue<Integer> q = new LinkedList<>();
        boolean visited[] = new boolean[V];
        q.add(0);

        while (!q.isEmpty()) {
            int current = q.remove();
            if (visited[current] == false) {
                System.out.println(current);
                visited[current] = true;
                for (Edge e : graph[current]) {
                    q.add(e.dest);
                }
            }
        }
    }

    public static void main(String[] args) {
        int V = 6;
        ArrayList<Edge>[] graph = new ArrayList[V];
        createGraph(graph);
        Prims(graph, 0, V);
    }
}
