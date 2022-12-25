//
// Created by lp on 2022/9/21.
//
#include "string"

bool checkPalindromeWithoutDeleted(const std::string &s, int low, int high) {
  while (low < high) {
	if (s[low]!=s[high])return false;
	++low;
	--high;
  }
  return true;
}

bool validPalindrome(std::string s) {
  int low = 0, high = s.size() - 1;
  bool is_already_deleted = false;

  while (low < high) {
	if (s[low]!=s[high] && !is_already_deleted) {
	  return checkPalindromeWithoutDeleted(s, low + 1, high) || checkPalindromeWithoutDeleted(s, low, high - 1);
	}
	if (s[low]==s[high]) {
	  ++low;
	  --high;
	  continue;
	}
	return false;
  }

  return true;
}