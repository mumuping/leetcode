//
// Created by lp on 2022/11/11.
//
#include "vector"
#include "string"
#include "unordered_map"

int maxProduct(std::vector<std::string> &words) {
  std::unordered_map<int, int> map;
  map.reserve(words.size());

  int max_product = 0;
  int mask = 0, size = 0;
  for (const auto &word : words) {
	mask = 0;
	size = word.size();
	for (const auto &ch : word) {
	  mask |= (1 << (ch - 'a'));
	}

	for (const auto &element : map) {
	  if (!(mask & element.first)) {
		max_product = std::max(max_product, size*element.second);
	  }
	}

	map[mask] = std::max(map[mask], size);	// 这里是为了解决可能出现这种情况，"abcd" 和 "aaaabcd"
  }

  return max_product;
}