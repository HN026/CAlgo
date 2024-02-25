#include <iostream>
#include <stack>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *reverseLL(ListNode *head) {
    ListNode *curr = head;
    ListNode *prev = NULL;
    ListNode *ahead = NULL;

    while (curr != NULL) {
        ahead = curr->next;
        curr->next = prev;
        prev = curr;
        curr = ahead;
    }

    return prev;
}

int length(ListNode *head) {
    ListNode *temp = head;
    int cnt = 0;
    while (temp != NULL) {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

class Solution {
  public:
    vector<int> nextLargerNodes(ListNode *head) {
        int n = length(head);
        ListNode *rhead = reverseLL(head);
        stack<int> st;
        vector<int> k(n, 0);
        for (int i = 0; i < n && rhead != NULL; i++) {
            while (!st.empty() && rhead->val >= st.top()) {
                st.pop();
            }
            if (!st.empty()) {
                k[n - i - 1] = st.top();
            }
            st.push(rhead->val);
            rhead = rhead->next;
        }

        return k;
    }
};

int main() {
    Solution solution;

    // Create a linked list: 1 -> 7 -> 5 -> 1 -> 9 -> 2 -> NULL
    ListNode *head = new ListNode(1);
    head->next = new ListNode(7);
    head->next->next = new ListNode(5);
    head->next->next->next = new ListNode(1);
    head->next->next->next->next = new ListNode(9);
    head->next->next->next->next->next = new ListNode(2);

    vector<int> result = solution.nextLargerNodes(head);

    cout << "Next larger nodes: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    // Delete the linked list to avoid memory leak
    while (head != nullptr) {
        ListNode *temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}