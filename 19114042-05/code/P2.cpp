#include<bits/stdc++.h>
using namespace std;

struct Edge{
  int v1;
  int v2;
  int weight;
  
  struct Edge* next;
};

class FindUnion{
  private:
    int size; 
    int *compSize; 
    int *id; 
    int comp; 
  
  public:
    FindUnion(int n){ 
      this->size = comp = n;
      this->compSize = new int[n];//allocate memory
      this->id = new int[n];//allocate memory
      
      for(int i=0;i<n;i++){
        id[i] = i; 
        compSize[i] = 1; 
      }
    }
    
    int find_parent(int a){      
      int parent = a;
      if(parent != id[parent]){ 
        parent = id[parent];
      }     
      while(a != parent){
        int temp;
        temp = id[a];
        id[a] = parent; 
        a = temp;
      }
      
      return parent;
    }   
    
    void union_kro(int a, int b){ 
      int first = find_parent(a);
      int second = find_parent(b);
      
      if(first==second) return; //both have same parent      
      
      if(compSize[first] < compSize[second]){
        compSize[second] += compSize[first];
        id[first] = second;
      }
      else{
        compSize[first] += compSize[second];
        id[second] = first;
      }
      comp--; 
    }
};

class Graph{
  struct Edge* head;
  public: 
    Graph(){
      head = NULL;
    }
  
  public:
    void addEdge(int a, int b, int w){ 
      struct Edge* newnode = (struct Edge*)malloc(sizeof(struct Edge));
      newnode->v1 = a;
      newnode->v2 = b;
      newnode->weight = w;
      
      struct Edge* current = (struct Edge*) malloc(sizeof(struct Edge));
    
      if(this->head == NULL || this->head->weight >= newnode->weight){        
        newnode->next = this->head;
        this->head = newnode;
      }
      else{
        current = this->head; 
        while(current->next != NULL && current->next->weight < newnode->weight){ 
          current = current->next; 
        }
        newnode->next = current->next;
        current->next = newnode;
      }
    }
    
    struct Edge* temp = (struct Edge*) malloc(sizeof(struct Edge));
    struct Edge* DotHead = temp;
    // Krushkal Algorithm
    int kruskalAlgo(int vertices){
      int W = 0; //to store the weigth of the MST
      
      FindUnion u(vertices);//initialise Findunion class
      struct Edge* current;
      current = this->head;
      
      cout<<"\nNode1  Node2  Weight"<<endl;
      
      while(current != NULL){
        int a = current->v1;
        int b = current->v2;
        
        int parent1 = u.find_parent(a); // finding parent Node of vertex
        int parent2 = u.find_parent(b);
        
        if(parent1 != parent2){ // we are investigating nodes of different parents or components
          cout<<a+1<<"      "<<b+1<<"      "<<current->weight<<endl;
          temp->v1 = a+1;
          temp->v2 = b+1;
          temp->weight = current->weight;
          
          W += (current->weight); 
          u.union_kro(parent1, parent2); 
          temp->next = (struct Edge*) malloc(sizeof(struct Edge));//was causing segfault...
          temp = temp->next;  
        } 
        current = current->next;
      }
      temp = NULL;
      return W;
    }
    
    void DotFile(){ // printing dot file content
      struct Edge* node = DotHead;
      cout<<"graph mst{"<<endl;
      cout<<"    overlap = \"scale\";"<<endl;
      while(node->next != NULL){
        cout<<"    "<<node->v1<<" -- "<<node->v2<<" [label = \""<<node->weight<<"\"];"<<endl;
        node = node->next;
      }
      cout<<"}"<<endl;
    }
      
};

int main(){ 
  Graph gr;  
  bool Visited[100] = {false};  
  int a, b, w;
  int vertices = 0;

  while(cin>>a>>b>>w){    
    gr.addEdge(a-1, b-1, w);
    if(Visited[a-1])
      vertices--;
    if(Visited[b-1])
      vertices--;
    Visited[a-1] = true; 
    Visited[b-1] = true;
    vertices+=2;
  } 
  
  int ans = gr.kruskalAlgo(vertices);//invoke kruskal algo
  cout<<"\nTotal edge-weight of the MST = "<<ans<<endl;
  
  cout<<"\nContents of Dot File are: "<<endl;
  gr.DotFile();  
  return 0;
}
