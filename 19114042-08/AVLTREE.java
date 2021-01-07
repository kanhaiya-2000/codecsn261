import java.util.*; 
class AVLTREE{  

	static  class Node { 
		int element; 
		Node left; 
		Node right; 
	}  

	static Node addNode(int data){ 
		Node node = new Node(); 
		node.element = data; 
		node.left = null; 
		node.right = null; 

		return node; 
	}    

	static Node buildTree(int arr[], int start, int end){ 

		if (start > end) 
			return null;   

		int mid = (start + end) / 2; 
		Node root = addNode(arr[mid]); 


    root.left = buildTree(arr, start, mid - 1); //build left subtree

    
    root.right = buildTree(arr, mid + 1, end); //build right subtree

    return root; 
}

static void printAVLOrderByBST(Node root){
	if(root!=null){  
		Queue<Node> q = new LinkedList<Node>(); 

		q.add(root);  

		while (q.size()>0) 
		{  
			Node node = q.element();  
			System.out.print( node.element + " ");  
			q.remove();  
			if (node.left != null)  
				q.add(node.left);  
			if (node.right != null)  
				q.add(node.right);  
		}  
	}
}  

public static void main(String args[]){  

	Scanner c = new Scanner(System.in);

	int n = c.nextInt();
    int nodelist[] = new int[n];//store all nodes here
    for(int i =0;i<n;i++)
    	nodelist[i] = c.nextInt();
    Arrays.sort(nodelist);    
    Node root = buildTree(nodelist, 0, n - 1); 
    printAVLOrderByBST(root); 

} 
} 