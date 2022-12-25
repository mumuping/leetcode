//
// Created by lp on 2022/10/20.
//
#include "string"

// 递归方式
// 该方法在测试用例中会导致超时
void recursion(const std::string &s, int level, int &nums) {
  // 当 level 到达末尾时，说明找到了一个解码方案
  if (level==s.size()) {
	++nums;
	return;
  }

  // 当前字符为 0 时，说明解码错误
  if (s[level]=='0') return;
  // 只有一个字符时 1~9
  recursion(s, level + 1, nums);

  // 两个字符时，10~26
  if (level + 1 < s.size()) {
	std::string sub(s, level, 2);
	int a = stoi(sub);
	if (a <= 26 && a >= 10)
	  recursion(s, level + 2, nums);
  }
}

// 上述方法在测试用例中会导致超时，因此现改为 dp
// 当元素 i 不为 0 时，若与前面的元素组合不为 10~26，则 f(i)=f(i-1)
//					   若与前面的元素组合为 10~26，则 f(i)=f(i-1)+f(i-2)
// 当元素 i 为 0 时，若与前面的元素组合不为 10~26，则无解，直接返回
//					 若与前面的元素组合为 10~26，则 f(i)=f(i-2)
int dp(const std::string &s) {
  int size = s.size();
  if (size==0 || (size==1 && s[0]=='0')) return 0;

  int *dp = new int[size + 1]();
  dp[0] = dp[1] = 1;

  int tmp = 0, str_to_int;
  for (int i = 1; i < size; ++i) {
	tmp = 0;
	if (s[i]!='0') {        // 单个字符 1~9
	  tmp = dp[i];
	}
	// 两个字符 10~26
	if (s[i - 1]=='1' || s[i - 1]=='2') {    // 前一个字符只能是 1 或 2
	  std::string sub(s, i - 1, 2);
	  str_to_int = stoi(sub);
	  if (str_to_int >= 10 && str_to_int <= 26) {
		tmp += dp[i - 1];
	  }
	}
	dp[i + 1] = tmp;
	if (tmp==0) return 0;    // 说明无解
  }

  tmp = dp[size];
  delete[] dp;
  return tmp;
}

// 从上面的状态转移方程可以发现 f(i) 只与 f(i-1) 和 f(i-2) 有关，因此可以压缩空间
int dp_compression(const std::string &s) {
  int size = s.size();
  if (size==0 || (size==1 && s[0]=='0')) return 0;

  int dp[2]{1, 1};
  int tmp, str_to_int;
  for (int i = 1; i < size; ++i) {
	tmp = 0;
	if (s[i]!='0') {    // 单个字符 s[i] 属于 [1,9]
	  tmp = dp[1];
	}
	if (s[i - 1]=='1' || s[i - 1]=='2') {    // 两个字符 s[i-1] 只能是 1 或者 2
	  std::string sub(s, i - 1, 2);
	  str_to_int = std::stoi(sub);
	  if (str_to_int >= 10 && str_to_int <= 26) {
		tmp += dp[0];
	  }
	}
	if (tmp==0) return 0;    // 无解
	dp[0] = dp[1];
	dp[1] = tmp;
  }

  return dp[1];
}

int numDecoding(std::string s) {
  if (s.size() < 1 || s[0]=='0') return 0;

  return dp_compression(s);
}