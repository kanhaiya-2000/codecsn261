#include <bits/stdc++.h>

using namespace std;


class Expression{
	public:
		int expi;
		int c;
		Expression *next;
};

int main(){
	int iter = 3;
	int n,expi,coeff;
	Expression *head[iter] ;
	Expression *final = new Expression();//there was problem at this point...memory was not allocated which was causing seg fault at line 45
	int p = iter;
	int max = 0;
	//My program is for adding only 3 polynomials..neither greater than 3 nor 
	//less than 3,please change iter value for adding more than 3 polynomials
	//Expression k;
	while(iter--){		
		cin>>n;
		head[2-iter] = new Expression;//allocate memory here as well
		//n is number of terms
		for(int i =0;i<n;i++){
			//Format is power >> coefficient 
			Expression *g = new Expression;			
			cin>>expi>>coeff;
			g->expi = expi;
			g->c = coeff;
			if(expi>max)
				max = expi;
			
			g->next = head[2-iter];
			head[2-iter] = g;
			//delete g; this was causing problem
		}		
        
	}
	iter = p;
	int i =0;
	bool d = false;

	while(true){
		Expression *g = new Expression;
		g->expi = i++;		
		g->c = 0;
		for(int j =0;j<iter;j++){
			Expression *k = head[j];			
			while(head[j]){
			if(head[j]->expi==g->expi)
				g->c +=head[j]->c;
			head[j] = head[j]->next;
			}
			head[j] = k;///the problem was here since i was not restoring back the head[j] pointer...
			//also loop terminating sequence is also specified
		}
		//Below is the most suitable method for inserting into the linked list using either struct or class implementaion...
		g->next = final;
		final = g;		
		
		if(g->expi>=max)
		  break;
		
	}
	// while(final){
	// 	cout<<final->c<<'\t'<<final->exp<<endl;
	// 	final = final->next;
	// }
	while(true){
		if(final->c !=0)
			cout<< final->c<<"x^"<<final->expi;
	    if(final->next&&final->next->c!=0)
		  cout<<" + ";		
		if(final->next){
			final = final->next;			
		}		
		else
			break;
		
	}
}