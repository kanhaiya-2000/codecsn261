import java.util.Scanner;

class CalculateAVLNode{
	public static int calc_min(int h){
		if(h<0){
			System.out.println("Invalid input");
			return -1;
		}
		else if(h<2)
			return h+1;
		 ///Minimum node will be obtained if we consider that absolute 
		     //difference in height between left and right subtree of each node is 1 except for leaf node 
		else 
			return 1+ calc_min(h-1) + calc_min(h-2);
	}
	public static void main(String args[]){
		Scanner inp = new Scanner(System.in);
		int height_inp = inp.nextInt();
		System.out.println(calc_min(height_inp));
	}
}