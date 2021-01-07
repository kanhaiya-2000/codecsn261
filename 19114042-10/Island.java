import java.util.*; 

class Island{	

	static void FindIslands(int a[][],int n){ 

		Union u = new Union(n);   

		for (int i=0; i<n*n; i++){	

			if (a[i/n][i%n] == 0) 
				continue;  
			int k = i%n;
			if (i/n+1 < n && a[i/n+1][k]==1) 
				u.makeunion(i, i+n); 
			if (i/n-1 >= 0 && a[i/n-1][k]==1) 
				u.makeunion(i, i-n);
			if (i/n +1<n && k+1<n && a[i/n+1][k+1]==1) 
				u.makeunion(i, i+n+1);  
			if (k+1 < n && a[i/n][k+1]==1) 
				u.makeunion(i, i+1); 
			if (k-1 >= 0 && a[i/n][k-1]==1) 
				u.makeunion(i, i-1);			
			if (i/n-1>=0 && k+1<n && a[i/n-1][k+1]==1) 
				u.makeunion(i, i-n+1); 
			if (i/n-1>=0 && k-1>=0 && a[i/n-1][k-1]==1) 
				u.makeunion(i, i-n-1);
			if (i/n+1<n && k-1>=0 && a[i/n+1][k-1]==1) 
				u.makeunion(i, i+n-1);  

		}  

		int[] counter = new int[n*n]; 
		int num = 0; 
		for (int i=0; i<n*n; i++){
			if (a[i/n][i%n]==1){
				int x = u.findParent(i);                   
				if (counter[x]==0){ 
					num++;					 
				}				
				counter[x]++; 
			}
		} 
		System.out.println(num); 
	}

	public static void main(String[] args){
		Scanner c = new Scanner(System.in);
		int n = c.nextInt();

		int[][] a = new int[n][n];
		for(int i=0;i<n*n;i++){
			a[i/n][i%n] = c.nextInt();
		} 
		FindIslands(a,n); 
	}
}  
//class for doing union
class Union{ 
	int[] depth, parent;   

	public Union(int n){ 
		depth = new int[n*n]; 
		parent = new int[n*n];        
		for (int i=0; i<n*n; i++) 
			parent[i] = i;  
	}  

	int findParent(int x){ 
		if (parent[x] != x){           
			return findParent(parent[x]); 
		} 

		return x; 
	}  

	void makeunion(int x, int y){         
		int parent_x = findParent(x); 
		int parent_y = findParent(y);

		if (parent_x == parent_y) 
			return; 

		if (depth[parent_x] < depth[parent_y]) 
			parent[parent_x] = parent_y;  

		else if(depth[parent_y]<depth[parent_x]) 
			parent[parent_y] = parent_x; 

		else{            
			parent[parent_x] = parent_y;
			depth[parent_y] = depth[parent_y] + 1; 
		} 
	} 
} 