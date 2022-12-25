//
// Created by lp on 2022/10/1.
//
#include "string"
#include "unordered_map"
#include "algorithm"
#include "map"

std::string frequencySort(std::string s) {
  int size_s = s.size();
  if (size_s==1)return s;

  // 统计 s 中各字符的频率
  std::unordered_map<char, int> map;
  int i = 0;
  for (; i < size_s; ++i) {
	++map[s[i]];
  }

  // 由于 map 不允许排序，因此将 map 转化为 pair 数组
  int number_of_character = map.size();
//  std::pair<char, int> *c = (std::pair<char, int> *)new std::pair<char, int>[number_of_character];
  std::pair<char, int> *c = (std::pair<char, int> *)malloc(sizeof(std::pair<char, int>)*number_of_character);
  i = 0;
  for (auto iter = map.begin(); iter!=map.end();
	   ++iter, ++i) {
	c[i].first = iter->first;
	c[i].second = iter->second;
  }

  // 对 c 数组进行排序
  std::sort(c, c + number_of_character, [](auto a, auto b) {
	return a.second > b.second;
  });

  // 返回结果
  std::string result;
  for (i = 0; i < number_of_character; ++i) {
	result.append(c[i].second, c[i].first);
  }

  // 释放之前申请的空间
//  delete[] c;
  free(c);
  return result;
}

// 注意在 c++17 中要求必须是 const 类型的函数，
// 因此 operator() 末尾的 const 的必不可少的
struct comp {
  bool operator()(int a, int b) const {
	return a > b;
  }
};

// 使用 map，注意 map 是有序的，可以自己写 comp
std::string frequencySort_(std::string s) {
  int size_s = s.size();
  if (size_s==1)return s;

  // 统计 s 中各字符的频率
  std::unordered_map<char, int> m;
  int i = 0;
  for (; i < size_s; ++i) {
	++m[s[i]];
  }

  // 这里要选择 multimap，因为可能有多个字符的频率是一样的
  // 由于使用 multimap，因此就要使用 insert 函数
  std::multimap<int, char, comp> ordered_map;
  for (auto iter = m.begin(); iter!=m.end(); ++iter) {
	ordered_map.insert(std::pair<int, char>(iter->second, iter->first));
  }

  std::string result;
  for (auto iter = ordered_map.begin(); iter!=ordered_map.end(); ++iter) {
	result.append(iter->first, iter->second);
  }
  return result;
}