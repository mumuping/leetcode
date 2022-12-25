//
// Created by lp on 2022/9/22.
//
#include "vector"

/*
 * 方法一：左右各遍历依次，每次都是处理上升序列，
 * 当前的值要比上一个遍历的值多 1
 */
int candy(std::vector<int> &ratings) {
  int size_ratings = ratings.size();
  if (size_ratings==1) return 1;

  std::vector<int> candy_of_child;
  candy_of_child.reserve(size_ratings);

  int i = 0;
  candy_of_child[i] = 1;
  // from left to right
  for (i = 1; i < size_ratings; ++i) {
	if (ratings[i - 1] < ratings[i]) candy_of_child[i] = candy_of_child[i - 1] + 1;
	else candy_of_child[i] = 1;
  }
  // from right to left
  i = size_ratings - 2;
  for (; i >= 0; --i) {
	if (ratings[i] > ratings[i + 1])
	  candy_of_child[i] = std::max(candy_of_child[i], candy_of_child[i + 1] + 1);
  }

  int sum = 0;
  for (i = 0; i < size_ratings; ++i)
	sum += candy_of_child[i];

  return sum;
}

int candy_another(std::vector<int> &ratings) {
  int size_ratings = ratings.size();
  if (size_ratings==1) return 1;

  int value_of_pre = 1;
  int steps_of_inc = 1, steps_of_dec = 1;
  int sum = 1;

  for (int i = 1; i < size_ratings; ++i) {
	if (ratings[i - 1]==ratings[i]) {
	  // 如果相等，则相当于 i 前面没有元素，只用将 sum 加一即可
	  // 因此重置参数
	  ++sum;
	  steps_of_inc = 1;
	  steps_of_dec = 1;
	  value_of_pre = 1;
	} else if (ratings[i - 1] < ratings[i]) {
	  // 如果是上升趋势，
	  value_of_pre += 1;
	  sum += value_of_pre;
	  // 注意这里不能写为 steps_of_inc+=1
	  // 因为在下降时，使用的是 value_of_pre 进行重置的
	  // 因此使用上面的表达式是无法重置的
	  // 而 value_of_pre 刚好又和 steps_of_inc 相等
	  // 因此使用 value_of_type
	  // 如果这里不好理解的话看下一个版本 candy_another_
	  steps_of_inc = value_of_pre;
	  steps_of_dec = 0;
	} else {
	  // 如果是下降
	  ++steps_of_dec;
	  // 如果下降的长度等于前一个上升的长度，
	  // 那么就需要将 steps_of_dec 加一，即替换最高点的值
	  if (steps_of_dec==steps_of_inc)
		++steps_of_dec;
	  sum += steps_of_dec;
	  // 注意这里重置 steps_of_inc 时，不应该写为 steps_of_inc = 1，
	  // 因为此时 steps_of_dec 可能还是小于 steps_of_inc 的，
	  // 还可能会用到 steps_of_inc，
	  // 而 value_of_pre 刚好只有上升时会用到，
	  // 因此只能用 value_of_pre 代替
	  value_of_pre = 1;
	}
  }

  return sum;
}

int candy_another_(std::vector<int> &ratings) {
  int size_ratings = ratings.size();
  if (size_ratings==1) return 1;

  int steps_of_inc = 1, steps_of_dec = 1;
  int sum = 1;

  int copy_of_steps_of_inc = 0;
  for (int i = 1; i < size_ratings; ++i) {
	if (ratings[i - 1]==ratings[i]) {
	  ++sum;
	  steps_of_inc = 1;
	  steps_of_dec = 1;
	  copy_of_steps_of_inc = 1;
	} else if (ratings[i - 1] < ratings[i]) {
	  steps_of_inc += 1;
	  sum += steps_of_inc;
	  // 重置 step_of_dec
	  steps_of_dec = 0;
	  // copy_of_steps_of_inc 始终是 steps_of_inc 的副本
	  copy_of_steps_of_inc = steps_of_inc;
	} else {
	  ++steps_of_dec;
	  if (steps_of_dec==copy_of_steps_of_inc)
		++steps_of_dec;
	  sum += steps_of_dec;
	  // 重置 steps_of_inc
	  steps_of_inc = 1;
	}
  }

  return sum;
}