//
// Created by lp on 2023/5/15.
//
/**
 * http://codefun2000.com/p/P1005
 */

#include "algorithm"
#include "iostream"
#include "vector"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> pos(n);
  std::vector<std::pair<int, int>> v(n);
  for (int i = 0; i < n; ++i) {
    std::cin >> pos[i] >> v[i].first;
    v[i].second = i;
  }
  std::sort(pos.begin(), pos.end());
  std::sort(v.begin(), v.end(),
            [&](std::pair<int, int> &lhs, std::pair<int, int> &rhs) {
              return lhs.first < rhs.first;
            });
  for (int i = 0; i < n; ++i) {
    while (v[i].second != i) {
      int next=v[i].second;
      std::swap(v[i], v[next]);
      std::swap(pos[i], pos[next]);
    }
  }

  for (int i = 0; i < n; ++i) {
    std::cout << pos[i] << " " << v[i].first << std::endl;
  }
  return 0;
}