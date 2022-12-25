//
// Created by lp on 2022/11/15.
//
#include "stack"
#include "string"

bool isValid(std::string s) {
  int size = s.size();
  if (size==0 || size%2!=0) return false;

  char tmp;
  std::stack<char> s_stack;
  for (int i = 0; i < size; ++i) {
	if (s[i]=='(' || s[i]=='{' || s[i]=='[') s_stack.push(s[i]);
	else {
	  if (s_stack.empty()) return false;
	  tmp = s_stack.top();
	  s_stack.pop();
	  if (!((s[i]==')' && tmp=='(') ||
		  (s[i]==']' && tmp=='[') ||
		  (s[i]=='}' && tmp=='{')))
		return false;
	}
  }

  return s_stack.empty();
}