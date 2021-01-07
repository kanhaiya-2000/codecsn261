import java.util.Scanner;

class DetectSwapForBST{
    int mainArr[];
    int count = 0;
    int i =0;
	void swap(int a ,int b){
		 mainArr[a] = mainArr[a] + mainArr[b];
		 mainArr[b] = mainArr[a] - mainArr[b];
		 mainArr[a] = mainArr[a] - mainArr[b];
		 count++;

	}

    void performInorder(int[] Arr,int l){
        if(l==0)
          mainArr = new int[Arr.length];    	
    	if(l < Arr.length){
    		performInorder(Arr,2*l+1);
    		mainArr[i++] = Arr[l];
    		performInorder(Arr,2*l+2);
    	}

	}
	void printArr(){
		for(int i=0;i<mainArr.length;i++)
			System.out.print(" "+mainArr[i]);
	}
	void printSwapcount(){
		/*System.out.println("Before swap-->");
		printArr();*/
		int min;
		int minelmnt = -1;
		for(int i=0;i<mainArr.length;i++){
			min =-1;
			minelmnt = -1;
			for(int j=i;j<mainArr.length;j++){
				if(minelmnt==-1){
					if(mainArr[i]>mainArr[j]){
						minelmnt = mainArr[j];
						min = j;
					}
				}
				else{
					if(minelmnt>mainArr[j]){
						minelmnt = mainArr[j];
						min = j;
					}
				}
			}
			if(minelmnt!=-1)
			 swap(i,min);
				
		}

		// System.out.println("after swap-->");
		// printArr();
	}

	public static void main(String[] args){		
		Scanner c = new Scanner(System.in);
		int num  = c.nextInt();
		int main[] = new int[num];		
		for(int i=0;i<num;i++){
			main[i] = c.nextInt();
		}
		DetectSwapForBST obj = new DetectSwapForBST();
		obj.performInorder(main,0);
		obj.printSwapcount();
		System.out.println(obj.count);
	}
	
}