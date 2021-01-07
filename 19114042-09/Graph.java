import java.util. * ;

class Graph {
	int vertices;
	int prev_vertex = 0;
	int count = 0;
	int DFSvisited[];
	Vector < Integer > bfsvec;
	Vector < Integer > dfsvec;
	Vector < Integer > edgeRemoved = new Vector < Integer > ();
	LinkedList < Integer > Edcollection[];
	Graph(int v) {
		vertices = v;
		Edcollection = new LinkedList[v];
		bfsvec = new Vector < Integer > (v);
		dfsvec = new Vector < Integer > (v);
		for (int i = 0; i < v; i++)
		Edcollection[i] = new LinkedList < Integer > ();
		DFSvisited = new int[vertices];
	}
	void makeEdge(int f, int s) {
		Edcollection[f].add(s);
	}
	void PrintBFS(int n, boolean not_p) {
		Queue < Integer > q = new LinkedList < Integer > ();
		int added[] = new int[vertices];
		//Arrays.fill(visited,0);		
		q.add(n);
		added[n] = 1;
		if (!not_p) System.out.print("BFS:");
		for (int j = 0; j < vertices; j++) {
			if (added[j] != 1) {
				added[j] = 1;
				q.add(j);
			}
			while (q.size() > 0) {
				int m = q.element();
				q.remove();
				if (!not_p) System.out.print(" " + m);
				bfsvec.add(m);
				for (int i: Edcollection[m]) {
					if (added[i] != 1) {
						added[i] = 1;
						q.add(i);
					}
				}
			}
		}
	}
	void printDFS(int n, boolean not_p) {
		if (!not_p) System.out.print(" " + n);
		dfsvec.add(n);
		DFSvisited[n] = 1;
		for (int i: Edcollection[n]) {
			if (DFSvisited[i] != 1) printDFS(i, not_p);
		}
	}
	void RemoveEdge(int m, int n) {
		Edcollection[m].remove(Integer.valueOf(n));
		Edcollection[n].remove(Integer.valueOf(m));
	}
	void findEdgeToRemove(int n) {
		/*System.out.println(bfsvec);
		System.out.println(dfsvec);
		print(n);*/
		n = dfsvec.size();
		int i;
		for (i = 0; i < dfsvec.size(); i++) {
			if (bfsvec.get(i) != dfsvec.get(i)) {
				count++;
				edgeRemoved.add(dfsvec.get(i));
				edgeRemoved.add(dfsvec.get(i - 1));
				break;
			}
		}
		if (i < dfsvec.size()) {
			RemoveEdge(dfsvec.get(i), dfsvec.get(i - 1));
			/*bfsvec.clear();
		dfsvec.clear();*/
			bfsvec = new Vector < Integer > (n);
			dfsvec = new Vector < Integer > (n);
			Arrays.fill(DFSvisited, 0);
			PrintBFS(0, true);
			DfsRecurse(true);
			findEdgeToRemove(n);
		}

	}
	void DfsRecurse(boolean not_p) {
		for (int i = 0; i < vertices; i++) {
			if (DFSvisited[i] != 1) {
				printDFS(i, not_p);
			}
		}
	}
	void printResult() {
		System.out.println("\n" + count);
		for (int i = 0; i < edgeRemoved.size(); i = i + 2) {
			System.out.println(edgeRemoved.get(i) + " " + edgeRemoved.get(i + 1));
		}
	}
	void print(int l) {
		for (int i = 0; i < l; i++)
		System.out.println(Edcollection[i]);
	}
	public static void main(String[] args) {
		Scanner c = new Scanner(System. in );
		int l = c.nextInt();
		Graph g = new Graph(l);
		for (int i = 0; i < l * l; i++) {
			if (c.nextInt() == 1) g.makeEdge(i / l, i % l);
		}
		//g.print(l);
		g.PrintBFS(0, false);
		System.out.print("\nDFS:");
		//g.printDFS(0, false);
		g.DfsRecurse(false); //this has been added to cope up with disconnected graph
		g.findEdgeToRemove(l);
		g.printResult();
	}
}