//
// Created by lp on 2022/11/14.
//
#include "vector"

int maxChunksToSorted(std::vector<int> &arr) {
  int size = arr.size();
  int chunks = 0, tmp = -1;

  for (int i = 0; i < size; ++i) {
	tmp = std::max(tmp, arr[i]);
	if (i==tmp) {
	  ++chunks;
	  tmp = -1;
	}
  }

  return chunks;
}