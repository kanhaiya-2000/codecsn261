import java.lang.reflect.Array;
import java.util.*;
import java.lang.*;

class node {
    int v;
    int w;

    node(int v, int w) {
        this.v = v;
        this.w = w;
    }
}


class BwCentrality {

    static void addEdge(ArrayList<ArrayList<node>> adjlist, int v1, int v2, int w) {

        node n1 = new node(v2, w);
        node n2 = new node(v1, w);

        adjlist.get(v1).add(n1);
        adjlist.get(v2).add(n2);
    }

    static double findvinsp(ArrayList<LinkedList<Integer>> t, int v) {  // number of all shortest path through v
        double paths = 0;
        for (int i = 0; i < t.size(); i++) {
            for (int j=0;j<t.get(i).size();j++){
                if (t.get(i).get(j)==v){
                    paths++;
                }
            }
        }
        return paths;
    }

    static void find_path(ArrayList<LinkedList<Integer>> paths, LinkedList<Integer> path, ArrayList<Integer> parent[], int u) {
        if (u == -1) {
            LinkedList newpath = new LinkedList();
            newpath = (LinkedList)path.clone();
            paths.add(newpath);
            return;
        }

        for (int par:parent[u]) {
          path.add(u);
          find_path(paths,path,parent,par);
          path.removeLast();
        }
        return;
    }

    static void bfs(ArrayList<ArrayList<node>> adjlist, ArrayList<Integer> parent[], int n, int start) {  // set the values of parents of a particular vertex

        Queue<Integer> q = new LinkedList<>();
        q.add(start);
        int dist[] = new int[n];

        Arrays.fill(dist, Integer.MAX_VALUE);
        dist[start] = 0;
        parent[start].add(-1);
        while (!q.isEmpty()) {
            int u = q.remove();
            for (node v:
                 adjlist.get(u)) {
                if (dist[v.v]>dist[u]+v.w){
                    dist[v.v] = dist[u]+v.w;
                    q.add(v.v);
                    parent[v.v].clear();
                    if (!parent[v.v].contains(u))
                    parent[v.v].add(u);
                }
                else if(dist[v.v]==dist[u]+v.w){
                    if (!parent[v.v].contains(u))
                        parent[v.v].add(u);
                }
            }
        }
    }


    static void findsp(ArrayList<LinkedList<Integer>> t, ArrayList<ArrayList<node>> adjlist, int v1, int v2,int v) {  // this funtion finds all shortest paths between v1 and v2

        LinkedList<Integer> path = new LinkedList<>();
        ArrayList<Integer> parent[] = new ArrayList[v];

        for (int i=0;i<v;i++){
            parent[i] = new ArrayList<>();
        }

        bfs(adjlist, parent, v, v1);
        find_path(t, path, parent, v2);
    }

    static double measure_bw_cen(ArrayList<ArrayList<node>> adjlist, int vi,int v ) {
        double cen_val = 0;
        for (int i = 0; i < v; i++) {
            for (int j = i+1; j < v ; j++) {
                if (i == vi || j == vi) continue;
                ArrayList<LinkedList<Integer>> t = new ArrayList<>();
                findsp(t, adjlist, i, j,v);
                cen_val = cen_val + (findvinsp(t, vi)/ t.size());
            }

        }
        return cen_val;
    }



    public static void main(String[] args) {

        Scanner c = new Scanner(System.in);

        int v = c.nextInt();
        int e = c.nextInt();

        ArrayList<ArrayList<node>> adjlist = new ArrayList<ArrayList<node>>(v);

        for (int i = 0; i < v; i++)
            adjlist.add(new ArrayList<node>());

        for (int i = 0; i < e; i++) {
            addEdge(adjlist, c.nextInt() , c.nextInt() , c.nextInt());
        }

        for (int i = 0; i < v; i++)
            System.out.print(measure_bw_cen(adjlist, i,v) + " ");
        System.out.println();

    }
}
/*Sample input

10 20
0 1 4
0 4 8
0 6 7
0 7 5
0 8 1
0 9 9
1 3 8
1 5 6
1 6 8
1 7 2
1 8 4
2 3 5
2 8 3
3 9 5
4 5 8
4 9 8
5 7 5
5 8 5
7 9 3
5 9 5

*/