//
// Created by lp on 2022/11/12.
//

int findComplement(int num) {
  int a = 1, b = num;
  while ((b >>= 1)!=0) {
	a <<= 1;
	a |= 1;
  }

  return a ^ num;
}