//
// Created by lp on 2022/10/21.
//
#include "vector"
#include "algorithm"

// dp
// dp[i] 表示以 nums[i] 为结尾的最长递增子串
int lengthOfLIS(std::vector<int> &nums) {
  int size_nums = nums.size();
  if (size_nums <= 1) return size_nums;

  int *dp = new int[size_nums];
  dp[0] = 1;

  int tmp = 0, ans = 1;
  for (int i = 1; i < size_nums; ++i) {
	tmp = 0;
	for (int j = i - 1; j >= 0; --j) {
	  if (nums[i] > nums[j]) {
		tmp = std::max(tmp, dp[j]);
	  }
	}
	dp[i] = tmp + 1;
	ans = std::max(ans, dp[i]);
  }

  delete[] dp;
  return ans;
}

// 上述方法还可以将时间复杂度减到 O(n log(n))
// dp[i] 表示存放长度为 i 的最长递增子串的最后一个数字
// 遍历 nums，若 nums[k] 大于所有 dp 中的数字，则 dp 长度加一，值为 nums[k]
// 若 nums[k] 在 dp 数组中比数字 a 大、比数字 b 小，则我们将 b 更新为此数字，使得之后构成递增序列的可能性增大
// 这样就可以使用二分查找
int lengthOfLIS_nlogn(std::vector<int> &nums) {
  int size_nums = nums.size();
  if (size_nums <= 1) return size_nums;

  std::vector<int> dp;
  dp.reserve(size_nums);
  dp.push_back(nums[0]);

  std::vector<int>::iterator iter;
  for (int i = 1; i < size_nums; ++i) {
	if (nums[i] > dp.back()) {
	  dp.push_back(nums[i]);
	} else {
	  iter = std::lower_bound(dp.begin(), dp.end(), nums[i]);
	  *iter = nums[i];
	  /** 二分 左闭右开
	  auto begin=dp.begin(), end=dp.end();
	  while(begin!=end){
		if(*((end-begin)/2+begin)>=nums[i]){
		  end=(end-begin)/2+begin;
		}
		else{
		  begin=(end-begin)/2+begin+1;
		}
	  }
	  *end=nums[i];
	  */
	}
  }
  return dp.size();
}