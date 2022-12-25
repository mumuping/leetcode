//
// Created by lp on 2022/10/17.
//

#include "vector"
// dp
// f(n)=f(n-1)+f(n-2)
int climbStairs(int n) {
  if(n==1) return 1;
  if(n==2) return 2;

  std::vector<int> steps(n,1);
  steps[1]=2;
  int i=2;
  while(i<n){
	steps[i]=steps[i-1]+steps[i-2];
	++i;
  }

  return steps.back();
}

// 因为 f(n) 只与前两个有关，因此可以压缩空间
int climbStairs_(int n){
  if(n==1) return 1;
  if(n==2) return 2;

  int dp[2]{1,2};
  int res;
  for(int i=2;i<n;++i){
	res=dp[0]+dp[1];
	dp[0]=dp[1];
	dp[1]=res;
  }

  return res;
}