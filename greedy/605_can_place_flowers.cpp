//
// Created by lp on 2022/9/23.
//

#include "vector"

/* 暴力 */
bool canPlaceFlowers(std::vector<int> &flowerbed, int n) {
  if (n==0) return true;

  int size_flowerbed = flowerbed.size();
  if (size_flowerbed==1) {
	if (n==1 && flowerbed[0]==0)return true;
	else return false;
  }

  // handle the first plot
  if (flowerbed[0]==0 && flowerbed[1]==0) {
	--n;
	flowerbed[0] = 1;
  }

  // handle the middle plots
  int pre = 0, cur = 1, next = 2;
  while (next < size_flowerbed) {
	if (n==0) return true;
	if (flowerbed[cur]==0 && flowerbed[pre]==0 && flowerbed[next]==0) {
	  --n;
	  flowerbed[cur] = 1;
	}
	++pre;
	++cur;
	++next;
  }

  // handle the last plot
  if (flowerbed[cur]==0 && flowerbed[pre]==0) {
	--n;
	flowerbed[cur] = 1;
  }

  if (n==0) return true;
  return false;
}

/* 通过计算 10000001 等中间的 [i,j] 可以种多少花，以及开始部分 00001 和结尾部分 000001 */
bool canPlaceFlowers_another(std::vector<int> &flowerbed, int n) {
  if (n==0) return true;

  int size_flowerbed = flowerbed.size();
  int pre = -1;
  for (int i = 0; i < size_flowerbed; ++i) {
	if (flowerbed[i]==1) {
	  if (pre==-1) {
		n -= i/2;
	  } else if (i - pre > 3) {
		n -= ((i - pre)/2 - 1);
	  }
	  pre = i;
	  if (n < 1)return true;
	}
  }

  if (pre==-1) {
	n -= (size_flowerbed + 1)/2;
  } else if (flowerbed[size_flowerbed - 1]==0 && size_flowerbed - 1 - pre > 1) {
	n -= ((size_flowerbed - 1 - pre)/2);
  }

  if (n < 1)return true;
  else return false;
}
