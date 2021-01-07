import java.util.*;

class StopInfection{
	int V;
	int exp = 0;
	int degree[];
	private ArrayList<Integer>[] adj;
    boolean isConnected = false;
	public StopInfection(int V){
		this.V = V;
		adj = new ArrayList[V];
		degree = new int[V];
		for(int i=0;i<V;i++){
			adj[i] = new ArrayList<>();
		}	
	}
	int choseMaxDeg_vertex(){
		int max = 0;
		int index = -1;
		for(int i=0;i<V;i++){
			if(degree[i]>max){
				max = degree[i];
				index = i;
			}
		}

		return index;
	}
	void DestroyVertex(int v){
	    if(v==-1){
	        isConnected = false;
	        return;
	    }
		degree[v] = -1;
		exp++;
		adj[v] = new ArrayList<>();
		for(int k=0;k<V;k++){
			if(adj[k].indexOf(v)>-1){
				degree[k]--;
			}
		}
	}
	
	void calc_minExplosive(){
		while(isConnected){
			DestroyVertex(choseMaxDeg_vertex());
		}
	}
	void addEdge(int u,int v){
		isConnected = true;
		adj[u].add(v);
		adj[v].add(u);
		degree[u]++;
		degree[v]++;
	}
	public static void main(String[] args){
		Scanner c = new Scanner(System.in);
		int N = c.nextInt();
		int M = c.nextInt();
		StopInfection sf = new StopInfection(N);
		for(int i=0;i<M;i++){
			sf.addEdge(c.nextInt()-1,c.nextInt()-1);
		}
		sf.calc_minExplosive();
		System.out.println(sf.exp);

	}
}