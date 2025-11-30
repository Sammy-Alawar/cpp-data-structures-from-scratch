#include <iostream>
#include <unordered_map>
#include <string>
#include <queue> 
#include <stack>
using namespace std;
class Node{
    public:
        Node* next;
        string name;
        int weight;
        int cumDist;
        Node(string n, int w, int c){
            name = n; 
            next = nullptr; //since im inserting at the tail
            weight = w;
            cumDist = c;
        }
        Node(){
            name = "";
            next = nullptr;
        }
};
class minHeap{
    public:
        Node* arr;
        int arrsize;
        int heapsize;
        minHeap(int s){
            arrsize = s;
            arr = new Node[arrsize];
            heapsize = 0;
        }
        void heapifyDown(int i){
            int left = (2*i) + 1;
            int right = (2*i) + 2;
            int min;
            if(right < heapsize){ 
                if(arr[left].cumDist <= arr[right].cumDist){
                    min = left;
                }
                else{
                    min = right;
                }
            }
            else{
                if(left < heapsize){
                    min = left;
                }
                else{
                    return;
                }
            }
            if(arr[i].cumDist > arr[min].cumDist){
                swap(arr[i], arr[min]);
                heapifyDown(min);
            }   
        }
        void heapifyUp(int i){
            int parent = (i - 1)/2;
            if(parent >= 0 && arr[i].cumDist < arr[parent].cumDist){
                Node temp = arr[parent];
                arr[parent] = arr[i];
                arr[i] = temp;
                heapifyUp(parent);
            }
        }
        /*void heapsort(int* currArr){
            arr = currArr;
            for(int i = (heapsize - 1)/2; i >= 0; i--){
                heapifyDown(i);
            }
            for(int i = 0; i < heapsize; i++){
                swap(arr[0], arr[heapsize-1]);
                cout << arr[heapsize-1];
                heapsize--;
                heapifyDown(0);
            }
        }*/
        void insert(Node* d){
            arr[heapsize] = *d;
            heapsize++;
            heapifyUp(heapsize - 1);
        }
        void del(){
            Node temp = arr[0];
            arr[0] = arr[heapsize - 1];
            arr[heapsize - 1] = temp;
            heapsize--;
            heapifyDown(0);
        }
};

class LL{
    public:
        Node* head;
        Node* tail;
        LL(Node* h, Node* t){
            head = h;
            tail = t;
        }  
        LL(){head = nullptr; tail = nullptr;}
};
class Graph{
    public:     
        unordered_map<string, LL>adjlist;
        Graph(){}
        void insert(LL currLL){
            adjlist[currLL.head->name] = currLL;
        }
        void addEdge(Node* from, Node* to, int w){
            Node* newNode = new Node(to->name, w, to->cumDist);
            adjlist[from->name].tail->next = newNode;
            adjlist[from->name].tail = newNode;
        }
        void removeEdge(Node* from, Node* to){
            Node* curr = adjlist[from->name].head;
            while(curr->next->name != to->name){
                curr = curr->next;
            }
            if(curr->next->next == nullptr){
                adjlist[from->name].tail = curr;
            }
            curr->next = curr->next->next;
        }
        void removeNode(Node* node){
            adjlist.erase(node->name);
        }
        
