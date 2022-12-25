//
// Created by lp on 2022/11/10.
//

bool isPowerOfFour(int n) {
  if (n <= 0) return false;
  if (n==1 || n==4) return true;

  while (n%4==0) {
	if (n==4) return true;
	n /= 4;
  }

  return false;
}

// 采用位运算
bool isPowerOfFour_bits(int n) {
//  if (n <= 0) return false;
//  if (n==1 || n==4) return true;
//
//  const int BITS = 0x55555554;
//  if (((n & (-n)) | BITS)!=BITS) return false;
//  if (n & (n - 1)) return false;
//  return true;

  return n > 0 && !(n & (n - 1)) && (n & 1431655765);
}