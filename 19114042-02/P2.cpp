#include <bits/stdc++.h>

using namespace std;

struct Student{
	string ID;
	string full_name ;
	string course_code;
	string branch;
	int age;
	struct Student* next;

};
void printSortedList(Student *h,int N){
	while(h){
		cout<<h->ID<<'\t'<<h->full_name<<'\t'<<h->course_code<<'\t'<<h->age<<'\t'<<h->branch<<endl;
		h = h->next;
	}
}
int main(){ 
	char s;
	int N;
	cout<<"Enter the number of students"<<endl;
	cin>>N; 
	struct Student* head = NULL;
	struct Student* a = NULL; 
	struct Student*b = NULL;   
	for(int i =0;i<N;i++){
		struct Student* S = (struct Student*) malloc(sizeof(struct Student));     		
		cout<<"Enter the choice for student "<<i+1<<"\nR​ for Roll number\nM for mobile number\nO for other unique ID\n"; 	

		cin>>s;
		string next = (s=='R'||s=='r')?"Roll number":((s=='m'||s=='M')?"10-digit mobile number":"Other unique id"); 				
		cout<<"Enter the "<<next<<" for student "<<i+1<<endl;
		string I;
		string St;
		cin>>I;
		S->ID = I;
		cout<<"Enter full name of student "<<i+1<<endl;
		cin.ignore();
		getline(cin,St);
		S->full_name = St; 
		cout<<"Enter course code for student "<<i+1<<endl;
		cin>>I;
		S->course_code = I; 	
		int age;
		cout<<"Enter the age for student "<<i+1<<endl;
		cin>>age;
		S->age = age; 	 	
		cout<<"Enter branch for student "<<i+1<<endl;
		cin>>I;
		S->branch = I;
			    
		S->next = head;
		head = S;
		a = head->next;
		b = head->next;
		while(a){
			if(head->age < a->age){    	   	
				break;
			}
			else{
				if(a->next&&(head->age < a->next->age)){
					head ->next = a->next;
					a->next = head ; 
					head = b; 
					break;	
				}
				if(a->next==NULL){
					a->next = head;
					head = b;
					a->next->next = NULL;					
					break;
				}
				a = a->next;    		    		
			}    	
		}
		
		
	}
	printSortedList(head,N);	
	return 0;
}