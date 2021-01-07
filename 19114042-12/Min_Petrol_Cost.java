import java.util.*;

class MinPetrol{
	int Vert;
	int Edge;
	int petrolcost[];//This comes in input in a separate line as space separated integers
	int petrolamount[][];//This comes in input with each road
	long[][] cst;
	void initialiseSystem(){
		petrolcost = new int[Vert];
		petrolamount = new int[Edge][3];
		cst = new long[Vert][Vert];
		for(int i=0; i<Vert; i++) Arrays.fill(cst[i], Long.MAX_VALUE/2-1);
        for(int i=0; i<Vert; i++) cst[i][i] = 0;
	}
	void addEdge(int u,int v,int w,int i){
		petrolamount[i][0] = u;
		petrolamount[i][1] = v;
		petrolamount[i][2] = w;
		
	}
	public static void main(String[] args){
		int T;
		Scanner c = new Scanner(System.in);
		T = c.nextInt();
		MinPetrol m = new MinPetrol();
		while(T-- > 0){
			int V = c.nextInt();
		m.Vert = V;		
		int E = c.nextInt();
		m.Edge = E;	
		m.initialiseSystem();
		for(int i=0;i<E;i++)
			m.addEdge(c.nextInt()-1,c.nextInt()-1,c.nextInt(),i);
		for(int i=0;i<V;i++){
			m.petrolcost[i] = c.nextInt();
		}
		for(int i=0; i<E; i++) {
            m.cst[m.petrolamount[i][0]][m.petrolamount[i][1]] = 1L * m.petrolamount[i][2];
            m.cst[m.petrolamount[i][1]][m.petrolamount[i][0]] = 1L * m.petrolamount[i][2];
          }
          for(int k=0; k<V; k++) {
            for(int i=0; i<V; i++) {
              for(int j=0; j<V; j++) {
                if(m.cst[i][j] > m.cst[i][k] + m.cst[k][j])
                  m.cst[i][j] = m.cst[i][k] + m.cst[k][j];
              }
            }
          }
          long[][] new_cst = new long[V][V];
          for(int i=0; i<V; i++) Arrays.fill(new_cst[i], Long.MAX_VALUE/2-1);
          for(int i=0; i<V; i++) new_cst[i][i] = 0;

          for(int i=0; i<V; i++)
            for(int j=0; j<V; j++)
              if(m.cst[i][j] != Long.MAX_VALUE)
                new_cst[i][j] = 1L * m.cst[i][j] * m.petrolcost[i];
          for(int k=0; k<V; k++) {
            for(int i=0; i<V; i++) {
              for(int j=0; j<V; j++) {
                if(new_cst[i][j] > new_cst[i][k] + new_cst[k][j])
                  new_cst[i][j] = new_cst[i][k] + new_cst[k][j];
              }
            }
          }
          System.out.println(new_cst[c.nextInt()-1][c.nextInt()-1]);
		}
	}
}
//sample input
/*

1 
4 3
1 2 3
2 3 1
2 4 7
3 6 2 2
1 4

*/