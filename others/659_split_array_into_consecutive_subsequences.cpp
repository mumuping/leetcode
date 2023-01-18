//
// Created by 18315 on 2023/1/18.
//
#include "vector"
#include "unordered_map"
#include "queue"

bool isPossible(std::vector<int> &nums) {
  const int n = nums.size();
  std::unordered_map<int, std::priority_queue<int, std::vector<int>, std::greater<int>>> m;

  for (int i = 0; i < n; ++i) {
    if (m[nums[i] - 1].empty()) {
      m[nums[i]].push(1);
    } else {
      int length = m[nums[i] - 1].top() + 1;
      m[nums[i] - 1].pop();
      m[nums[i]].push(length);
    }
  }

  for (const auto &it : m) {
    if (!it.second.empty() && it.second.top() < 3) return false;
  }

  return true;
}

// 优化
bool isPossible_greedy(std::vector<int> &nums) {
  std::unordered_map<int, int> counts, num_of_seq_with_end;
  for (int it : nums) {
    ++counts[it];
  }

  for (int it : nums) {
    if (counts[it] == 0) continue;
    if (num_of_seq_with_end[it - 1] == 0) {
      if (counts[it + 1] == 0 || counts[it + 2] == 0) return false;
      --counts[it + 1], --counts[it + 2];
      ++num_of_seq_with_end[it + 2];
    } else {
      --num_of_seq_with_end[it - 1];
      ++num_of_seq_with_end[it];
    }
    --counts[it];
  }

  return true;
}