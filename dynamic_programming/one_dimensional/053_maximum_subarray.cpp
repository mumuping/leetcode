//
// Created by lp on 2022/10/27.
//
#include "vector"
#include "climits"

// dp[i] 表示以 nums[i] 结尾的最大子串
// dp[i] = nums[i] 		   IF dp[i-1]<0
// dp[i] = dp[i-1]+nums[i] IF dp[i-1]>=0

int maxSubArray(std::vector<int> &nums) {
  int size = nums.size();
  if (size==0) return 0;
  if (size==1) return nums[0];

  int maximum_sum = INT_MIN;
  int sub_maximum_sum = 0;
  for (int i = 0; i < size; ++i) {
	sub_maximum_sum += nums[i];
	maximum_sum = std::max(maximum_sum, sub_maximum_sum);
	if (sub_maximum_sum < 0) {
	  sub_maximum_sum = 0;
	}
  }

  return maximum_sum;
}