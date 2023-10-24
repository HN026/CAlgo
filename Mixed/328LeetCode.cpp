/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL){
            return NULL;
        }
        ListNode *temp = head;
        ListNode *even = NULL;
        ListNode *odd = NULL;
        ListNode *estart = NULL;
        ListNode *ostart = NULL;
        int count = 1;

        while(temp!=NULL){
            if(count%2==0){
                if(even==NULL){
                    ListNode *t = new ListNode(temp->val);
                    even = t;
                    estart = even;
                }
                else{
                    ListNode *t = new ListNode(temp->val);
                    even->next = t;
                    even = t;
                }
            }
            else if(count%2!=0){
                if(odd==NULL){
                    ListNode *t = new ListNode(temp->val);
                    odd = t;
                    ostart = odd;
                }
                else{
                    ListNode *t = new ListNode(temp->val);
                    odd->next = t;
                    odd = t;
                }
            }
            temp = temp->next;
            count++;
        }

        
        odd->next = estart;
        
        return ostart;
        
    }
};
