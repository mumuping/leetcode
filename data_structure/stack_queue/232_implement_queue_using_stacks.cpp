//
// Created by lp on 2022/11/15.
//
#include "stack"
#include "cassert"

// 一个当作输出栈，一个当作输入栈，当输出栈为空时，将输入栈的数据 push 进输出栈
// 这样每次都是先进先出
class MyQueue_In_Out {
 public:
  MyQueue_In_Out() : m_in(), m_out() {}

  void push(int x) {
	m_in.push(x);
  }

  int pop() {
	_in2out();
	int tmp = m_out.top();
	m_out.pop();
	return tmp;
  }

  int peek() {
	_in2out();
	return m_out.top();
  }

  bool empty() {
	return m_out.empty() && m_in.empty();
  }

 private:
  void _in2out() {
	if (m_out.empty()) {
	  while (!m_in.empty()) {
		m_out.push(m_in.top());
		m_in.pop();
	  }
	}
  }

 private:
  std::stack<int> m_in, m_out;
};

class MyQueue {
 public:
  MyQueue() : m_base(), m_base_aux() {}

  void push(int x) {
	m_base.push(x);
  }

  int pop() {
	while (!empty()) {
	  m_base_aux.push(m_base.top());
	  m_base.pop();
	}
	int res = m_base_aux.top();
	m_base_aux.pop();
	while (!m_base_aux.empty()) {
	  m_base.push(m_base_aux.top());
	  m_base_aux.pop();
	}

	return res;
  }

  int peek() {
	while (!empty()) {
	  m_base_aux.push(m_base.top());
	  m_base.pop();
	}
	int res = m_base_aux.top();
	while (!m_base_aux.empty()) {
	  m_base.push(m_base_aux.top());
	  m_base_aux.pop();
	}

	return res;
  }

  bool empty() {
	return m_base.empty();
  }

 private:
  std::stack<int> m_base, m_base_aux;
};