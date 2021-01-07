import java.util.Scanner;

class Topological{
	static void findmax(int[] A,int n){
		int maxI = A[0];
		int max=0;
		for(int i=0;i<n;i++){
			if(A[i]>maxI){
				maxI = A[i];
				max = i;
			}
		}
		A[max] = -1;
		System.out.print(max+" ");
	}
	public static void main(String[] args){
		Scanner c = new Scanner(System.in);
		int n = c.nextInt();
		int Adj[] = new int[n*n];
		int ref[] = new int[n];		
		for(int i=0;i<n*n;i++){
			Adj[i] = c.nextInt();
			if(Adj[i]==1)
				ref[i/n]++; //store how many directed edge starts at a particular vertex
		}
		for(int j=0;j<n;j++){
			findmax(ref,n);
		}
	}
}