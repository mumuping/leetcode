//
// Created by lp on 2022/11/9.
//
#include "unordered_set"
#include "cmath"

bool isHappy(int n) {
  if (n==0) return false;
  if (n==1) return true;

  std::unordered_set<int> set;
  set.insert(n);

  int val = n, sum = n;
  do {
	val = sum;
	sum = 0;
	while (val!=0) {
	  sum += pow(val%10, 2);
	  val /= 10;
	}
	if (sum==1) return true;
	else if (set.find(sum)!=set.end()) return false;
	else set.insert(sum);
  } while (true);
}

// 弗洛伊德循环检测法
// 其实就是快慢指针，如果存在循环则快慢指针一定会相遇，否则快指针一定先到达 1
int getNextNumber(int n) {
  int sum = 0;
  while (n!=0) {
	sum += pow(n%10, 2);
	n /= 10;
  }

  return sum;
}
bool isHappy_floyd(int n) {
  if (n==0) return false;
  if (n==1) return true;

  int fast = n, slow = n;
  do {
	fast = getNextNumber(getNextNumber(fast));
	if (fast==1) return true;
	slow = getNextNumber(slow);
	if (fast==slow) return false;
  } while (true);
}