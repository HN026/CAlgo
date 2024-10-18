#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList{
    private:
        Node *head;
    public:
        LinkedList(){
            head = NULL;
        }

        void Insert(int data){
            if(head == NULL){
                head = new Node();
                head->data = data;
                head->next = NULL;
            }
            else{
                Node *temp = head;
                while(temp->next != NULL){
                    temp = temp->next;
                }
                temp->next = new Node();
                temp->next->data = data;
                temp->next->next = NULL;
            }
        }
        
        void print(){
            Node *temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};


int main(){

    LinkedList ll = LinkedList();
    ll.Insert(1);
    ll.Insert(2);
    ll.Insert(3);
    ll.print();

    return 0;
}