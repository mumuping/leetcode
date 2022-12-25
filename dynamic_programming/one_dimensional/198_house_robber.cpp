//
// Created by lp on 2022/10/17.
//
#include "vector"

// dp
// f(n)=max(nums[n]+f(n-2), f(n-1))
int rob(std::vector<int>& nums){
  int size_nums=nums.size();
  if(size_nums==1) return nums[0];
  if(size_nums==2) return std::max(nums[0],nums[1]);

  std::vector<int> money(size_nums,0);
  money[0]=nums[0];
  money[1]=std::max(nums[0],nums[1]);

  for(int i=2;i<size_nums;++i){
	money[i]=std::max(money[i-1],money[i-2]+nums[i]);
  }

  return money.back();
}

// 从状态转移方程可以看出 f(n) 只与 f(n-1) 和 f(n-2）以及 nums[n] 有关
// 因此可以压缩空间
int rob_(std::vector<int>& nums){
  int size_nums=nums.size();
  if(size_nums==1) return nums[0];
  if(size_nums==2) return std::max(nums[0],nums[1]);

  int dp[2]{nums[0],std::max(nums[0],nums[1])};
  int res;
  for(int i=2;i<size_nums;++i){
	res= std::max(dp[1],dp[0]+nums[i]);
	dp[0]=dp[1];
	dp[1]=res;
  }

  return res;
}