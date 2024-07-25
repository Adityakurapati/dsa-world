import java.util.*;

public class GRAPH {
        public static class Edge {
                int src, dest, wt;

                public Edge(int src, int dest, int wt) {
                        this.src = src;
                        this.dest = dest;
                        this.wt = wt;
                }
        }
        

        public static void createGraph(ArrayList<Edge> graph[]) {
                for (int i = 0; i < graph.length; i++) {
                        graph[i] = new ArrayList<Edge>();
                }

                graph[0].add(new Edge(0, 1, 2));
                graph[1].add(new Edge(1, 2, 10));
                graph[1].add(new Edge(1, 3, 0));
                graph[2].add(new Edge(2, 0, 2));
                graph[2].add(new Edge(2, 1, 10));
                graph[2].add(new Edge(2, 3, -1));
                graph[3].add(new Edge(3, 1, 0));
                graph[3].add(new Edge(3, 2, -1));
        }

        public static void BFS(ArrayList<Edge> graph, int V) {
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
                int V = 4;
                ArrayList<Edge> graph[] = new ArrayList[V];
                createGraph(graph);
                System.out.println("The graph is: ");
                for (ArrayList<Edge> g : graph) {
                        for (Edge e : g) {
                                System.out.println(e.src + " " + e.dest + " " + e.wt);
                        }
                }
        }
}
