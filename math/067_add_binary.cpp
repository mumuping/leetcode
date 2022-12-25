//
// Created by lp on 2022/11/6.
//
#include "string"
#include "algorithm"

std::string addBinary(std::string a, std::string b) {
  int size_a = a.size(), size_b = b.size();
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());

  std::string sum;
  char current_bit = 0, carry = 0;
  int i = 0, j = 0;
  while (i < size_a || j < size_b) {
	current_bit = carry;
	if (i < size_a) {
	  current_bit += a[i] - '0';
	  ++i;
	}
	if (j < size_b) {
	  current_bit += b[j] - '0';
	  ++j;
	}

	carry = current_bit/2;
	current_bit -= carry*2;
	sum += current_bit + '0';
  }
  if (carry) {
	sum += carry + '0';
  }
  std::reverse(sum.begin(), sum.end());

  return sum;
}

std::string addBinary_(std::string a, std::string b) {
  int size_a = a.size(), size_b = b.size();
  std::reverse(a.begin(), a.end());
  std::reverse(b.begin(), b.end());

  std::string sum;
  char current_bit = 0;
  bool carry = 0;
  int i = 0, j = 0;
  while (i < size_a || j < size_b) {
	current_bit = carry;
	if (i < size_a) {
	  current_bit += a[i] - '0';
	  ++i;
	}
	if (j < size_b) {
	  current_bit += b[j] - '0';
	  ++j;
	}

	carry = current_bit >> 1;
	if (carry) current_bit -= 2;
	sum += current_bit + '0';
  }
  if (carry) {
	sum += carry + '0';
  }
  std::reverse(sum.begin(), sum.end());

  return sum;
}