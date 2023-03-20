//
// Created by 18315 on 2023/3/20.
//
// https://www.bilibili.com/video/BV1Ca411a72E/?spm_id_from=333.788&vd_source=cae965f23b6cb71143bed6af4be19e37

#include <vector>
#include <iostream>
#include <string>

void solution() {
  std::string s;
  std::cin >> s;

  int n = s.length();
  std::vector<int> attack(n + 1), defence(n + 1);
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') {
      attack[i + 1] = attack[i] + i + 1;
    } else {
      attack[i + 1] = attack[i];
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '1') {
      defence[i] = defence[i + 1] + i + 1;
    } else {
      defence[i] = defence[i + 1];
    }
  }

  int pos = 0, difference = INT_MAX, tmp;
  for (int i = 0; i <= n; ++i) {
    tmp = std::abs(attack[i] - defence[i]);
    if (tmp < difference) {
      difference = tmp;
      pos = i;
    }
  }
  std::cout << difference << std::endl;
}
