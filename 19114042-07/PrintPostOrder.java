	import java.util.Scanner;


	class PrintPostOrder{

		public static int returnIndex(int in[],int data,int l){

			while(--l!=-1){
				if(in[l]==data)
					return l;
			}			
			return -1;//this will not reach as long as inputs are valid
		}

		public static void printPostOrder(int n,int preArr[],int inArr[]){

			int base = returnIndex(inArr,preArr[0],inArr.length);

			//For postOrder...print left subtree then right subtree then root for every node

			if(base!=0){//if left subtree is not empty give priority to printing left subtree first

				int newpre[] = new int[n-1];//for storing copy of array between index [1,n)

				for(int i =1;i<n;i++){
					newpre[i-1] = preArr[i];
				}

				printPostOrder(base,newpre,inArr);
			}

			if(base!=n-1){//print right subtree if not empty
				int newpre[] = new int[n-base-1];//for storing copy of array between index [1+base,n)
				int newin[] = new int[n-base-1];
				for(int i =1+base;i<n;i++){
					newpre[i-1-base] = preArr[i];
					newin[i-1-base] = inArr[i];

				}
				printPostOrder(n-base-1,newpre,newin);
			}
			System.out.print(preArr[0]+" ");
		}

		public static void main(String[] args){
			int num;
			Scanner c = new Scanner(System.in);
			num = c.nextInt();
			int preArr[] = new int[num];
			int inArr[] = new int[num];

			for(int i=0;i<num;i++){
				inArr[i] = c.nextInt();
			}

			for(int i=0;i<num;i++){
				preArr[i] = c.nextInt();
			}
			
			printPostOrder(num,preArr,inArr);
		}
	}