//
// Created by lp on 2022/11/15.
//
#include "stack"

// 我们可以额外建立一个新栈，栈顶表示原栈里所有值的最小值。每当在原栈里插入一个数字
// 时，若该数字小于等于新栈栈顶，则表示这个数字在原栈里是最小值，我们将其同时插入新栈内。
// 每当从原栈里取出一个数字时，若该数字等于新栈栈顶，则表示这个数是原栈里的最小值之一，
// 我们同时取出新栈栈顶的值。
class MinStack {
 public:
  MinStack() : m_min_stack(), m_stack() {}

  void push(int val) {
	if (m_min_stack.empty() || m_min_stack.top() >= val) m_min_stack.push(val);
	m_stack.push(val);
  }

  void pop() {
	int tmp = top();
	if (tmp==getMin()) {
	  m_min_stack.pop();
	}
	m_stack.pop();
  }

  int top() {
	return m_stack.top();
  }

  int getMin() {
	return m_min_stack.top();
  }

 private:
  std::stack<int> m_min_stack;
  std::stack<int> m_stack;
};