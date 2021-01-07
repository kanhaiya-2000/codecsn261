#include <bits/stdc++.h>
#define SIZE 10
//i am defining stack of size 10...
//sir if you want to test my code for higher value 
//then please first modify value of SIZE  ( defined just above the comment)
using namespace std;

typedef enum VarType {
	INTE,
	FLOT,
	CHR,
} VarType;
typedef union VarStore{
	int i;
	float f;
	char c;     
} UnionType;
typedef struct _var{
	VarType type;
	UnionType value;
} var;
int current = 0;
int I;
float F;
char C;
void PRINT(var &c){
	switch(c.type){
		case INTE:
		cout<<c.value.i<<'\n';
		break;
		case FLOT:
		cout<<c.value.f<<'\n';
		break;
		case CHR:
		cout<<c.value.c<<'\n';
		break;
		default:
		cout<<"NONE\n";		
		break;
	}
}
bool Full(int d){
	if(d==SIZE)
		return true;
	return false;
}
bool empty(int d){
	if(d==0)
		return true;
	return false;
}
void Push(var &ch,int D){	
	if(!Full(current)){			
		ch.type = INTE;		
		ch.value.i = D;			
	}		
}
void Push(var &ch,float D){
	if(!Full(current)){
		ch.type = FLOT;
		ch.value.f = D;
	}
}
void Push(var &ch,char D){
	if(!Full(current)){
		ch.type = CHR;
		ch.value.c = D;
	}
}
void Pop(var d){
	if(!empty(current)){ 	
		current = current-1;  	
	}
}
int main(){
	char c ;
	char ci;
	var stack[SIZE];
	
	while(true){		
		cout<<"Enter your choice" <<"\n"<<"I for insert, " <<"\n"<<" D for delete," <<"\n"<<" P for Print," <<"\n"<<" E for exit"<<"\n";
		cin>>c;		
		if(c== 'I'){
			if(Full(current)){
				cout<<"\nNo more space for storage.please increase the SIZE value to accomodate more entities\n";
				continue;
			}
			cout<<"Enter ​" <<"\n"<<"I​ for integer," <<"\n"<<" ​C​ for char " <<"\n"<<"and ​F​ for float"<<"\n";
			cin>>ci;
			if(ci=='I'){				
				cout<<"Enter an integer value"<<"\n";
				cin>>I;
				Push(stack[current],I);	
				current++;
			}
			if(ci=='F'){				
				cout<<"Enter a float value"<<"\n";
				cin>>F;
				Push(stack[current],F);
				current++;
			}
			if(ci=='C'){				
				cout<<"Enter a char value"<<"\n";
				cin>>C;
				Push(stack[current],C);
				current++;
			}				
		}
		
		if(c== 'D'){
			Pop(stack[current-1]);
			cout<<"Popped element is ";
			PRINT(stack[current]);
			cout<<'\n';			
		}
		if(c== 'P'){
			cout<<"Current status of stack is ";
			for(int i =current-1;i>=0;i--)
				PRINT(stack[i]);
			cout<<" ";
		}
		if(c== 'E'){
			cout<<"Program is stopped"<<endl;
			break;
		}			
		
		
	}
}