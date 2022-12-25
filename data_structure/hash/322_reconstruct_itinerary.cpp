//
// Created by lp on 2022/11/20.
//
#include "vector"
#include "unordered_map"
#include "set"
#include "string"
#include "stack"
#include "algorithm"

std::vector<std::string> findItinerary(std::vector<std::vector<std::string>> &tickets) {
  int n = tickets.size();
  if (n==0) return {};
  if (n==1) return tickets[0];

  std::unordered_map<std::string, std::multiset<std::string>> map_tickets;
  for (const auto &ticket : tickets) {
	map_tickets[ticket[0]].insert(ticket[1]);
  }

  std::vector<std::string> ans;
  std::stack<std::string> s;
  s.push("JFK");

  std::string next;
  while (!s.empty()) {
	next = s.top();
	if (map_tickets[next].empty()) {
	  ans.push_back(next);
	  s.pop();
	} else {
	  s.push(*map_tickets[next].begin());
	  map_tickets[next].erase(map_tickets[next].begin());
	}
  }
  std::reverse(ans.begin(),ans.end());

  return ans;
}