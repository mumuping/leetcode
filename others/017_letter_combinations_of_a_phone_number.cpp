//
// Created by lp on 2023/2/6.
//
#include "string"
#include "vector"

const std::string digit_string[8] = {"abc", "def",
									 "ghi", "jkl", "mno",
									 "pqrs", "tuv", "wxyz"};

void letterCombinations_aux(const std::string &digits, int index,
							std::string combination,
							std::vector<std::string> &combinations) {
  if (digits.size()==index) {
	combinations.push_back(combination);
	return;
  }

  int number = digits[index] - '2';
  int n = digit_string[number].size();
  for (int i = 0; i < n; ++i) {
	combination += digit_string[number][i];
	letterCombinations_aux(digits, index + 1, combination, combinations);
	combination.pop_back();
  }
}

std::vector<std::string> letterCombinations(std::string digits) {
  if (digits.empty()) return {};
  std::vector<std::string> combinations;
  std::string combination;
  letterCombinations_aux(digits, 0, combination, combinations);
  return combinations;
}