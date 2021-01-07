#include <bits/stdc++.h>

using namespace std;

int binarySearch(int arr[],int low,int high,int key){
	if(key<arr[low]||key>arr[high]||low>high)
		return -1;
	int mid = (low+high)/2;
	if(arr[mid]==key)
		return mid;
	else if(arr[mid]>key)
		return binarySearch(arr,low,mid-1,key);
	else
		return  binarySearch(arr,mid+1,high,key);
}
int main(){
	int N,key,res;
	//cout<<"Enter the size of your sorted array\n";
	//cin>>N;
	N = 8;
	int arr[N];
	//cout<<"Enter the elements of your array one-by-one\n";
	for(int i =0;i<N;i++)
		cin>>arr[i];
	//cout<<"\nEnter the key you are looking for finding index\n";
	cin>>key;
	res = binarySearch(arr,0,N-1,key);
	if(res>-1)
		cout<<"\n The index of key element in the array is "<<res;
	else
		cout<<"\nSorry!there is no element matching your key in your array";
	cout<<endl;
	return 0;

}
