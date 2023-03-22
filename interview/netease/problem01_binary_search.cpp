//
// Created by 18315 on 2023/3/22.
//
// https://www.bilibili.com/video/BV193411g72T/?spm_id_from=333.788&vd_source=cae965f23b6cb71143bed6af4be19e37

#include <vector>
#include <iostream>

bool check(const std::vector<int> &nums, int n, int m, int distance) {
  int count = 1, pre = nums[0];
  for (int i = 1; i < n; ++i) {
    if (nums[i] - pre >= distance) {
      ++count;
    }
    if (count == m) return true;
  }
  return false;
}

void solution() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> nums(n);
  for (auto &it : nums) {
    std::cin >> it;
  }

  int left = 0, right = nums.back() - nums.front();
  while (left < right) {
    int mid = (left + right + 1) / 2;
    if (check(nums, n, m, mid)) left = mid;
    else right = mid - 1;
  }

  std::cout << right;
}