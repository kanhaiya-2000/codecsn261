#include "bits/stdc++.h"

using namespace std;
#define MAX_SIZE 20

char stack_c[MAX_SIZE];
int cur = 0;
bool hasError = false;

int getPriority(char c){
	if(c=='[')
	 return 100;
	else if(c=='{')
		return 10;
	else
		return 1;
}
bool checkPriority(char c){
	if(getPriority(stack_c[cur-1])<getPriority(c)){
		cout<<"Missing priority of pair "<<stack_c[cur-1]<<" and "<<c<<" \n";		
		return false;
	}
	return true;
}
bool checkOrder(char c){
	if(c==')')
		return stack_c[cur-1] == '(';
	else{
		return ((int) stack_c[cur-1] - (int) c ==-2);
	}
}
void push(char c){
	if(cur==0){
 		stack_c[cur++] = c;
 		return;
 	}
 if(checkPriority(c)&&cur!=0){
 	stack_c[cur++] = c;
 } 
 else
 	hasError = true;
}
void pop(char c){
 if(checkOrder(c)){
 	cur = cur - 1;
 }
 else{
 	cout<<"Unbalanced "<<stack_c[cur-1]<<" "<<c<<"\n";
 	hasError = true;
 }
}
char complement(){
	return (stack_c[cur]=='('?')':(stack_c[cur]=='{'?'}':')'));
}
int main(){ 
 string input;
 //take one string per input
 cin>>input;
 int flag=0;
 for(int i =0;i<input.size();i++){
 		 	if(hasError){
 		 		break;
 		 	}
 			if(input[i]=='['||input[i]=='{'||input[i]=='('){
 				if(flag==0)
 					push(input[i]);
 				else{
 					hasError=true;
 					cout<<"Unbalanced at "<<stack_c[cur-1];
 				}
 			}
 			else{
 				flag = 1;
 				pop(input[i]);
 			}
 			if(i==input.size()-1&&cur!=0&&!hasError){
 				hasError = true;
 				cout<<"Unbalanced "<<complement()<<endl;
 			}
 		
 	
 	}
 	if(!hasError)
 		cout<<"No error\n";

}