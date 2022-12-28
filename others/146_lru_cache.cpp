//
// Created by lp on 2022/12/27.
//
#include "unordered_map"
#include "list"

class LRUCache {
 public:
  LRUCache(int capacity) : m_data(), m_cache(), m_capacity(capacity) {}

  int get(int key) {
	auto it = m_cache.find(key);
	if (it==m_cache.end()) {
	  return -1;
	}
	m_data.splice(m_data.begin(), m_data, it->second);
	return it->second->second;
  }

  void put(int key, int value) {
	auto it = m_cache.find(key);
	if (it==m_cache.end()) {
	  if (m_data.size() >= m_capacity) {
		int old_key = m_data.back().first;
		m_data.pop_back();
		m_cache.erase(old_key);
	  }
	  m_data.push_front(std::make_pair(key, value));
	  m_cache.insert(std::make_pair(key, m_data.begin()));
	} else {
	  it->second->second = value;
	  m_data.splice(m_data.begin(), m_data, it->second);
	}
  }

 private:
  std::list<std::pair<int, int>> m_data;
  std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m_cache;
  int m_capacity;
};