//
// Created by lp on 2022/9/28.
//

#include "vector"

int findMin(std::vector<int> &nums) {
  int left = 0, right = nums.size() - 1, mid;
  if (right==0) return nums[0];

  // 处理这种情况：nums[left]==nums[mid]==nums[right]
  // 这时是无法分清是处理左边还是右边
  // 因此只需要简单将 left 和 right 向中间靠即可
  mid = (left + right)/2;
  while (left <= right && nums[left]==nums[mid] && nums[mid]==nums[right]) {
	++left;
	--right;
  }

  // 上面处理完后，要判断是否是升序，因为如果是升序的话，下式 while 是判断不了的
  // 注意这里不能写 <=，因为会存在 3，1，3 等情况
  // 这里思考 == 是因为上面那个 while 中如果出现 left>=right，则直接可以返回 nums[left]
  if (nums[left] < nums[right])return nums[left];

  while (left + 1 < right) {
	mid = (left + right)/2;
	if (nums[mid] >= nums[left])left = mid;
	else right = mid;
  }
  return nums[right];
}