#include<iostream>

using namespace std;
#define MAX_NODE 100
struct list{
    int data;
    list *next;
    list *second;
};
class MyList{   
    struct list* head;
    struct list* duplicate;
    public:
        int ref[MAX_NODE] = {0};       
        void createNode(int data){
           list *n = (struct list*)malloc(sizeof(struct list));
           n->data = data;
           if(head != NULL)
            ref[head->data]++;//head is being referenced by n 
           n->next = head;
           head = n;
        }
        void connectNode(int data,int secondData){
          list *temp = head;
          list *temp2 = head;
          while(temp->data!=data)
            temp = temp->next;        
        while(temp2->data!=secondData){
            temp2 = temp2->next;
        }
        ref[temp2->data]++;//temp2 is being referenced by temp
        temp->second = temp2;
    }
    void duplicateList(){        
        TraverseList();
        list *temp = head;
        list* duplicatehead = NULL;
        while(temp){
            list *i = (struct list*)malloc(sizeof(struct list));
            i->data = temp->data;
            i->second = temp->second;
            i->next = temp->next;
            duplicate = i;
            if(duplicatehead==NULL)
               duplicatehead = duplicate;
            duplicate = duplicate->next;
            temp = temp->next;
        }
        duplicate = duplicatehead;
        cout<<"\nContent of duplicate list\n"<<endl;
        cout<<"Node   next    second"<<endl;
        cout<<"----------------------------"<<endl;       
        while(duplicatehead){
            if(duplicatehead->next)
                cout<<duplicatehead->data<<"   \t"<<duplicatehead->next->data<<"  \t"<<duplicatehead->second->data<<endl;
            else
                cout<<duplicatehead->data<<"   \t"<<"x"<<"   \t"<<duplicatehead->second->data<<endl;
            duplicatehead = duplicatehead->next;
        }
    }
    void TraverseList(){
      cout<<"Node   next    second"<<endl;
      cout<<"----------------------------"<<endl;
      list *te = head;
      while(te){
          if(te->next)
            cout<<te->data<<"  \t"<<te->next->data<<"  \t"<<te->second->data<<endl;
          else
            cout<<te->data<<"  \t"<<"x"<<"  \t"<<te->second->data<<endl;
            te = te->next;
      }
    }

    void DeleteNode(int data){
        list *temp = head;
        list *temp2 = head;
        list *prev;
       
        while(temp->data!=data){
            prev = temp;
            temp = temp->next;
        }
        while(temp2){
            if(temp2->second==temp){
                temp2->second = temp->second;
            }
            temp2= temp2->next;
        }
        prev->next = temp->next;
        TraverseList();

    }
    void printHighestRefNode(int n){
        int arr[2] = {0};//for storing max referenced node data
        for(int i =0;i<n;i++){
            if(ref[i]>arr[0]){
                arr[1] = i;//giving node data
                arr[0] = ref[i];//gives number of reference ,total number of direct reference + second reference
            }
        }
        cout<<"\nHighest reference Node->"<<arr[1]<<" with total reference "<<arr[0]<<endl;
    }
    void printWithDFS(list *curr,int data,bool visited[],int a[],bool fa[],int &count,int n){
      if(curr==NULL||visited[curr->data]||fa[curr->data])
        return;
      visited[curr->data]=true;
      if(curr->data==data){
        cout<<"Cycle :"<<count<<"-->"<<data<<" ";
        for(int i=0;i<n;i++){
          if(a[i]==0)
            break;
          cout<<a[i]<<" ";
        }
        cout<<curr->data<<" "<<endl;
        visited[curr->data] = false;
        count++;
        return;
      }
      int p = -2;
      for(int i=0;i<n;i++){
        if(a[i]==0){
          p=i;
          break;
        }
      }
      a[p] = curr->data;
      printWithDFS(curr->next,data,visited,a,fa,count,n);
      printWithDFS(curr->second,data,visited,a,fa,count,n);
      visited[curr->data] = false;
      a[p] = 0;
      return;
    }
    void PrintCyCLE(int n){
      list *t = head;
      bool fa[2*n] = {false};
      int count=1;
      for(int i =1;i<n;i++){
        int det[2*n] = {0};
        bool visited[2*n] = {false};
        if(t->next)
          printWithDFS(t->next,i,visited,det,fa,count,n);
        printWithDFS(t->second,i,visited,det,fa,count,n);
        fa[i] = true;
        t = t->next;
      }
  }
};

int main(){
  MyList l;
  int n,a,b;
  //connect nodes with first pointer
  //createNode(node->data)
  cin>>n;
  for(int i=0;i<n;i++)
   l.createNode(n-i);   
   
   //connectNode is basically for connecting to the second node
   //connectNode(first_node->data,second_node->data)
   for(int i=0;i<n;i++){
    cin>>a>>b;
    l.connectNode(a,b);
  }
   /*l.connectNode(2,1);
   l.connectNode(3,5);
   l.connectNode(4,3);
   l.connectNode(5,2);*/
   l.duplicateList();
   cout<<"\nList after deleting Node 3\nI have commented out the part for deleting node so that in printing cycle,\nall node will be printed";
   //Delete node 3

   //please uncomment out below code to delete node 3

   //l.DeleteNode(3);
   
  //number of reference for each node was counted on fly while the list was being created
   l.printHighestRefNode(n);
   //Max number of cycles that can be found is pow(2,n) - n - 1
   //So We can detect all cycles by examining each group of node 
   //Below is the method to implement.
   l.PrintCyCLE(n);   
}