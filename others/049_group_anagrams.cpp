//
// Created by lp on 2023/2/17.
//
#include "vector"
#include "string"
#include "unordered_map"
#include "algorithm"
#include "functional"
#include "numeric"

std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
  if (strs.empty()) return {{}};
  int n = strs.size();
  if (n==1) return {{strs[0]}};

  std::unordered_map<std::string, std::vector<std::string>> m;
  std::string tmp;
  for (const auto &str : strs) {
	tmp = str;
	std::sort(tmp.begin(), tmp.end());
	m[tmp].emplace_back(str);
  }

  std::vector<std::vector<std::string>> ans;
  for (const auto &it : m) {
	ans.emplace_back(it.second);
  }
  return ans;
}

std::vector<std::vector<std::string>> groupAnagrams_hash(std::vector<std::string> &strs) {
  if (strs.empty()) return {{}};
  int n = strs.size();
  if (n==1) return {{strs[0]}};

  auto hash = [fn = std::hash<int>()](const std::array<int, 26> letters) {
	return std::accumulate(letters.begin(), letters.end(), 0u, [&](unsigned int sum, int num) {
	  return (sum << 1) ^ fn(num);
	});
  };
  std::unordered_map<std::array<int, 26>, std::vector<std::string>, decltype(hash)> m(0, hash);
  for (const auto &str : strs) {
	std::array<int, 26> counts{};
	for (const char &ch : str) {
	  ++counts[ch - 'a'];
	}
	m[counts].emplace_back(str);
  }

  std::vector<std::vector<std::string>> ans;
  for (const auto &iter : m) {
	ans.emplace_back(iter.second);
  }

  return ans;
}