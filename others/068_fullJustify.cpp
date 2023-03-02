//
// Created by lp on 2023/3/2.
//
#include "vector"
#include "string"

std::string space(int n) {
  return std::string(n, ' ');
}

std::string get_line(const std::vector<std::string> &words, int left, int right, std::string space) {
  std::string res = words[left];
  for (int i = left + 1; i < right; ++i) {
	res += space + words[i];
  }
  return res;
}

std::vector<std::string> fullJustify(std::vector<std::string> &words, int maxWidth) {
  if (words.empty()) return {{}};
  int n = words.size();

  std::vector<std::string> res;
  int left = 0, right = 0, width = 0;
  while (right!=n) {
	left = right;
	width = 0;
	while (right < n && width + words[right].length() + right - left <= maxWidth) {
	  width += words[right].length();
	  ++right;
	}

	int num_words = right - left;
	if (right==n) {
	  res.push_back(get_line(words, left, right, " ") + space(maxWidth - width - num_words + 1));
	  return res;
	} else if (num_words==1) {
	  res.push_back(words[left] + space(maxWidth - width));
	} else {
	  int num_space = maxWidth - width;
	  int average_space = num_space/(num_words - 1);
	  int extra_space = num_space%(num_words - 1);
	  std::string t1 = get_line(words, left, left + extra_space + 1, space(average_space + 1));
	  std::string t2 = get_line(words, left + extra_space + 1, right, space(average_space));
	  res.push_back(t1 + space(average_space) + t2);
	}
  }

  return res;
}