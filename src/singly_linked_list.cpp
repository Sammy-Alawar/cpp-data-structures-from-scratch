#include <iostream>
using namespace std;
class List{
    public:
        class LLNode{
            public:
            int data;
            LLNode *next;
            public:
            LLNode(const int &d, LLNode *n = NULL){
                data = d;
                next = n;
            }
            ~LLNode(){
                delete next;
            }
        };
    
        LLNode *head;
        LLNode *tail;
        unsigned int size;
        List(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
        ~List(){
            delete head;
        }
        LLNode *insert(const int &d){
            head = new LLNode(d, head);
            if(tail == NULL){
                tail = head;
            }
            size++;
            return head;
        }
        
        LLNode *insertAfter(const int &k, int j){
            LLNode *z = find(k);
            LLNode *n;
            if(z != NULL){
            if(z == head && k == head->data){
                n = new LLNode(j, head->next);
                head->next = n;
                size++;
            
            }
            
            else if(z->next == tail){
                n = new LLNode(j, NULL);
                tail->next = n;
                tail = n;
                size++;
                
            }
            else{
                n = new LLNode(j, z->next->next);
                z->next->next = n;
                size++;
                
            }
            return n;
            }
            else{
                cout << "Node not found." << endl;
                return NULL;
            }
        }

        LLNode *find(int i){
            LLNode *temp = head;
            if(temp->data == i){
                return temp;
            }
            while(temp->next != NULL){
                if(temp->next->data == i){
                    return temp;
                }
                temp = temp->next;
            }
            return NULL;
        }
        LLNode *removeNode(int d){
            LLNode *i = find(d);
            
                if(i != NULL){
                    if(i == head && i->data == d){
                        head = head->next;
                        
                        size--;
                         
                        return i;
                    }
                    else if(i->next == tail){
                        
                        i->next = NULL;
                        tail = i;
                        size--;
                       
                        return i;
                    }
                    else{
                        i->next = i->next->next;
                        
                        size--;
                        return i;
                    }
                }
                else{
                    cout << "Node not found" << endl;
                }
            return i;
        }
            
            
};



int main() {
    List myList;
    int n = 0;
    cout << "Enter values and terminate with -1: ";
    while(cin >> n && n != -1){
        myList.insert(n);
    }
    int j;
    cout << "Enter value of node you would like to remove: " ;
    cin >> j;
    List :: LLNode *curr = myList.removeNode(j);
    
    if(curr != NULL){
        List :: LLNode *temp = myList.head;
        for(int i = 0; i < myList.size; i++){
            cout << temp->data << ' ';
            temp = temp->next;
        }
        }
        cout << "\n" << "Tail: " << myList.tail->data << " Head: " << myList.head->data << endl;
    int h;
    cout << "After which node would you like to insert your new Node? ";
    cin >> h;
    cout << "\n" << "Enter value of your new Node: ";
    int y;
    cin >> y;
    List :: LLNode *cur = myList.insertAfter(h,y);
    if(cur != NULL){
        List :: LLNode *temp = myList.head;
         for(int i = 0; i < myList.size; i++){
            cout << temp->data << ' ';
            temp = temp->next;
        }
    }
    cout << endl;
    

    return 0;
}
