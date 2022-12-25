//
// Created by lp on 2022/9/25.
//

#include "vector"
#include "algorithm"

std::vector<std::vector<int>> reconstructQueue(std::vector<std::vector<int>> &people) {
  size_t size_people = people.size();

  // 按照 k 从小到大排序，若 k 相等，则按照 h 从大到小排序
  std::sort(people.begin(), people.end(), [](const std::vector<int> &first, const std::vector<int> &second) {
	if (first[1] < second[1]) return true;
	if (first[1]==second[1] && first[0] > second[0])return true;
	return false;
  });

  std::vector<std::vector<int>> queue;
  queue.reserve(size_people);
  int k = 0;
  int j = 0;
  // 将 people 中的人依次插入到队列中，
  // 其中 people[i][1] 表示 queue 中前面应有 people[i][1] 个人比 people[i][0] 相等或更大
  for (int i = 0; i < size_people; ++i) {
	k = people[i][1];
	j = 0;
	while (k!=0) {
	  if (queue[j][0] >= people[i][0]) --k;
	  ++j;
	}
	queue.insert(queue.begin() + j, people[i]);
  }

  return queue;
}