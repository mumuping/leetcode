//
// Created by lp on 2023/2/5.
//
#include "string"

std::string intToRoman(int num) {
  const std::pair<int, std::string> value_symbols[] = {
	  {1000, "M"},
	  {900, "CM"},
	  {500, "D"},
	  {400, "CD"},
	  {100, "C"},
	  {90, "XC"},
	  {50, "L"},
	  {40, "XL"},
	  {10, "X"},
	  {9, "IX"},
	  {5, "V"},
	  {4, "IV"},
	  {1, "I"},
  };

  std::string res;
  for (int i = 0; i < 13; ++i) {
	while (num >= value_symbols[i].first) {
	  res += value_symbols[i].second;
	  num -= value_symbols[i].first;
	}
	if (num==0) break;
  }
  return res;
}

// 硬编码
std::string intToRoman_code(int num) {
  const std::string thousands[] = {"", "M", "MM", "MMM"};
  const std::string hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
  const std::string tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
  const std::string ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
  return thousands[num/1000] + hundreds[(num/100)%10] + tens[(num/10)%10] + ones[num%10];
}