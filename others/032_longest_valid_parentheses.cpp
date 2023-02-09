//
// Created by 18315 on 2023/2/9.
//
#include "string"
#include "stack"
#include "vector"

// dp
int longestValidParentheses(std::string s) {
  if (s.empty()) return 0;
  int n = s.size();
  if (n == 1) return 0;

  std::vector<int> dp(n);
  int longest = 0;
  if (s[0] == '(' && s[1] == ')') {
    dp[1] = longest = 2;
  }
  for (int i = 2; i < n; ++i) {
    if (s[i] == ')') {
      if (s[i - 1] == '(') dp[i] = dp[i - 2] + 2;
      else if (i - 1 - dp[i - 1] >= 0 && s[i - 1 - dp[i - 1]] == '(') {
        if (i - 2 - dp[i - 1] >= 0) dp[i] = dp[i - 2 - dp[i - 1]] + dp[i - 1] + 2;
        else dp[i] = dp[i - 1] + 2;
      }
      longest = std::max(longest, dp[i]);
    }
  }

  return longest;
}

// stack
int longestValidParentheses_stack(std::string s) {
  if (s.empty()) return 0;
  int n = s.size();
  if (n == 1) return 0;

  std::stack<int> st;
  st.push(-1);
  int longest = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') st.push(i);
    else {
      st.pop();
      if (st.empty()) st.push(i);
      else longest = std::max(longest, i - st.top());
    }
  }

  return longest;
}

int longestValidParentheses_thrid(std::string s) {
  if (s.empty()) return 0;
  int n = s.size();
  if (n == 1) return 0;

  int longest = 0, left = 0, right = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') ++left;
    else {
      ++right;
      if (right > left) {
        left = right = 0;
        continue;
      }
    }
    if (left == right) longest = std::max(longest, left * 2);
  }

  left = right = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == ')') ++right;
    else {
      ++left;
      if (left > right) {
        left = right = 0;
        continue;
      }
    }
    if (left == right) longest = std::max(longest, left * 2);
  }
  return longest;
}