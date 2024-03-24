#include <iostream>
#include <vector>

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
    void reorderList(ListNode *head) {
        if (!head)
            return;
        vector<ListNode *> v;
        ListNode *temp = head;
        while (temp) {
            v.push_back(temp);
            temp = temp->next;
        }

        head->next = NULL;
        head = NULL;
        int n = v.size();
        int s = 0;
        int e = n - 1;
        head = v[0];
        temp = head;
        s++;
        while (s <= e) {
            if (s == e) {
                temp->next = v[s];
                temp = v[s];
                s++;
                e--;
            } else {
                temp->next = v[e];
                temp = v[e];
                e--;
                temp->next = v[s];
                temp = v[s];
                s++;
            }
        }
        temp->next = NULL;
    }
};

// Function to print the linked list
void printList(ListNode *head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create a linked list
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // Print the original list
    cout << "Original List: ";
    printList(head);

    // Reorder the list
    Solution().reorderList(head);

    // Print the reordered list
    cout << "Reordered List: ";
    printList(head);

    return 0;
}