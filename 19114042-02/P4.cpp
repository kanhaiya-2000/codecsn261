#include <bits/stdc++.h>
#define SIZE 10
//SAME here as earlier one,here i am restricting the size of queue to 10
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
int front =-1 ;
int back = -1;
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
		cout<<"NONE"<<'\n';		
		break;
	}
}
bool Overflow(){
	return (back+1)%SIZE==front;
}
bool Underflow(){	
	return front==-1;
}
void Initiate(char ins){
	switch(ins){
		case 'I':
		if(front==-1){
			front = 0;			
		}
		back = (back+1)%SIZE;
		break;
		case 'D':
		if(back==front){
			front = back = -1;
		}
		break;
	}
}
void Insert(var &ch,int D){    
	if(!Overflow()){			
		ch.type = INTE;		
		ch.value.i = D;
		Initiate('I');			
	}
	else{
		cout<<"Overflow"<<'\n';
	}

}
void Insert(var &ch,float D){	
	if(!Overflow()){
		ch.type = FLOT;
		ch.value.f = D;
		Initiate('I');
	}
	else{
		cout<<"Overflow"<<'\n';
	}

}
void Insert(var &ch,char D){	
	if(!Overflow()){
		ch.type = CHR;
		ch.value.c = D;
		Initiate('I');
	}
	else{
		cout<<"Overflow"<<'\n';
	}
}
void Delete(var &ch){		
	Initiate('D');
	if(!Underflow()){ 	
		front = (front+1)%SIZE;  	
	}
	else{
		cout<<"underflow"<<'\n';
	}
}
int main(){
	char c ;	
	char ci;
	var cqueue[SIZE];
	while(true){		
		cout<<"\nEnter your choice"<<"\n"<<"I for insert,"<<"\n"<<"D for delete,"<<"\n"<<"P for Print,"<<"\n"<<"E for exit"<<"\n";
		cin>>c;		
		if(c== 'I'){				
			cout<<"Enter ​"<<"\n"<<"I​ for integer,"<<"\n"<<" ​C​ for char "<<"\n"<<"and ​F​ for float"<<"\n";
			cin>>ci;
			if(ci=='I'){				
				cout<<"Enter an integer value"<<"\n";
				cin>>I;
				Insert(cqueue[(back+1)%SIZE],I);			
			}
			if(ci=='F'){				
				cout<<"Enter a float value"<<"\n";
				cin>>F;
				Insert(cqueue[(back+1)%SIZE],F);	
			}
			if(ci=='C'){				
				cout<<"Enter a char value"<<"\n";
				cin>>C;
				Insert(cqueue[(back+1)%SIZE],C);			
			}				
		}

		if(c== 'D'){
			cout<<"Deleted element is ";
			if(front>-1)
				PRINT(cqueue[front]);
			Delete(cqueue[front]);					
		}
		if(c== 'P'){
			cout<<"Current status of queue is ";
			if(back>=front){
				for(int i =front;i<back+1;i++)
					PRINT(cqueue[i]);
			}
			else{
				for(int i =front;i<SIZE;i++)
					PRINT(cqueue[i]);
				for(int i =0;i<=back;i++)
					PRINT(cqueue[i]);
			}
		}
		if(c== 'E'){
			cout<<"Program is stopped\n";
			break;
		}	

	}
}