#include <iostream>
using namespace std;
class List{
    public:
        class LLNode{
            public:
                int data;
                LLNode *next;
                LLNode *prev;
                LLNode(int d, LLNode *n=NULL, LLNode *p=NULL){
                    data = d;
                    next = n;
                    prev = p;
                }
                ~LLNode(){
                    delete next;
                   
                }
        };
        LLNode *head;
        LLNode *tail;
        int size;
        List(){
            head = NULL;
            tail = NULL;
            size = 0;
        }
        ~List(){
            delete head;
        }
            LLNode *insertAtHead(int d){
                LLNode *n = new LLNode(d, head, NULL);
                if(head != NULL){
                    head->prev = n;
                }
                else{
                    tail = n;
                }
                head = n;
                size++;
                return head;
            }
            LLNode *insertAtTail(int k){
                LLNode *n = new LLNode(k, NULL, tail);
                if(tail != NULL){
                    tail->next = n;
                }
                else{
                    head = n;
                }
                tail = n;
                size++;
                return tail;
            }
            LLNode *insertAfter(int d, LLNode *after){
                LLNode *n = new LLNode(d, after->next, after);
                after->next->prev = n;
                after->next = n;
                size++;
                return n;
            }
            LLNode *delNode(LLNode *n1){
                if(n1 == head){
                    n1->next->prev = NULL;
                    head = n1->next;
                    size--;
                }
                else if(n1 == tail){
                    n1->prev->next = NULL;
                    tail = n1->prev;
                    size--;
                }
                else{
                    n1->next->prev = n1->prev;
                    n1->prev->next = n1->next;
                    size--;
                }
                return n1;
            }

};

int main(){
     List myList;

    // Insert nodes at head
    myList.insertAtHead(3);
    myList.insertAtHead(2);
    myList.insertAtHead(1);

    // Insert nodes at tail
    myList.insertAtTail(4);
    myList.insertAtTail(5);

    // Insert node after a specified node
    List::LLNode *afterNode = myList.head->next->next;
    myList.insertAfter(2690, afterNode);
    List::LLNode *curNode = myList.head;
    while (curNode != NULL) {
        cout << curNode->data << " ";
        curNode = curNode->next;
    }
    cout << "\nHead: " << myList.head->data << " || Tail: " << myList.tail->data << endl;
    // Delete a specified node
    List::LLNode *delNode = myList.tail->prev;
    
    myList.delNode(delNode);
    

    // Print the contents of the list
    List::LLNode *currNode = myList.head;
    while (currNode != NULL) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << "\nHead: " << myList.head->data << " || Tail: " << myList.tail->data << endl;

    return 0;
}
    
