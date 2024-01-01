#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x): data(x), next(NULL) {}
};

Node *RotateList(Node *head, int k){
    if(!head || k==0 || !head->next) return head;
    Node *last = head;
    int cnt = 0;
    while(last->next){
        cnt++;
        last = last->next;
    }
    cnt++;
    int effK = 0;
    if(k<=cnt) effK = cnt-k;
    else{
        int z = k%cnt;
        effK = cnt-z;
    }

    for(int i = 0; i<effK; i++){
        Node *tempfirst = head;
        Node *templast = tempfirst;
        tempfirst = tempfirst->next;
        templast->next = NULL;
        last->next = templast;
        last = templast;
        head = tempfirst;
    }

    return head;
}


int main(){
    Node *head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);

    int k = 4;

    Node *ans = RotateList(head, k);

    while(ans){
        cout<<ans->data<<" ";
        ans = ans->next;
    }
    
    return 0;
}