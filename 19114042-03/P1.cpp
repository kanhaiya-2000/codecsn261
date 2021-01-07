#include "bits/stdc++.h"

using namespace std;

typedef struct passengers{
	int row;
	char column;
	string ID;
} passengers;

bool checkEverythingok(string a,char c,int r,passengers *p){
	if(p->ID!=""){
		cout<<"There is already a passenger at this seat \n";
		return false;
	}	
	return true;
}
bool checkIfExists(string a,char c,int r,passengers *p){
	if(p->ID==""){
		cout<<"No record is found for the given sit number \n";
		return false;
	}
	if(p->ID !=a){
		cout<<"Your given ID didnt match with customer at that seat \n";
		return false;
	}
	return true;
}
void Entry(passengers *p,string ID,int row,char column){	
	if(checkEverythingok(ID,column,row,p)){
		cout<<"Push "+ID<<'\n';		
		p->row = row;		
		p->column = column;
		p->ID = ID;
	}	
}
void Exit(passengers *p,string ID,int row,char column){	
	if(checkIfExists(ID,column,row,p)){
		cout<<"Pop "+ID<<'\n';
		p->ID = "";
	}
}
void Print(passengers *p){
	if(p->ID!=""){
		cout<<p->ID<<'\t';
	}
	else{
		cout<<"0"<<'\t';
	}
}
void FullExit(passengers *p){
	if(p->ID!="")
		cout<<"Pop "+p->ID<<'\n';
	p->ID = "";
}
int main(){
	int ROW;
	cin>>ROW;
	passengers p[ROW][2][3];	
	while(true){
	cout<<"Enter your choice"<<'\n'<<"E1 for passenger entry"
	<<'\n'<<"E2 for passenger exit"<<'\n'
	<<"E for program exit"
	<<'\n'<<"P for print "<<'\n'<<" X for full exit ";
	string c;
	bool insert = true;
	cin>>c;
	if(c== "E1"){
		string ID;
		char column;
		int row;
		cout<<"Enter passenger ID, ​boarding ​row number​ and ​Seat number​"<<'\n';
		cin>>ID>>row>>column;
		for(int i =0;i<5;i++){
			for(int j =0;j<6;j++){
				if(p[i][j/3][j%3].ID==ID){
				cout<<"A passenger is already there with this id"<<endl;
				insert = false;
				break;
			}
		}
	}
	 	if(insert){
	 		int k = ((int)column - 65)/3;
	 		int pos = 2 ;
	 		if(k>0){	 			
	 			while(pos!=(70 - (int)column)%3){
	 				if(p[row-1][k][pos].ID!="")
	 					cout<<"Pop "+p[row-1][k][pos].ID<<'\n';
	 				pos --;
	 			}
				Entry(&p[row-1][k][pos],ID,row,column);				
				while(++pos!=3){
	 				if(p[row-1][k][pos].ID!="")
	 					cout<<"Push "+p[row-1][k][pos].ID<<'\n';	 				
	 			}
	 		}
			else{				
				while(pos!=((int)column - 65)%3){
	 				if(p[row-1][k][pos].ID!="")
	 					cout<<"Pop "+p[row-1][k][pos].ID<<'\n';
	 				pos --;
	 			}
				Entry(&p[row-1][k][pos],ID,row,column);
				while(++pos!=3){
	 				if(p[row-1][k][pos].ID!="")
	 					cout<<"Push "+p[row-1][k][pos].ID<<'\n';	 				
	 			}
			}
	 	}
		insert = true;	
	}
	if(c== "E2"){
		string ID;
		char column;		
		int row;
		cout<<"Enter passenger ID, ​boarding ​row number​ and ​Seat number​"<<'\n';
		cin>>ID>>row>>column;		
		int k = ((int)column - 65)/3;
		int pos = 2;
		if(k>0){
			while(pos!=(70 - (int)column)%3){
	 			if(p[row-1][k][pos].ID!="")
	 				cout<<"Pop "+p[row-1][k][pos].ID<<'\n';
	 			pos --;
	 		}
			Exit(&p[row-1][k][pos],ID,row,column);
			while(++pos!=3){
	 			if(p[row-1][k][pos].ID!="")
	 				cout<<"Push "+p[row-1][k][pos].ID<<'\n';	 				
	 		}
		}
		else{
			while(pos!=((int)column - 65)%3){
	 			if(p[row-1][k][pos].ID!="")
	 				cout<<"Pop "+p[row-1][k][pos].ID<<'\n';
	 			pos --;
	 		}
			Exit(&p[row-1][k][pos],ID,row,column);
			while(++pos!=3){
	 			if(p[row-1][k][pos].ID!="")
	 				cout<<"Push "+p[row-1][k][pos].ID<<'\n';	 				
	 		}
		}
	}
	if(c== "P"){
		cout<<"Flight occupancy status :\n";
		for(int i =0;i<5;i++){
			for(int j =0;j<6;j++){
				if(j==3)
					cout<<"\t";
				Print(&p[i][j/3][j%3]);	
			}
			cout<<"\n";
		}
	}
	if(c== "X"){
		for(int i =0;i<5;i++){
			for(int j =0;j<6;j++){
				int k = j<3?3-j:j-3 ;
				FullExit(&p[i][j/3][k%3]);	
			}
		}
	}
	if(c=="E")
		break;
  }
}