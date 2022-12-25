//
// Created by lp on 2022/11/16.
//
#include "vector"
#include "queue"

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 第一种方法，依次合并
ListNode *merge2(ListNode *first, ListNode *second) {
  if (!first) return second;
  if (!second) return first;

  ListNode head;            // 定义一个空节点
  ListNode *curr = &head;
  while (first && second) {
	if (first->val < second->val) {
	  curr->next = first;
	  first = first->next;
	} else {
	  curr->next = second;
	  second = second->next;
	}
	curr = curr->next;
  }
  curr->next = (first ? first : second);

  return head.next;
}

ListNode *mergeKLists(std::vector<ListNode *> &lists) {
  int size = lists.size();
  if (size==0) return nullptr;
  if (size==1) return lists[0];

  ListNode *head = nullptr;
  for (int i = 0; i < size; ++i) {
	head = merge2(lists[i], head);
  }

  return head;
}

// 分治合并
ListNode *merge(std::vector<ListNode *> &lists, int l, int r) {
  if (l==r) return lists[l];
  if (l > r) return nullptr;

  int mid = (l + r) >> 1;
  return merge2(merge(lists, l, mid), merge(lists, mid + 1, r));
}

ListNode *mergeKLists_divide(std::vector<ListNode *> &lists) {
  int size = lists.size();
  if (size==0) return nullptr;
  if (size==1) return lists[0];

  return merge(lists, 0, size - 1);
}

// 使用优先队列
struct comp {
  bool operator()(const ListNode *a, const ListNode *b) const {
	return b->val < a->val;
  }
};
ListNode *mergeKLists_priority(std::vector<ListNode *> &lists) {
  int size = lists.size();
  if (size==0) return nullptr;
  if (size==1) return lists[0];

  std::priority_queue<ListNode *, std::vector<ListNode *>, comp> q;
  for (auto list : lists) {
	if (list) q.push(list);
  }

  ListNode dummy;
  ListNode *curr = &dummy;
  while (!q.empty()){
	curr->next=q.top();
	q.pop();
	curr=curr->next;
	if(curr->next){
	  q.push(curr->next);
	}
  }

  return dummy.next;
}