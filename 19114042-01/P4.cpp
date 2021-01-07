#include <bits/stdc++.h>
#define RANGE 4
using namespace std;

/*int convertTobinaryFormat(int r){
  int k = 0; 
  for (int i = 8; i >0; i++)
  {   
    k += (r % (int)pow(2,i))*(int)pow(10,i-1);    
  }
  return k;
    
}*/
void countSort(int A[], int size, int level)
{
  int o[size];
  int c[RANGE] ;
  for(int i =0;i<RANGE;i++){
    c[i] = 0;
  }
  for (int i = 0; i < size; i++)
  {
    c[(A[i]/level)%4]++;
    }
    for (int i = 1; i < RANGE; i++)
      c[i] += c[i - 1];
    for (int i = size - 1; i >= 0; i--)
    {      
        o[c[(A[i]/level)%4]-1] = A[i];
        c[(A[i]/level)%4]--;
      }
    
    for (int i = 0; i < size; i++)
      A[i] = o[i];
  
}
void bitRadixSort(int A[], int N)
{
  int level = 1;
  int max ;
  for(int i =1;i<N;i++){
    max = A[0];
    if(A[i]>A[0])
      max = A[i];
  }
  for (int i = 1; level <max*4; i++){         
    countSort(A, N, level);
    level *=4;    
  }
}

int main()
{
  //cout << "Enter the number of integers you want to input\n";
  int N;  /*
  cin >> N;*/
  N = 8;
  //taking value of N as 8
  int rand[N];    
  //cout << "Enter " << N << " decimal number between 0 and 255" << endl;
  for (int i = 0; i < N; i++)
  {
    cin >> rand[i];
    /*if (rand[i] < 0 || rand[i] > 255)
    {
      cout << "Please enter value between 0 and 255 only" << endl;
      i = i - 1;
    }*/
  }
 
  bitRadixSort(rand, N);
  for(int i =0;i<N;i++)
    cout<<rand[i]<<" ";
  cout<<endl;
  return 0;
}
