#include <bits/stdc++.h>

using namespace std;

void reverseArray(int [],int);
void swap(int* a, int* b){ 
	*a = *a+*b; 
	*b = *a-*b; 
	*a = *a-*b; 
}
int main(){
	int n; 
	//cout<<"Enter the size of your array\n";
	//cin>>n;
	//taking n = 6
	n = 6;
	//cout<<"Enter the elements of your array one-by-one\n";
	int arr[n];
	for(int i =0;i<n;i++)
	  cin>>arr[i]; 	
	reverseArray(arr, n); 
	//cout << "\nAfter reversing, array is\n"; 
	for(int i =0;i<n;i++)
	  cout<<arr[i]<<" ";
	return 0; 
} 
void reverseArray(int A[],int len){
  for(int i =0;i<len/2;i++){
    swap(&A[i],&A[len-1-i]);    
  }
}
