#include <bits/stdc++.h>

using namespace std;

struct soldier{	
		int ID;
		struct soldier *next;
} ;
int main(){
	srand (time(NULL));
	cout<<"Enter the value for n ,m and c\n";
	int n,m,c;
	cin>>n>>m>>c;	
	
	soldier *final = NULL;	
	soldier *head = NULL;	
	for(int i =0;i<n;i++){
		struct soldier* tem = (struct soldier*) malloc(sizeof(struct soldier));		
		tem->ID = i+1;
		tem->next = head;
		head = tem;
	}	
	int current[m];
	//this is for storing current stack position for each group of soldier...//
	//I am creating stack using virtual array (to save space) and just storing  position of rear element of each stack
	for(int i =0;i<m;i++){
		current[i] = c-1;
	}
	struct soldier* t ;
	t = head;
	cout<<"Soldiers in the respective Lifts at the Ground Floor are as:\n";
	for(int i =0;i<m;i++){		
		cout<<"Soldier in lift"<<(i+1)<<":";
		for(int j =0;j<c;j++){			
			cout<<"S"<<t->ID<<" ";
			if(t->next)
				t = t->next;
		}		
		cout<<endl;
		
	}
	
	bool loop = true;
	int rn ,id;
	
	struct soldier *header = NULL;
	struct soldier *tem = NULL;
	final = (struct soldier*) malloc(sizeof(struct soldier));
	header = final;
	while(true){

		rn = ((int)(rand()))%m;//choosing 0 to m-1
		id = c*rn + current[rn] + 1;//Error occured at this point because one was not added before
		if(current[rn]>-1){
		current[rn]-- ;			
		tem = NULL;			
		while(final&&final->ID&&final->ID<id){
			tem = final;
			final = final->next;
		}
			
			struct soldier* k = (struct soldier*)malloc(sizeof(struct soldier));			
			k->ID = id;
			k->next = final;
			
			if(tem){//error occured at this point because for the initial case tem was not defined 
			 tem->next = k;
			}
			else{//Be sure to update your header address if current soldier's id is less than the id stored by header
				header = k;
			}
						
		
		 final = header;
		for(int i =0;i<m;i++){
			loop&=(current[i]==-1);
		}
		if(loop)
			break;
		else
			loop = true;
	}
	}
	cout<< "Sorted order :";
	while(header&&header->ID !=0){
		cout<<"S"<<header->ID<<" ";
		header = header->next;
	}
	cout<<endl;
}