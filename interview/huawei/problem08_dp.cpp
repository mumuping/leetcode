//
// Created by lp on 2023/5/12.
//
/**
 * http://codefun2000.com/p/P1004
 */

#include "iostream"
#include "vector"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> nums(n);
  int sum = 0;
  for (auto &num : nums) {
    std::cin >> num;
    sum += num;
  }
  if (sum % 2 != 0) {
    std::cout << 0 << std::endl;
    return 0;
  }

  sum /= 2;
  std::vector<std::vector<int>> dp(sum + 1, std::vector<int>(n + 1, 0));
  for (int i = 0; i <= n; ++i) {
    dp[0][i] = 1;
  }
  for (int i = 1; i <= sum; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (i < nums[j - 1]) {
        dp[i][j] = dp[i][j - 1];
      } else {
        dp[i][j] = dp[i - nums[j - 1]][j - 1] + dp[i][j - 1];
      }
    }
  }
  std::cout << dp[sum][n] << std::endl;
  return 0;
}