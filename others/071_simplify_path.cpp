//
// Created by 18315 on 2023/3/3.
//

#include "string"
#include "vector"

std::string simplifyPath(std::string path) {
  if (path.empty()) return {};
  int n = path.length();
  std::vector<std::string> contents;
  int start = 0, end = 0;
  while (end < n) {
    start = end;
    while (start < n - 1 && path[start] == path[start + 1]) {
      ++start;
    }
    if (start == n - 1) {
      break;
    }
    end = start + 1;

    std::string t;
    while (end < n && path[end] != '/') {
      t += path[end];
      ++end;
    }
    if (t.compare(".") == 0) continue;
    else if (t.compare("..") == 0) {
      if (!contents.empty()) contents.pop_back();
    } else {
      contents.push_back(t);
    }
  }

  std::string res;
  for (const auto &str : contents) {
    res += "/" + str;
  }
  return res.empty() ? "/" : res;
}