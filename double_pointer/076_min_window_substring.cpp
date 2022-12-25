//
// Created by lp on 2022/9/18.
//

#include "string"
#include "unordered_map"
#define MAX_NUM 0x3f3f3f3f

std::string minWindow(std::string s, std::string t) {
  int s_size = s.size(), t_size = t.size();
  std::unordered_map<char, int> t_count;
  std::unordered_map<char, int> s_substring_count;
  for (int i = 0; i < t.size(); ++i)
	t_count[t[i]]++;

  int left = 0, right = 0;
  int distance = 0;
  int number_of_substring = MAX_NUM;
  int substring_left_index = 0, substring_right_index = 0;

  /* 优化 s 最左边部分，即 s 最左边的字符不属于 t 的直接跳过 */
  while (t_count[s[left]]==0 && left < s_size) {
	++left;
	++right;
  }

  while (right < s_size) {
	if (s_substring_count[s[right]] < t_count[s[right]])
	  ++distance;
	++s_substring_count[s[right]];

	while (distance==t_size) {
	  if (number_of_substring > right - left + 1) {
		substring_left_index = left;
		substring_right_index = right;
		number_of_substring = right - left + 1;
	  }
	  ++left;
	  --s_substring_count[s[left - 1]];
	  if (s_substring_count[s[left - 1]] < t_count[s[left - 1]])
		--distance;
	}
	++right;
  }

  if (number_of_substring==MAX_NUM)return "";
  return s.substr(substring_left_index, substring_right_index - substring_left_index + 1);
}
