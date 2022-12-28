//
// Created by lp on 2022/12/28.
//
#include "vector"
#include "unordered_map"
#include "random"

class RandomizedSet {
 public:
  RandomizedSet() : m_data(), m_map() {}

  bool insert(int val) {
	if (m_map.count(val)==0) {
	  m_data.push_back(val);
	  m_map.insert(std::make_pair(val, m_data.size() - 1));
	  return true;
	} else {
	  return false;
	}
  }

  bool remove(int val) {
	if (m_map.count(val)==0) return false;
	int index = m_map[val];
	m_map.erase(val);
	if (index!=m_data.size() - 1) {
	  m_data[index] = m_data.back();
	  m_map[m_data.back()] = index;
	}
	m_data.pop_back();
	return true;
  }

  int getRandom() {
	int index = rand()%(m_data.size());
	return m_data[index];
  }

 private:
  std::vector<int> m_data;
  std::unordered_map<int, int> m_map;
};
