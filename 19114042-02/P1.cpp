#include <bits/stdc++.h>

using namespace std;
void swap(int *a,int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
void findKth(int A[],int k,int N){
	for(int i =0;i<k;i++){
		for(int j =i+1;j<N;j++){
			if(A[i]>A[j])
				swap(&A[i],&A[j]);
		}
	}
}
int main()
{
	int N,k;
	cout<<"Enter the size of array"<<endl;
	cin>>N;
	cout<<"Enter the elements"<<endl;
	int A[N];
	for(int i =0;i<N;i++)
		cin>>A[i];
	cout<<"Enter the Kth smallest you want to find"<<endl;
	cin>>k;
	findKth(A,k,N);	
	cout<<"Kth smallest element is "<<A[k-1]<<endl;
	return 0;
}