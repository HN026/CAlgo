#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode* PartitionList(ListNode *root, int x){
    ListNode* lesser = NULL;
    ListNode* lessTemp = lesser;
    ListNode* bigger = NULL;
    ListNode* biggerTemp = bigger;
    ListNode* temp = root;
    while(temp){
        ListNode *t = new ListNode(temp->val);
        if(temp->val<x){
            if(!lesser){
                lesser = new ListNode(temp->val);
                lessTemp = lesser;
            }
            else{
                lesser->next = t;
                lesser = t;
            }
        }
        else{
            if(!bigger){
                bigger = new ListNode(temp->val);
                biggerTemp = bigger;
            }
            else{
                bigger->next = t;
                bigger = t;
            }
        }
        temp = temp->next;
    }

    if(lesser!=NULL) lesser->next = biggerTemp;
    else return biggerTemp;

    return lessTemp;
}

int main(){
    ListNode *root = new ListNode(1);
    root->next = new ListNode(4);
    root->next->next = new ListNode(3);
    root->next->next->next = new ListNode(2);
    root->next->next->next->next = new ListNode(5);
    root->next->next->next->next->next = new ListNode(2);
    int x = 3;

    ListNode *ans = PartitionList(root, x);

    ListNode* temp = ans;
    while(temp){
        cout<<temp->val<<" ";
        temp = temp->next;
    }
    cout<<endl;

    return 0;
}