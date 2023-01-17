//
// Created by 18315 on 2023/1/17.
//
#include "vector"

extern bool knows(int i, int j);

int findCelebrity(int n) {
  if (n == 0) return -1;
  if (n == 1) return 0;

  int celebrity = 0;
  for (int i = 1; i < n; ++i) {
    if (knows(celebrity, i)) celebrity = i;
  }

  for (int i = 0; i < n; ++i) {
    if (celebrity == i) continue;
    if (!knows(i, celebrity) || knows(celebrity, i)) return -1;
  }

  return celebrity;
}