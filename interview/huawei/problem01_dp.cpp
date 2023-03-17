//
// Created by 18315 on 2023/3/15.
//

// src: https://www.bilibili.com/video/BV1Ri4y1D7DA/?spm_id_from=333.788&vd_source=cae965f23b6cb71143bed6af4be19e37

#include <vector>
#include <iostream>

int min_step(const std::vector<int> &magic_values, int max_steps) {
  if (magic_values.empty()) return 0;
  int n = magic_values.size();
  if (n == 1) return 0;

  int curr_target_pos = magic_values[0], next_target_pos = magic_values[0], total_steps = 0;
  int i = 0;
  for (; i < n; ++i) {
    if (i != curr_target_pos) {
      next_target_pos = std::max(next_target_pos, i + magic_values[i]);
    } else {
      ++total_steps;
      if (next_target_pos >= n - 1) {
        ++total_steps;
        break;
      } else if (curr_target_pos == next_target_pos) {
        return -1;
      } else {
        curr_target_pos = next_target_pos;
      }
    }
  }

  if (next_target_pos >= n - 1 && total_steps <= max_steps) return total_steps;
  else return -1;
}

int solution() {
  int n, k;
  std::cin >> n;
  std::vector<int> magic_value(n);
  for (auto &it : magic_value) {
    std::cin >> it;
  }
  std::cin >> k;

  return min_step(magic_value, k);
}