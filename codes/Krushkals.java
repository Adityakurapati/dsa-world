import java.util.*;

public class Krushkals {
    static int[] parent;

    public static class Edge {
        int src;
        int dest;
        int wt;

        Edge(int src, int dest, int wt) {
            this.src = src;
            this.dest = dest;
            this.wt = wt;
        }
    }

    public static class Pair implements Comparable<Pair> {
        int node, cost;

        Pair(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }

        @Override
        public int compareTo(Pair p2) {
            return this.cost - p2.cost;
        }
    }

    public static void createGraph(ArrayList<Edge>[] graph, int n) {
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        graph[0].add(new Edge(0, 1, 2));
        graph[0].add(new Edge(0, 2, 4));

        graph[1].add(new Edge(1, 3, 7));
        graph[1].add(new Edge(1, 2, 1));

        graph[2].add(new Edge(2, 4, 3));

        graph[3].add(new Edge(3, 5, 1));

        graph[4].add(new Edge(4, 3, 2));
        graph[4].add(new Edge(4, 5, 5));
    }

    public static int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    public static boolean union(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu != pv) {
            parent[pv] = pu;
            return true;
        }
        return false;
    }

    public static void Krushkals(ArrayList<Edge>[] graph, int n) {
        Arrays.sort(parent);
        int min_cost = 0;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        ArrayList<Edge> edges = new ArrayList<>();
        for (ArrayList<Edge> adjList : graph) {
            edges.addAll(adjList);
        }

        Collections.sort(edges, Comparator.comparingInt(e -> e.wt));

        ArrayList<Edge> minSpanningTree = new ArrayList<>();
        for (Edge edge : edges) {
            if (union(edge.src, edge.dest)) {
                min_cost += edge.wt;
                minSpanningTree.add(edge);
            }
        }

        System.out.println("Minimum Spanning Tree:");
        for (Edge edge : minSpanningTree) {
            System.out.println(edge.src + " - " + edge.dest + " : " + edge.wt);
        }
        System.out.println("Total Cost: " + min_cost);
    }

    public static void main(String[] args) {
        int n = 6; // number of nodes
        @SuppressWarnings("unchecked")
        ArrayList<Edge>[] graph = new ArrayList[n];
        createGraph(graph, n);
        parent = new int[n];
        Krushkals(graph, n);
    }
}
/*
 * 
import java.util.*;

public class Krushkals {
    static int[] parent;

    public static class Edge {
        int src;
        int dest;
        int wt;

        Edge(int src, int dest, int wt) {
            this.src = src;
            this.dest = dest;
            this.wt = wt;
        }
    }

    public static class Pair implements Comparable<Pair> {
        int node, cost;

        Pair(int node, int cost) {
            this.node = node;
            this.cost = cost;
        }

        @Override
        public int compareTo(Pair p2) {
            return this.cost - p2.cost;
        }
    }

    public static void createGraph(ArrayList<Edge>[] graph, int n) {
        for (int i = 0; i < n; i++) {
            graph[i] = new ArrayList<>();
        }
        graph[0].add(new Edge(0, 1, 2));
        graph[0].add(new Edge(0, 2, 4));

        graph[1].add(new Edge(1, 3, 7));
        graph[1].add(new Edge(1, 2, 1));

        graph[2].add(new Edge(2, 4, 3));

        graph[3].add(new Edge(3, 5, 1));

        graph[4].add(new Edge(4, 3, 2));
        graph[4].add(new Edge(4, 5, 5));
    }

    public static int findParent(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findParent(parent[node]);
    }

    public static boolean union(int u, int v) {
        int pu = findParent(u);
        int pv = findParent(v);
        if (pu != pv) {
            parent[pv] = pu;
            return true;
        }
        return false;
    }

    public static int Krushkals(ArrayList<Edge>[] graph, int n) {
        Arrays.sort(parent);
        int min_cost = 0;
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

        ArrayList<Edge> edges = new ArrayList<>();
        for (ArrayList<Edge> adjList : graph) {
            edges.addAll(adjList);
        }

        Collections.sort(edges, Comparator.comparingInt(e -> e.wt));

        for (Edge edge : edges) {
            if (union(edge.src, edge.dest)) {
                min_cost += edge.wt;
            }
        }
        return min_cost;
    }

    public static void main(String[] args) {
        int n = 6; // number of nodes
        @SuppressWarnings("unchecked")
        ArrayList<Edge>[] graph = new ArrayList[n];
        createGraph(graph, n);
        parent = new int[n];
        System.out.println("Minimum Cost: " + Krushkals(graph, n));
    }
}

 */