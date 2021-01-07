#include <bits/stdc++.h>

using namespace std;
void swapping(int* a, int* b){ 
	int k = *a;
	*a = *b;
	*b = k;
}
  
int part (int A[], int low, int high){
	srand(time(NULL)); 
	int random = low + rand() % (high+1-low) ;
	swapping(&A[random],&A[high]); 
	int piv = A[high]; //choosing pivot for quickSort 
	int i = low; 
	for (int j = low; j < high; j++){ 		
		if (A[j] < piv){			 	 
			swapping(&A[i], &A[j]);
			i++; 
			
		} 
	} 
	swapping(&A[i], &A[high]); 
	return i ; 
} 
void Sort(int A[], int low, int high) { 
	if (low < high){		
		int part_index = part(A, low, high); 		
		Sort(A, low, part_index - 1); 
		Sort(A, part_index + 1, high); 
	}	 
} 

int main(){
	int n; 
	//cout<<"Enter the size of your array\n";
	//cin>>n;
	//taking n = 8
	n = 8;
	//cout<<"Enter the elements of your array one-by-one\n";
	int arr[n];
	for(int i =0;i<n;i++)
	  cin>>arr[i];	  
	Sort(arr, 0, n - 1); 
	//cout << "\nAfter Sorting, array is\n"; 
	for(int i =0;i<n;i++)
	  cout<<arr[i]<<" ";
	return 0; 
} 

