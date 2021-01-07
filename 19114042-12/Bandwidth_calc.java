import java.util.*;

class Graph {

    private int v;
    int maxBand = -1;

    private ArrayList < Integer > [] adjList;
    private int weight[][];

    // Constructor 
    public Graph(int vertices) {

        // initialise no of vertices 
        this.v = vertices;
        //initialise weight matrix
        weight = new int[vertices][vertices];

        // initialise adjacency list 
        adjList = new ArrayList[v];

        for (int i = 0; i < v; i++) {
            adjList[i] = new ArrayList < > ();
        }
    }

    // add edge from u to v 
    public void addEdge(int u, int v, int w) {
        // Add v to u's list. 
        weight[u][v] = w;
        adjList[u].add(v);
    }

    public void calculateAllPaths(int s, int d) {
        boolean[] isVisited = new boolean[v];
        ArrayList < Integer > pathList = new ArrayList < > ();

        pathList.add(s);

        calc_bandwidth(s, d, isVisited, pathList);
    }
    private void calc_bandwidth(Integer u, Integer d,
        boolean[] isVisited,
        List < Integer > localPathList) {

        if (u.equals(d)) {
            int min = 3000;
            for (int i = 1; i < localPathList.size(); i++) {
                if (min > weight[localPathList.get(i)][localPathList.get(i - 1)] && weight[localPathList.get(i)][localPathList.get(i - 1)] > 0)
                    min = weight[localPathList.get(i)][localPathList.get(i - 1)];
            }
            if (min > maxBand) {
                maxBand = min;
            }
            return;
        }

        isVisited[u] = true;

        for (Integer i: adjList[u]) {
            if (!isVisited[i]) {

                localPathList.add(i);
                calc_bandwidth(i, d, isVisited, localPathList);
                localPathList.remove(i);
            }
        }

        isVisited[u] = false;
    }
    public static void main(String[] args) {
        Scanner c = new Scanner(System.in);
        int n = c.nextInt();
        // assuming infinity as 100 and do not considering it in making edge
        //in lecture it was mentioned that we can take 100 value as infinity
        // i am assuming that either some negative value or a value greater than 100 will be 
        // equivalent to infinity here
        Graph g = new Graph(n);
        //Taking array as input 
        for (int i = 0; i < n * n; i++) {
            int p = c.nextInt();
            if (p > 0 && p < 100)
                g.addEdge(i / n, i % n, p);
        }
        int src = c.next().charAt(0) - 'A';
        int des = c.next().charAt(0) - 'A';
        g.calculateAllPaths(src, des);
        System.out.println(g.maxBand);
    }
}

//sample input
/*
//here first input is the total no of vertices in graph
5
0 30 11 2 100
30 0 8 100 100
11 8 0 3 14
2 100 3 0 43
100 100 14 43 0
A
D

*/