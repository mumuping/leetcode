//
// Created by lp on 2022/12/12.
//
#include "vector"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isPalindrome(ListNode *head) {
  if (!head) return false;
  if (!head->next) return true;

  std::vector<int> nums;
  while (head) {
	nums.push_back(head->val);
	head = head->next;
  }

  int i = 0, j = nums.size() - 1;
  while (i < j) {
	if (nums[i]!=nums[j]) return false;
	++i;
	--j;
  }
  return true;
}

// 先使用快慢指针找到链表中点，再把链表切成两半；
// 然后把后半段翻转；最后比较两半是否相等。
ListNode *reverse_list(ListNode *head) {
  if (!head || !head->next) return head;
  ListNode *pre = nullptr, *next;
  while (head) {
	next = head->next;
	head->next = pre;
	pre = head;
	head = next;
  }
  return pre;
}

bool isPalindrome_p(ListNode *head) {
  if (!head || !head->next) return true;

  ListNode *slow = head, *fast = head;
  while (fast->next && fast->next->next) {
	slow = slow->next;
	fast = fast->next->next;
  }

  slow->next = reverse_list(slow->next);
  slow = slow->next;
  while (slow) {
	if (slow->val!=head->val) return false;
	head = head->next;
	slow = slow->next;
  }
  return true;
}