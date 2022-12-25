//
// Created by lp on 2022/11/6.
//
#include "vector"
#include "numeric"

// 由于不能采用除法，因此最简单的方法是采用两个数组分别存储从左到右和从右到左的乘积
std::vector<int> productExceptSelf(std::vector<int> &nums) {
  int size = nums.size();
  if (size==1) return {nums[0]};

  std::vector<int> left2right(size, 0);
  std::vector<int> right2left(size, 0);

  std::partial_sum(nums.begin(), nums.end(), left2right.begin(), [](int val, int ele) {
	return val*ele;
  });
  std::partial_sum(nums.rbegin(), nums.rend(), right2left.rbegin(), [](int val, int ele) {
	return val*ele;
  });

  std::vector<int> answer(size, 0);
  answer[0] = right2left[1];
  answer[size - 1] = left2right[size - 2];
  for (int i = 1; i < size - 1; ++i) {
	answer[i] = left2right[i - 1]*right2left[i + 1];
  }

  return answer;
}

// 显然上面方法空间复杂度很高
// 可以这样想，若已经算出了 [1,2,3] 的结果，那么计算 [1,2,3,4] 时，
// 只需要把 [1,2,3] x 4，然后把 [3] x 3 作为 [4] 的结果
// 但是时间复杂度不满足，为 O(n^2)
std::vector<int> productExceptSelf_(std::vector<int> &nums) {
  int size = nums.size();
  if (size==1) return {nums[0]};

  std::vector<int> answer(size);
  answer[0] = 1;
  for (int i = 1; i < size; ++i) {
	answer[i] = answer[i - 1]*nums[i - 1];
	for (int j = 0; j < i; ++j) {
	  answer[j] *= nums[i];
	}
  }

  return answer;
}

// 我们可以再想一想，可以把输出空间也利用上
std::vector<int> productExceptSelf__(std::vector<int> &nums) {
  int size = nums.size();
  if (size==1) return {nums[0]};

  std::vector<int> answer(size);
  // answer 此时记录的是从右到左的乘积
  std::partial_sum(nums.rbegin(), nums.rend(), answer.rbegin(), [](int val, int p) {
	return val*p;
  });

  int product_of_left2right = 1;
  for (int i = 0; i < size - 1; ++i) {
	answer[i] = product_of_left2right*answer[i + 1];
	product_of_left2right *= nums[i];
  }
  answer[size - 1] = product_of_left2right;

  return answer;
}