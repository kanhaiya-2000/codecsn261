import java.util.*;

class DetectPath{


	static int detectEdgeTraversed(Vector<Integer> Edges[],int src,int des){
		if(src==des){
			return 0;
		}
		Vector<Integer> count = new Vector<Integer>(des);
		Vector<Boolean> visited = new Vector<Boolean>(des);
		
		for(int i=0;i<des;i++){
			count.addElement(0);
			visited.addElement(false);
		}
		LinkedList<Integer> bq = new LinkedList<>();
		count.setElementAt(0,src);
		visited.setElementAt(true,src);
		bq.add(src);
		while(!bq.isEmpty()){
			int x = bq.pop(); 
            
			//System.out.println(2);
			for(int i=0;i<Edges[x].size();i++){
				if (visited.elementAt(Edges[x].get(i))) 
                    continue; 
				count.setElementAt(count.get(x)+1,Edges[x].get(i));
				bq.add(Edges[x].get(i));
				visited.setElementAt(true,Edges[x].get(i)); 
			}
		}
		//System.out.println(1);
		return count.get(des-1);

	}
	static void makeEdge(Vector<Integer> Edges[],int f,int s){
		Edges[f].add(s);
		Edges[s].add(f);
	}
	public static void main(String[] args) {
		Scanner inp = new Scanner(System.in);
		int N,M,Q;
		
		N = inp.nextInt();
		M = inp.nextInt();
		Vector<Integer> Edges[] = new Vector[N+1];
		for (int i = 0; i < N; i++) { 
            Edges[i] = new Vector<>(); 
        } 
		for(int i=0;i<M;i++){
			int p = inp.nextInt();
			int q =inp.nextInt(); 
			makeEdge(Edges,p-1,q-1);
		}
		Q = inp.nextInt();
		//System.out.println("here");
		for(int i=0;i<Q;i++){
			int q = inp.nextInt();
			//System.out.println(i);
			int n = detectEdgeTraversed(Edges,q-1,N);
			System.out.println(n==0?"impossible":n);
		}
	}
}