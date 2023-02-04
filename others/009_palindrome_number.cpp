//
// Created by lp on 2023/2/4.
//

bool isPalindrome(int x) {
  if (x >= 0 && x <= 9) return true;
  if (x < 0 || x%10==0) return false;

  int reverse = 0;
  while (reverse < x) {
	reverse *= 10;
	reverse += x%10;
	x /= 10;
  }

  return reverse==x || reverse/10==x;
}