import java.util.Scanner;

class Maze{
	public static void main(String[] args){
		int np ,mp,rp;
		Scanner c = new Scanner(System.in);
		np = c.nextInt();
		mp = c.nextInt();
		rp = c.nextInt();
		int stuckchance[] = new int[np];
		for(int i=0;i<mp;i++){
			stuckchance[c.nextInt()-1]++;
			stuckchance[c.nextInt()-1]--;
		}
		int minI = -1,minVal=np+1;
		for(int i=0;i<np;i++){
			if(stuckchance[i]<minVal){
				minVal = stuckchance[i];
				minI = i+1;
			}
		}
		System.out.print(minI);

	}
}