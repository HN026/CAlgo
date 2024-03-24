#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  public:
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2) {
        ListNode *temp1 = list1;
        ListNode *temp2 = list1;
        for (int i = 0; i < a - 1; i++) {
            temp1 = temp1->next;
        }
        for (int i = 0; i < b; i++) {
            temp2 = temp2->next;
        }

        temp1->next = list2;
        ListNode *t2 = list2;
        while (t2->next != NULL) {
            t2 = t2->next;
        }
        if (temp2->next) {
            t2->next = temp2->next;
        }

        return list1;
    }
};

int main() {
    Solution sol;

    // Create list1: 0->1->2->3->4
    ListNode *list1 = new ListNode(0);
    list1->next = new ListNode(1);
    list1->next->next = new ListNode(2);
    list1->next->next->next = new ListNode(3);
    list1->next->next->next->next = new ListNode(4);

    // Create list2: 1000000->1000001->1000002
    ListNode *list2 = new ListNode(1000000);
    list2->next = new ListNode(1000001);
    list2->next->next = new ListNode(1000002);

    int a = 3, b = 4;

    ListNode *result = sol.mergeInBetween(list1, a, b, list2);

    // Print the resulting list
    while (result != nullptr) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}