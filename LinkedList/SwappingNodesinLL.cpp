#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

int LenOfLL(ListNode *head) {
  ListNode *temp = head;
  int cnt = 0;
  while (temp) {
    cnt++;
    temp = temp->next;
  }
  return cnt;
}

ListNode *swapNodes(ListNode *head, int k) {
  if (head == NULL)
    return head;

  ListNode *ptrs = NULL;
  ListNode *ptrl = NULL;
  int n = LenOfLL(head);
  int end = n - k + 1;
  int cnt = 1;
  ListNode *temp = head;
  while (temp) {
    if (cnt == k) {
      ptrs = temp;
    }
    if (cnt == end) {
      ptrl = temp;
    }
    cnt++;
    temp = temp->next;
  }

  if (ptrs && ptrl) {
    int t = ptrs->val;
    ptrs->val = ptrl->val;
    ptrl->val = t;
  }

  return head;
}

int main() {

  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  int k = 2;

  head = swapNodes(head, k);
  ListNode *temp = head;
  while (temp != NULL) {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

  return 0;
}