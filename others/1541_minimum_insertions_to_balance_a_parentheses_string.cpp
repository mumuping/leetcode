//
// Created by 18315 on 2023/1/20.
//
#include "string"

int minInsertions(std::string s) {
  const int n = s.size();
  int mini = 0, need = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '(') {
      need += 2;
      if (need % 2 == 1) {
        ++mini;
        --need;
      }
    } else {
      --need;
      if (need == -1) {
        ++mini;
        need = 1;
      }
    }
  }
  return mini + need;
}
