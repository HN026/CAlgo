#include <iostream>
#include <unordered_map>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        unordered_map<int, ListNode*> prefixSumMap;
        int prefixSum = 0;
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while (curr) {
            prefixSum += curr->val;
            if (prefixSum == 0) {
                head = curr->next;
                prefixSumMap.clear();
                curr = head;
                prev = nullptr;
            } else {
                if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                    prev->next = curr->next;
                    prefixSum -= curr->val;
                    curr = prev->next;
                } else {
                    prefixSumMap[prefixSum] = curr;
                    prev = curr;
                    curr = curr->next;
                }
            }
        }

        return head;
    }
};

int main() {
    // Create a linked list
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(-3);
    head->next->next->next = new ListNode(3);
    head->next->next->next->next = new ListNode(1);

    // Create a Solution instance
    Solution sol;

    // Call the method with the linked list
    ListNode* result = sol.removeZeroSumSublists(head);

    // Print the resulting list
    for (ListNode* curr = result; curr != NULL; curr = curr->next) {
        cout << curr->val << " ";
    }

    return 0;
}