import java.util.*;

class MSTProblem {
	int minKey(int key[], Boolean checks[],int V){ 
		
		int min = Integer.MAX_VALUE, mi = -1; 
		for (int v = 0; v < V; v++) 
			if (checks[v] == false && key[v] < min) { 
				min = key[v]; 
				mi = v; 
			}
		return mi; 
	}
	int choseMax(int parent[],int arrayAdj[][],int V){
		int min = Integer.MAX_VALUE,index=-1;
		for(int i=1;i<V;i++){
			if(min>arrayAdj[i][parent[i]]){
				min = arrayAdj[i][parent[i]];
				index = i;
				
			}
		}
		return index;
	}	
	void printit(int parent[], int arrayAdj[][],int V){ 		
		for (int i = V-1; i >0; i--){
			int k = choseMax(parent,arrayAdj,V); 
			System.out.println(parent[k]+1 + "  " + (k+1) + " " + arrayAdj[k][parent[k]]);
			arrayAdj[k][parent[k]] = Integer.MAX_VALUE;
			} 
	} 
	
	void applyAlgo(int arrayAdj[][],int V){ 		
		int parent[] = new int[V];		
		int key[] = new int[V];		
		Boolean checks[] = new Boolean[V];		
		for (int i = 0; i < V; i++) { 
			key[i] = Integer.MAX_VALUE; 
			checks[i] = false; 
		} 		
		key[0] = 0; 
		parent[0] = -1; 
		for (int count = 0; count < V - 1; count++) {		
			int u = minKey(key, checks,V); 			
			checks[u] = true; 
			for (int v = 0; v < V; v++) 
				if (arrayAdj[u][v] != 0 && checks[v] == false && arrayAdj[u][v] < key[v]) { 
					parent[v] = u; 
					key[v] = arrayAdj[u][v]; 
				} 
		} 		
		printit(parent, arrayAdj,V); 
	} 

	public static void main(String[] args){ 
		Scanner inp = new Scanner(System.in);
		MSTProblem t = new MSTProblem();
		int z = inp.nextInt();
		for(int i=0;i<z;i++){ 
			int N,M;
			N = inp.nextInt();
			M = inp.nextInt();
			int arrayAdj[][] = new int[N][N];
			for(int j=0;j<M;j++){
			    int p = inp.nextInt();
			    int q = inp.nextInt();
			    int r = inp.nextInt();
			    //System.out.print(p+" "+q+" "+r);
				arrayAdj[p-1][q-1] = r;
				arrayAdj[q-1][p-1] = r;
			} 
			//System.out.print(arrayAdj);

		// Print the solution 
		t.applyAlgo(arrayAdj,N);
		} 
	} 
} 

