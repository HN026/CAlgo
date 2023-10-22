#include <iostream>
#include <vector>

using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

Node* createLL(vector<int> a){
    Node *head = new Node(a[0]);
    Node *tail = head;
    for(int i = 1; i<a.size(); i++){
        Node* t = new Node(a[i]);
        tail->next = t;
        tail = t;
    }    
    return head;
}

void DisplayLL(Node *head){
    Node *temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* ReverseLL(Node *p){
   Node *curr = p;
   Node *prev = NULL;
   Node *ahead = NULL;
   while(curr!=NULL){
    ahead = curr->next;
    curr->next = prev;
    prev = curr;
    curr = ahead;
   }
   return prev;
}

int Count(Node *head){
    Node *temp = head;
    int count = 0;
    while(temp!=NULL){
        count++;
        temp = temp->next;
    }
    return count;
}

Node *ReverseInK(Node *head, vector<int> b, int n, int idx){
    // Base Condition
    if(head==NULL || idx>=n){
        return head;
    }

    int K = b[idx];
    if(K==0){
        return ReverseInK(head, b, n, idx+1);
    }

    Node *curr = head;
    Node *ahead = NULL;
    Node *prev = NULL;

    int cnt = 0;
    
    while(curr!=NULL && cnt<K){
        ahead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;
        cnt++;
    }

    head->next = ReverseInK(ahead, b, n, idx+1);
    return prev;
}

Node *ReverseInGroupsOfK(Node *head, vector<int> b, int n){
    if(head==NULL){
        return NULL;
    }

    head = ReverseInK(head, b, n, 0);
    return head;
}

int main(){
    vector<int> a = {1,2,3,4,5};    
    // Reversing Linked List in groups of K
    vector<int> b = {3,3,5};
    
    Node *head = createLL(a);
    int n = a.size();

    Node *temp = ReverseInGroupsOfK(head, b, n);
    DisplayLL(temp);
    

    return 0;
}