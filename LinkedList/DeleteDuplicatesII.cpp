#include <iostream>
#include <unordered_map>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        std::unordered_map<int, int> unique;
        ListNode *temp = head;
        while (temp != nullptr) {
            unique[temp->val]++;
            temp = temp->next;
        }

        ListNode *ans = new ListNode();
        ListNode *j = ans;
        temp = head;
        while (temp != nullptr) {
            if (unique[temp->val] == 1) {
                ListNode *z = new ListNode(temp->val);
                ans->next = z;
                ans = z;
            }
            temp = temp->next;
        }

        return j->next;
    }
};

void printList(ListNode* head) {
    ListNode* current = head;
    while (current != nullptr) {
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(2);
    head->next->next->next->next = new ListNode(4);

    Solution solution;
    ListNode* result = solution.deleteDuplicates(head);

    printList(result);

    // Clean up allocated memory
    while (result != nullptr) {
        ListNode* temp = result;
        result = result->next;
        delete temp;
    }

    return 0;
}
