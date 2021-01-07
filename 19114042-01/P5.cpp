#include <bits/stdc++.h>

using namespace std;

int FoundSuitablePos(int A[],int key,int low ,int high){
 int mid = (low+high)/2 ;
 if (high <= low) 
    return (key > A[low])?  (low + 1): low; 
if(A[mid]==key)
 return mid +1;
else if(A[mid]>key)
 return FoundSuitablePos(A,key,low,mid-1);
else
 return FoundSuitablePos(A,key,mid+1,high);
}

void insertionSort(int A[],int n){
for(int i =1;i<n;i++){
int pos = FoundSuitablePos(A,A[i],0,i-1);
int key = A[i];
for(int j=i-1;j>=pos;j--){
A[j+1] = A[j];
}
A[pos] = key;
}
}
int main(){
	int n; 
	//cout<<"Enter the size of your array\n";
	//cin>>n;
	n = 8;
	//cout<<"Enter the elements of your array one-by-one\n";
	int arr[n];
	for(int i =0;i<n;i++)
	  cin>>arr[i]; 	
	insertionSort(arr, n); 
	//cout << "\nAfter sorting, array is\n"; 
	for(int i =0;i<n;i++)
	  cout<<arr[i]<<" ";
	return 0; 
} 
