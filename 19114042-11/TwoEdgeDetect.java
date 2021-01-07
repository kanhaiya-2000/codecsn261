import java.util.Scanner;

class TwoEdgeDetect{
	public static void main(String[] args){
		int V,E;
		Scanner inp = new Scanner(System.in);
		String result = "Yes";
		V = inp.nextInt();
		E = inp.nextInt();
		int m[] = new int[V*V];
		for(int i=0;i<V*V;i++){
			m[i] = inp.nextInt();
		}
		for(int i=0;i<V;i++){
			int t =0;
			for(int j=i;j<V*V;j=j+V){
				t += m[j];

			}
			if(t<2){ //Assuming no self loop as  mentioned in lecture
				result = "No";
				break;
			}

		}
		System.out.println(result);
	}
}