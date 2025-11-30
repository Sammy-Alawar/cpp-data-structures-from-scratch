#include <iostream>
#include <string>
using namespace std;

class HashTable{
    public:
    class LL{
        public:
        class Node{
            public:
                Node* next;
                string s;
                Node(){
                    s = "  ";
                    next = nullptr;
                }
                Node(Node* n, string ss){
                    next = n;
                    s = ss;
                }
        };
        Node* head;
        Node* tail;
        LL(){
            head = nullptr;
            tail = nullptr;
        }
    };
        LL* arr[1000];
        HashTable(){
            for(int i = 0; i < 1000; i++){
                arr[i] = new LL;
            }
        }
        
        int insert(string s){//inserting at head
            int ind = hash(s);//key
            arr[ind]->head = new LL::Node(arr[ind]->head, s);
            if(arr[ind]->tail == nullptr){
                arr[ind]->tail = arr[ind]->head;
            }
            return ind;
        }
        LL::Node* remove(string s) {
            int ind = hash(s);
            LL::Node* curr = arr[ind]->head;
            LL::Node* prev = nullptr;

            // find the node with string s
            while (curr != nullptr && curr->s != s) {
                prev = curr;
                curr = curr->next;
            }

            // not found
            if (curr == nullptr) {
                return nullptr;
            }

            // case 1: removing head
            if (prev == nullptr) {
                arr[ind]->head = curr->next;
                // if list becomes empty, update tail
                if (arr[ind]->head == nullptr) {
                    arr[ind]->tail = nullptr;
                }
            }
            // case 2: removing middle or tail
            else {
                prev->next = curr->next;
                // if we removed the tail node, update tail
                if (curr->next == nullptr) {
                    arr[ind]->tail = prev;
                }
            }

            return curr; // caller can delete curr if they want
        }

        bool search(string s){
            int ind = hash(s);
            LL::Node* curr = arr[ind]->head;
            while(curr != nullptr){
                if(curr->s == s){
                    return true;
                }
                curr = curr->next;
            }
            return false;
        }
        int hash(string s){
            int ind = 0;
            for(int i = 0; i < s.length(); i++){
                ind = ind + (int)s[i];
            }
            int hashh = ind/s.length();
       
            return hashh;
        }
    
};
int main(){
    HashTable J;
    int ind = J.insert("node1");
    J.insert("node2");
    J.insert("node3");
    HashTable::LL::Node* j = J.arr[ind]->head;
    cout << j->next->next->s << endl;
    return 0;
}