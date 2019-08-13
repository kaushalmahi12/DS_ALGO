import java.util.*;

class Graph {
    static int timer = 0;
    static class Vertex implements Comparable<Vertex> {
        int postOrder, val;
        boolean visited, marked;
        List<Vertex> adj, adj1; // adj: reverse graph adjacency List, adj1: main graph adjacency list

        public Vertex(int v) {
            adj = new ArrayList<>();
            adj1 = new ArrayList<>();
            visited =  false;
            marked = false;
            this.val = v;
        }

        public void add(Vertex v) {
            adj.add(v);
            v.adj1.add(this);
        }

        public List<Vertex> explore() {
            List<Vertex> scc = new ArrayList<>();
            scc.add(this);
            this.marked = true;
            for (Vertex v: adj1) {
                if (!v.marked) {
                    List<Vertex> subScc = v.explore();
                    scc.addAll(subScc);
                }
            }
            return scc;
        }

        public void dfs() {
            visited = true;
            ++(Graph.timer);
            for (Vertex v: adj) {
                if (!v.visited) {
                    v.dfs();
                }
            }
            postOrder = ++(Graph.timer);
            //System.out.println(this + " -> " + postOrder);
        }

        public int compareTo(Vertex v) {
            return v.postOrder - postOrder;
        }

        public String toString() {
            return "" + this.val;
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int nodes = sc.nextInt();
        Vertex[] vertices = new Vertex[nodes+1];
        for (int i=1; i<=nodes; i++) {
            vertices[i] = new Vertex(i);
        }
        int edges = sc.nextInt();

        for(int i=0; i<edges; i++) {
            int u = sc.nextInt(), v = sc.nextInt();
            vertices[v].add(vertices[u]);
        }
        for (int i=1; i<=nodes; i++) {
            if (!vertices[i].visited) {
                vertices[i].dfs();
            }
        }

        Arrays.sort(vertices, 1, nodes+1);
        int scc = 0;
        for (int i=1; i<=nodes; i++) {
            if (!vertices[i].marked) {
                System.out.println(vertices[i].val + " :) " + vertices[i].postOrder);
                List<Vertex> newScc = vertices[i].explore();
                scc++;
                System.out.print("SCC no: " + scc + " => ");
                for (Vertex v: newScc) {
                    System.out.print(v + " ");
                }
                System.out.println();
            }
        }
    }
}
