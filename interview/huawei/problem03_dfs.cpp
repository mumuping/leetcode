//
// Created by lp on 2023/3/17.
//

#include <iostream>
#include <unordered_map>
#include <string>

int dfs(const int problems[], int index, int cnt, int rest_grade,
		std::unordered_map<std::string, int> &memory) {
  if (cnt==0) return rest_grade==0 ? 1 : 0;
  if (rest_grade==0) return 1;
  if (index >= 25) return 0;

  std::string stat = std::to_string(index) + std::to_string(cnt) + std::to_string(rest_grade);
  if (memory.count(stat)==1) return memory[stat];

  int ans = dfs(problems, index + 1, cnt, rest_grade - problems[index], memory) +
	  dfs(problems, index + 1, cnt - 1, rest_grade, memory);
  memory[stat] = ans;
  return ans;
}

void solution() {
  int grade = 0;
  std::cin >> grade;
  int problems[25];
  for (int i = 0; i < 10; ++i) {
	problems[i] = 2;
  }
  for (int i = 10; i < 20; ++i) {
	problems[i] = 4;
  }
  for (int i = 20; i < 25; ++i) {
	problems[i] = 8;
  }
  std::unordered_map<std::string, int> memory;

  std::cout << dfs(problems, 0, 3, grade, memory);
}