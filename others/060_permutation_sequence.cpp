//
// Created by lp on 2023/2/22.
//
#include "string"
#include "vector"
#include "numeric"

std::string getPermutation(int n, int k) {
  if (n==1) return "1";

  std::string res;
  res.reserve(n);
  static constexpr int factorial[9] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320};
  std::vector<int> nums(n, 0);
  std::iota(nums.begin(), nums.end(), 1);

  --k;
  for (int i = n - 1; i >= 0; --i) {
	auto it = nums.begin() + k/factorial[i];
	res += '0' + *it;
	nums.erase(it);
	k %= factorial[i];
  }
  return res;
}