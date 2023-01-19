//
// Created by 18315 on 2023/1/19.
//
#include "vector"

int maxArea(std::vector<int> &height) {
  int n = height.size();
  if (n < 2) return 0;
  int left = 0, right = n - 1;
  int left_height = height[left], right_height = height[right];
  int max_water = (n - 1) * std::min(left_height, right_height);
  while (left < right) {
    if (left_height < right_height) {
      while (left < right && height[left] <= left_height) ++left;
      left_height = height[left];
    } else {
      while (left < right && height[right] <= right_height) --right;
      right_height = height[right];
    }
    max_water = std::max(max_water, (right - left) * std::min(left_height, right_height));
  }

  return max_water;
}