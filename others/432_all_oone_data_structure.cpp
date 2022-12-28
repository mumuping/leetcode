//
// Created by lp on 2022/12/28.
//
#include "string"
#include "list"
#include "unordered_set"
#include "unordered_map"

class AllOne {
  using string = std::string;
  using unordered_set = std::unordered_set<string>;
  using list = std::list<std::pair<unordered_set, int>>;
  using unordered_map = std::unordered_map<string, list::iterator>;
 public:
  AllOne() : m_data(), m_map() {}

  void inc(string key) {
	auto it = m_map.find(key);
	if (it==m_map.end()) {
	  if (m_data.empty() || m_data.front().second > 1) {
		m_data.push_front(std::make_pair(unordered_set{key}, 1));
	  } else {
		m_data.front().first.insert(key);
	  }
	  m_map.insert(std::make_pair(key, m_data.begin()));
	} else {
	  auto m_data_iter = it->second;
	  auto next_iter = m_data_iter;
	  if ((++next_iter)==m_data.end() || next_iter->second > m_data_iter->second + 1) {
		auto r = m_data.insert(next_iter, std::make_pair(unordered_set{key}, m_data_iter->second + 1));
		m_map.erase(key);
		m_map.insert(std::make_pair(key, r));
	  } else {
		next_iter->first.insert(key);
		m_map.erase(key);
		m_map.insert(std::make_pair(key, next_iter));
	  }
	  m_data_iter->first.erase(key);
	  if (m_data_iter->first.empty())
		m_data.erase(m_data_iter);
	}
  }

  void dec(string key) {
	auto it = m_map.find(key);
	if (it==m_map.end()) return;
	auto m_data_iter = it->second;
	auto pre_iter = m_data_iter;
	--pre_iter;
	if (m_data_iter==m_data.begin() || pre_iter->second < m_data_iter->second - 1) {
	  m_map.erase(key);
	  if (m_data_iter->second - 1!=0) {
		auto r = m_data.insert(m_data_iter, std::make_pair(unordered_set{key}, m_data_iter->second - 1));
		m_map.insert(std::make_pair(key, r));
	  }
	} else {
	  pre_iter->first.insert(key);
	  m_map.erase(key);
	  m_map.insert(std::make_pair(key, pre_iter));
	}
	m_data_iter->first.erase(key);
	if (m_data_iter->first.empty())
	  m_data.erase(m_data_iter);
  }

  string getMaxKey() {
	if (m_data.empty()) return {};
	return *(m_data.back().first.begin());
  }

  string getMinKey() {
	if (m_data.empty()) return {};
	return *(m_data.front().first.begin());
  }

 private:
  list m_data;
  unordered_map m_map;
};