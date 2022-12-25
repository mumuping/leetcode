//
// Created by lp on 2022/11/12.
//

bool hasAlternatingBits(int n) {
  unsigned int n_xor = n ^ (n >> 1);
  return (n_xor & (n_xor + 1))==0;
}