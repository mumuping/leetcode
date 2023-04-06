//
// Created by lp on 2023/3/25.
//

#include <iostream>
#include <vector>

void solution() {
  int N, A, B;
  std::cin >> N >> A >> B;
  std::vector<std::pair<int, int>> enemies(N);
  for (int i = 0; i < N; ++i) {
	std::cin >> enemies[i].first >> enemies[i].second;
  }

  int count, res = 0;
  for (int i = 0; i < N; ++i) {
	count = 1;
	for (int j = i + 1; j < N; ++j) {
	  if (std::abs(enemies[i].first - enemies[j].first) <= A &&
		  std::abs(enemies[i].second - enemies[j].second) <= B) {
		++count;
	  }
	}
	res = std::max(res, count);
  }

  std::cout << res << std::endl;
}