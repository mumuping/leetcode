//
// Created by 18315 on 2023/1/19.
//
#include "vector"
#include "stack"

int trap(std::vector<int> &height) {
  const int n = height.size();
  if (n <= 1) return 0;
  std::vector<int> max_height_of_left(n), max_height_of_right(n);
  max_height_of_left[1] = height[0];
  for (int i = 2; i < n; ++i) {
    max_height_of_left[i] = std::max(max_height_of_left[i - 1], height[i - 1]);
  }
  max_height_of_right[n - 2] = height[n - 1];
  for (int i = n - 3; i >= 0; --i) {
    max_height_of_right[i] = std::max(max_height_of_right[i + 1], height[i + 1]);
  }

  int water = 0, tmp_height;
  for (int i = 1; i < n - 1; ++i) {
    tmp_height = std::min(max_height_of_left[i], max_height_of_right[i]) - height[i];
    if (tmp_height > 0) water += tmp_height;
  }
  return water;
}

// 双指针
int trap_double_pointer(std::vector<int> &height) {
  const int n = height.size();
  if (n <= 1) return 0;
  int max_left = 0, max_right = 0;
  int left = 0, right = n - 1;
  int water = 0;
  while (left < right) {
    max_left = std::max(max_left, height[left]);
    max_right = std::max(max_right, height[right]);
    if (max_left < max_right) {
      water += max_left - height[left];
      ++left;
    } else {
      water += max_right - height[right];
      --right;
    }
  }
  return water;
}

// 单调栈
int trap_stack(std::vector<int> &height) {
  const int n = height.size();
  if (n <= 1) return 0;
  std::stack<int> s;
  int water = 0;
  for (int i = 0; i < n; ++i) {
    while (!s.empty() && height[s.top()] < height[i]) {
      int top_height = height[s.top()];
      s.pop();
      if (s.empty()) break;
      int left_height = height[s.top()];
      water += (std::min(left_height, height[i]) - top_height) * (i - s.top() - 1);
    }
    s.push(i);
  }

  return water;
}