        void BFS(Node* node){
            unordered_map<string, bool>visited;
            Node* currNode = adjlist[node->name].head;
            queue<Node*>q; //FIFO queue
            q.push(currNode);
            visited[currNode->name] = true;
            while(!q.empty()){
                while(currNode != nullptr){
                    if(visited.count(currNode->name) == 0){
                        q.push(currNode);
                        visited[currNode->name] = true;
                    }
                    currNode = currNode->next;
                }
                
                cout << q.front()->name << endl;
                currNode = adjlist[q.front()->name].head;
                q.pop();
                
            }
        }
        /*void DFS(Node* node, unordered_map<string, bool>visited){//using recursion
            Node* currNode = adjlist[node->name].head;
            visited[currNode->name] = true;
            cout << currNode->name;
            while(currNode != nullptr){
                if(visited.count(currNode->name) == 0){
                    DFS(currNode, visited);
                }
                currNode = currNode->next;
            }
        
        }*/
        void DFS(Node* node){//using stack
            unordered_map<string, bool>visited;
            Node* currNode = adjlist[node->name].head;    
            stack<Node*>s; //LIFO stack
            s.push(currNode);
            visited[currNode->name] = true;
            while(!s.empty()){
                while(currNode != nullptr){
                    if(visited.count(currNode->name) == 0){
                        s.push(currNode);
                        visited[currNode->name] = true;
                    }
                    currNode = currNode->next;
                }
                cout << "\n DFS: ";
                cout << s.top()->name << endl;
                currNode = adjlist[s.top()->name].head;
                s.pop();
            }
        }
        void Dijkstra(Node* start, int Nodes){
            start->cumDist = 0;
            Node* curr = adjlist[start->name].head->next;
            unordered_map<string, bool>visited;
            visited[start->name] = true;
            minHeap array(Nodes);
            Node* min;
            int cumD = 0;
            while(curr != nullptr){
                    curr->cumDist = curr->weight;
                    adjlist[curr->name].head->cumDist = curr->cumDist;
                    array.insert(curr);
                    curr = curr->next;
                }
            
            min = &array.arr[0];
            visited[min->name] = true;
            cumD = min->cumDist;
            curr = adjlist[min->name].head->next;
            array.del();
            while(array.heapsize != 0){
                while(curr != nullptr){
                    if(visited.count(curr->name) == 0 && curr->weight + cumD < curr->cumDist){
                        curr->cumDist = curr->weight + cumD;
                        adjlist[curr->name].head->cumDist = curr->cumDist;
                        array.insert(curr);
                    }
                    curr = curr->next;
                }
            min = &array.arr[0];
            cumD = min->cumDist;
            visited[min->name] = true;
            curr = adjlist[min->name].head->next;
            array.del();
            }
            for(auto const& pair:adjlist){
                cout << pair.first << ": " << pair.second.head->cumDist << endl;
            }
            
        }
        Graph Prims(Node* start, int nodes){
            unordered_map<string, bool>visited;
            Graph minSpanningTree;
            for(auto const& pair:adjlist){
                minSpanningTree.adjlist[pair.first] = LL();
                minSpanningTree.adjlist[pair.first].head = new Node(pair.first, 0, 0);
                minSpanningTree.adjlist[pair.first].tail = minSpanningTree.adjlist[pair.first].head;
            }
            visited[start->name] = true;
            int counter = 0;
            minHeap array(nodes);
            Node* curr = adjlist[start->name].head->next;
            Node min;
            while(curr != nullptr){
                curr->cumDist = curr->weight;
                array.insert(curr); 
                curr = curr->next;   
            }
            min = array.arr[0];
            minSpanningTree.addEdge(minSpanningTree.adjlist[start->name].head, &min, min.weight);
            counter++;
            visited[min.name] = true;
            array.del();
            curr = adjlist[min.name].head->next;
            while(counter != nodes - 1){
                while(curr != nullptr){
                    if(visited.count(curr->name) == 0){
                        curr->cumDist = curr->weight;
                        array.insert(curr);
                    }
                    curr = curr->next;
                }
                min = array.arr[0];
                curr = adjlist[min.name].head->next;
                array.del();
                Node* temp;
                Node* from;
                bool found = false;
                for(auto const& pair:visited){
                    from = minSpanningTree.adjlist[pair.first].head;
                    temp = adjlist[pair.first].head->next;
                    while(temp != nullptr){
                        if(temp->name == min.name){
                            found = true;
                            break;
                        }
                        temp = temp->next;
                    }
                    if(found){
                        break;
                    }
                }
                minSpanningTree.addEdge(minSpanningTree.adjlist[from->name].head, &min, min.weight);
                counter++;
            }
            return minSpanningTree;

        }

};
int main(){
    Node n1("n1", 0, 99999999);
    Node n2("n2", 0, 99999999);
    Node n3("n3", 0, 99999999);
    Node n4("n4", 0, 99999999);
    Node n5("n5", 0, 99999999);
    LL L1(&n1, &n1);
    LL L2(&n2, &n2);
    LL L3(&n3, &n3);
    LL L4(&n4, &n4);
    LL L5(&n5, &n5);
    Graph G;
    G.insert(L1);
    G.insert(L2);
    G.insert(L3);
    G.insert(L4);
    G.insert(L5);
    G.addEdge(&n1, &n2, 10);
    G.addEdge(&n1, &n3, 5);
    G.addEdge(&n2, &n3, 2);
    G.addEdge(&n2, &n4, 1);
    G.addEdge(&n3, &n2, 3);
    G.addEdge(&n3, &n4, 9);
    G.addEdge(&n3, &n5, 2);
    G.addEdge(&n4, &n5, 4);
    G.addEdge(&n5, &n4, 6);
    G.addEdge(&n5, &n1, 7);
    G.Dijkstra(&n1, 5);
    G.BFS(&n1);
    Graph G1 = G.Prims(&n1, 5);
    return 0;
}