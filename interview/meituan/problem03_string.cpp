//
// Created by lp on 2023/3/25.
//

#include <string>
#include <iostream>

void solution() {
  std::string str;
  std::cin >> str;
  if (str.length()==1) {
	std::cout << "a" << std::endl;
	return;
  }

  int left = 0, right = str.length() - 1;
  int modified = 0;
  std::pair<int, int> need_to_be_modified[2];
  while (left < right) {
	if (str[left]!=str[right]) {
	  need_to_be_modified[modified].first = left;
	  need_to_be_modified[modified].second = right;
	  ++modified;
	}
	++left;
	--right;
  }

  if (modified==0) {
	left = 0, right = str.length() - 1;
	while (left < right && str[left]=='a') {
	  ++left;
	  --right;
	}
	if (left==right) {
	  str[left] = 'a';
	} else if (left < right) {
	  str[left] = str[right] = 'a';
	}
  } else if (modified==1) {
	left = need_to_be_modified[0].first, right = need_to_be_modified[0].second;
	if (str[left]=='a' || str[right]=='a') {
	  str[left] = str[right] = 'a';
	  if (str.length()%2) {
		str[str.length()/2] = 'a';
	  }
	} else {
	  str[left] = str[right] = 'a';
	}
  } else {
	left = need_to_be_modified[0].first, right = need_to_be_modified[0].second;
	if (str[left] < str[right]) str[right] = str[left];
	else str[left] = str[right];
	left = need_to_be_modified[1].first, right = need_to_be_modified[1].second;
	if (str[left] < str[right]) str[right] = str[left];
	else str[left] = str[right];
  }

  std::cout << str << std::endl;
}