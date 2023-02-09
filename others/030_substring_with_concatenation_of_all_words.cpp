//
// Created by lp on 2023/2/9.
//
#include "string"
#include "unordered_map"
#include "vector"

std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
  if (s.empty() || words.empty()) return {};
  int s_length = s.size(), num_words = words.size(), word_length = words[0].size();
  if (s_length < num_words*word_length) return {};

  std::unordered_map<std::string, int> word_count;
  for (const auto &word : words) {
	word_count[word]++;
  }

  std::unordered_map<std::string, int> word_count_copy;
  std::vector<int> res;
  std::string sub;
  int num_match = 0;
  for (int i = 0; i < word_length; ++i) {
	if (i > s_length - num_words*word_length) break;
	num_match = 0;
	word_count_copy = word_count;
	for (int j = i; j < num_words*word_length; j += word_length) {
	  sub = s.substr(j, word_length);
	  if (word_count_copy.count(sub)==1) {
		if (word_count_copy[sub] > 0) ++num_match;
		--word_count_copy[sub];
	  }
	}
	if (num_match==num_words) res.push_back(i);

	for (int start = i, next = i + num_words*word_length;
		 next < s_length;
		 start += word_length, next += word_length) {
	  sub = s.substr(start, word_length);
	  if (word_count_copy.count(sub)==1) {
		if (word_count_copy[sub] >= 0 && word_count_copy[sub] < word_count[sub])
		  --num_match;
		++word_count_copy[sub];
	  }
	  sub = s.substr(next, word_length);
	  if (word_count_copy.count(sub)==1) {
		if (word_count_copy[sub] > 0 && word_count_copy[sub] <= word_count[sub])
		  ++num_match;
		--word_count_copy[sub];
	  }
	  if (num_match==num_words) res.push_back(start + word_length);
	}
  }
  return res;
}