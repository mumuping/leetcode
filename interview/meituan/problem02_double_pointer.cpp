//
// Created by lp on 2023/3/25.
//
#include <unordered_map>
#include <vector>
#include <iostream>

void solution() {
  int N, K;
  std::cin >> N >> K;
  std::vector<int> tapes(N);
  for (auto &it : tapes) {
	std::cin >> it;
  }

  int left = 0, right = 0;
  int max_length = 0;
  std::unordered_map<int, int> colors_counts;
  while (right < N) {
	if (!colors_counts.count(tapes[right])) {
	  --K;
	  if (K < 0) break;
	}
	++colors_counts[tapes[right]];
	++right;
  }

  max_length = right - left;
  while (right < N) {
	if (!colors_counts[tapes[right]]) {
	  while (--colors_counts[tapes[left++]]);
	}
	++colors_counts[tapes[right]];
	++right;
	max_length = std::max(max_length, right - left);
  }

  std::cout << max_length << std::endl;
}