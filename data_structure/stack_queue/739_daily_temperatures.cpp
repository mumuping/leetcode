//
// Created by lp on 2022/11/15.
//
#include "vector"
#include "stack"

// 单调栈
std::vector<int> dailyTemperatures(std::vector<int> &temperatures) {
  int size = temperatures.size();
  if (size==0) return {};
  if (size==1) return {0};

  std::stack<std::pair<int, int>> s;    // <温度，位置差>，另一种更简单的方法是定义 <温度，位置索引>
  std::vector<int> answer(size);
  int tmp = 1;
  for (int i = size - 1; i >= 0; --i) {
	while (!s.empty() && s.top().first <= temperatures[i]) {
	  tmp += s.top().second;
	  s.pop();
	}
	if (s.empty()) answer[i] = 0;
	else answer[i] = tmp;
	s.push({temperatures[i], answer[i]});
	tmp = 1;
  }

  return answer;
}

std::vector<int> dailyTemperatures_index(std::vector<int> &temperatures) {
  int size = temperatures.size();
  if (size==0) return {};
  if (size==1) return {0};

  std::stack<std::pair<int, int>> s;    // <温度，位置索引>
  std::vector<int> answer(size);
  for (int i = size - 1; i >= 0; --i) {
	while (!s.empty() && s.top().first <= temperatures[i]) {
	  s.pop();
	}
	if (s.empty()) answer[i] = 0;
	else answer[i] = s.top().second - i;
	s.push({temperatures[i], i});
  }

  return answer;
}

// 更优的方法是直接存储索引
std::vector<int> dailyTemperatures_index_(std::vector<int> &temperatures) {
  int size = temperatures.size();
  if (size==0) return {};
  if (size==1) return {0};

  std::stack<int> s;    // <位置索引>
  std::vector<int> answer(size);
  for (int i = size - 1; i >= 0; --i) {
	while (!s.empty() && temperatures[s.top()] <= temperatures[i]) {
	  s.pop();
	}
	if (s.empty()) answer[i] = 0;
	else answer[i] = s.top() - i;
	s.push(i);
  }

  return answer;
}