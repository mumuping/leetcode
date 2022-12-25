//
// Created by lp on 2022/10/21.
//
#include "string"
#include "vector"

// 在本题中，我们可以建立一个二维数组 dp，其中 dp[i][j] 表示到第一个字符串位置 i 为止、到
// 第二个字符串位置 j 为止、最长的公共子序列长度。这样一来我们就可以很方便地分情况讨论这
// 两个位置对应的字母相同与不同的情况了。
// 若 text1[i]==text2[j] 则 dp[i][j]=dp[i-1][j-1]+1
// 若 text1[i]!=text2[j] 则 dp[i][j]=max(dp[i-1][j],dp[i][j-1])
int longestCommonSubsequence(std::string text1, std::string text2){
  int size_text1=text1.size(), size_text2=text2.size();
  std::vector<std::vector<int>> dp(size_text1+1,std::vector<int>(size_text2+1,0));

  for(int i=0;i<size_text1;++i){
	for(int j=0;j<size_text2;++j){
	  if(text1[i]==text2[j]){
		dp[i+1][j+1]=dp[i][j]+1;
	  }else{
		dp[i+1][j+1]=std::max(dp[i][j+1],dp[i+1][j]);
	  }
	}
  }
  return dp[size_text1][size_text2];
}