//
// Created by 18315 on 2023/3/15.
//
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *deleteDuplicates(ListNode *head) {
  if (head == nullptr || head->next == nullptr) return head;

  ListNode *dummy = new ListNode;
  dummy->next = head;

  ListNode *pre = dummy, *cur = head->next, *tmp = nullptr;
  while (cur) {
    if (pre->next->val != cur->val) {
      pre = pre->next;
    } else {
      while (cur && pre->next->val == cur->val) {
        tmp = cur->next;
        delete cur;
        cur = tmp;
      }
      pre->next = cur;
    }
    if (cur) cur = cur->next;
    else break;
  }

  pre = dummy->next;
  delete dummy;
  return pre;
}
