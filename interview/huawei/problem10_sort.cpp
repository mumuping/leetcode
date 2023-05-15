//
// Created by lp on 2023/5/15.
//
/**
 * http://codefun2000.com/p/P1006
 */

#include "algorithm"
#include "iostream"
#include "vector"

int main() {
  int n, tot;
  std::cin >> n >> tot;
  std::vector<int> nums(n);
  int sum = 0;
  for (auto &num : nums) {
    std::cin >> num;
    sum += num;
  }
  if (sum <= tot) {
    std::cout << -1 << std::endl;
    return 0;
  }

  sum -= tot;
  std::sort(nums.begin(), nums.end());
  int total_end2begin = -sum;
  for (int i = n - 1, j = 1; i >= 0; --i, ++j) {
    total_end2begin += nums[i];
    if (i >= 1) {
      if (total_end2begin / j < nums[i - 1]) {
        continue;
      } else {
        std::cout << total_end2begin / j << std::endl;
        break;
      }
    } else {
      std::cout << tot / j << std::endl;
      break ;
    }
  }
  return 0;
}