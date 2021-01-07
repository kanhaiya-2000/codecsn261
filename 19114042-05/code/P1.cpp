#include <bits/stdc++.h>
using namespace std;

class Queue {
  private:
    struct Element {
      int id;
      struct Element* next;
    };
    struct Element* front;
    struct Element* rear;
    
  public:
    Queue () {
      front = NULL;
      rear = NULL;
    }

    // define empty() method
    bool empty() {
      return this->front == NULL;
    }
   //define enqueue() method
    void enqueue(int id){
      struct Element* e = new Element();
      e->id = id;
      e->next = NULL;
      if(this->empty()) 
      { 
        this->front = e;
        this->rear = e;
      } else {
        this->rear->next = e;
        this->rear = e;
      }
      return;
    }
    // dequeue() method
    int dequeue(){ 
      int id = this->front->id;
      if(this->front == this->rear){ // for single element in queue
        this->front = NULL;
        this->rear = NULL;
      } else { 
        this->front = this->front->next;
      }
      return id; // return id
    }
};

class Graph {
  private:
    struct Vertex {
      int id;
      struct Vertex* next;
    };
    struct Vertex** list; // define adjaceny list
    int n; // number of vertices
    bool* dfs_b; // boolean value for checking dfs traversal of a vertex
  public:
    Graph(int numEdge) {      
      this->n = numEdge+2;
      this->dfs_b = new bool[n];
      list = new Vertex*[n];//allocate memory to adjacency list

      for (int i=0; i<n; i++) {
        list[i] = NULL;
        dfs_b[i] = false;
      }
    }

    void addEdge(int a, int b) {
      if (list[a] == NULL) {
        list[a] = new Vertex();
        list[a]->next = NULL;
        list[a]->id = a;
      }
      if (list[b] == NULL) {
        list[b] = new Vertex();
        list[b]->next = NULL;
        list[b]->id = b;
      }
      struct Vertex *newVertex = new Vertex();
      newVertex->id = b;
      newVertex->next = list[a]->next;
      list[a]->next = newVertex;

      newVertex = new Vertex();
      newVertex->id = a;
      newVertex->next = list[b]->next;
      list[b]->next = newVertex;
    }
    
    void bfs(int x) {
      bool bfs_t[this->n] = {false};
      Queue q;
      q.enqueue(x);
      bfs_t[x] = true;  
      cout << x << " ";
      int v;
      while (!q.empty()) {
        v = q.dequeue();
        struct Vertex *vertex = this->list[v]->next;
        while (vertex != NULL) {
          int t = vertex->id;
          vertex = vertex->next;
          if (bfs_t[t]) continue;
          bfs_t[t] = true;
          q.enqueue(t);
          cout << t << " ";          
        }
      }
      return;
    }

    void dfs(int x) {
      if (this->dfs_b[x]) return;

      cout << x << " ";
      this->dfs_b[x] = true;
      struct Vertex *vertex = this->list[x]->next;
      while (vertex != NULL) {
        this->dfs(vertex->id);
        vertex = vertex->next;
      }
      return;
    }  
    bool detectCycle() {
      bool bfs_t[this->n] = {false};//defining boolean for bfs traversal
      int parent[this->n] = {0};

      Queue q;
      q.enqueue(1);
      bfs_t[1] = true;  
      parent[1] = -1;
      
      int v;
      while (!q.empty()) {
        v = q.dequeue();
        struct Vertex *vertex = this->list[v]->next;
        while (vertex != NULL) {
          int t = vertex->id;
          vertex = vertex->next;
          
          if (bfs_t[t]) {
            if (t == parent[v]) {
              continue;
            } else {
              return true;
            }
          }
          parent[t] = v;
          bfs_t[t] = true;
          q.enqueue(t);
        }
      }
      return false;
    }
  //reference from internet for calculating max depth
    void maxDepth(int arr[]) {
      int depth[this->n] = {0};
      bool bfs_t[this->n] = {false};

      int x = arr[0];
      Queue q;
      q.enqueue(x);
      bfs_t[x] = true;  
      
      int v;
      while (!q.empty()) {
        v = q.dequeue();
        int d = depth[v] + 1;
        struct Vertex *vertex = this->list[v]->next;
        while (vertex != NULL) {
          int y = vertex->id;
          vertex = vertex->next;
          if (bfs_t[y]) continue;
          bfs_t[y] = true;
          depth[y] = d;
          q.enqueue(y);          
        }
      }
      int maxDepth = 0, maxDepthIndex=0;
      for (int i=1; i<n; i++) {
        if (depth[i] > maxDepth) {
          maxDepthIndex = i;
          maxDepth = depth[i];
        }
      }
      arr[0] = maxDepthIndex;
      arr[1] = maxDepth;
      
      return;
    }

    int getDiameter() {
      int values[2] = {1, -1};
      this->maxDepth(values);
      values[1] = 0;
      this->maxDepth(values);
      return values[1];
    }
};

int main() 
{
  int e;
  cin>> e;

  // Initialise graph
  Graph gp(e);

  int a, b;
  int total_nodes=0;
  while (e--) {
    cin>>a>>b;
    gp.addEdge(a, b);
  }
  

  // BFS
  cout << "1. ";
  gp.bfs(1);

  // DFS
  cout << "\n2. ";
  gp.dfs(1);

  // cycle
  cout << "\n3. Cycle: ";
  cout << ( gp.detectCycle() ? "Yes" : "No" );

  // diameter
  cout << "\n4. Diameter: " << gp.getDiameter();

  cout<<"\n";
  return 0;
}
