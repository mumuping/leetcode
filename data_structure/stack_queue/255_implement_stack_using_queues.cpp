//
// Created by lp on 2022/11/24.
//
#include "queue"

class MyStack {
 public:
  MyStack() : m_queue() {}

  void push(int x) {
	int n = m_queue.size();
	m_queue.push(x);
	while (n > 0) {
	  m_queue.push(m_queue.front());
	  m_queue.pop();
	  --n;
	}
  }

  int pop() {
	int res = m_queue.front();
	m_queue.pop();
	return res;
  }

  int top() {
	return m_queue.front();
  }

  bool empty() {
	return m_queue.empty();
  }

 private:
  std::queue<int> m_queue;
};