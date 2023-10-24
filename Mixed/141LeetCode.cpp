/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    bool hasCycle(ListNode *head) {
        unordered_set<ListNode*> hashTable;
        struct ListNode *temp = head;
        while(temp!=NULL){
            if(hashTable.find(temp) != hashTable.end()){
                return true;
            }
            hashTable.insert(temp);
            temp = temp->next;
        }
        return false;
    }
};
