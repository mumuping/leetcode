//
// Created by lp on 2022/9/26.
//

#include "vector"

// 方法一：先找到这个旋转点，再两边分别进行二分搜索
// 采用左闭右闭
// 采用 left=mid or right=mid，因为如果采用 left=mid+1 or right=mid+1 那么可能会导致跳过这个断点
// 从而导致无法分清每种情况应该返回 left 还是 right
// 这样 left 和 right 才不会跳过断点，而只会在断点的两边
int find_the_position_of_rotated(const std::vector<int> &nums, int left, int right) {
  int mid;
  while (left + 1 < right) {
	mid = (left + right)/2;
	if (nums[mid] >= nums[left])left = mid;
	else right = mid;
  }
  return left;
}

bool binary_search(const std::vector<int> &nums, int target, int left, int right) {
  int mid;
  while (left <= right) {
	mid = (left + right)/2;
	if (nums[mid]==target) return true;
	if (nums[mid] < target) left = mid + 1;
	else right = mid - 1;
  }
  return false;
}

bool search(std::vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1, mid = (left + right)/2;
  if (right==0)return target==nums[0];

  if (target==nums[left]) return true;
  // 如果 nums[left]==nums[mid]==nums[right] 时，是无法判断的
  // 此时只需要简单使左边加一和右边减一即可
  while (left <= right && nums[left]==nums[mid] && nums[right]==nums[mid]) {
	++left;
	--right;
  }
  if (right < left)return false;

  int position = find_the_position_of_rotated(nums, left, right);
  return binary_search(nums, target, 0, position) || binary_search(nums, target, position + 1, right);
}

// 方法二：在寻找断点的过程中，顺带查找 target
bool search_(std::vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1, mid;
  if (right==0) return target==nums[0];

  while (left <= right) {
	mid = (left + right)/2;
	if (nums[mid]==target)return true;

	// nums[mid]==nums[left]==nums[right] 这种情况是无法判断的，
	// 因此只需要将 left++ 和 right-- 即可
	if (nums[mid]==nums[left] && nums[mid]==nums[right]) {
	  ++left;
	  --right;
	} else if (nums[mid] >= nums[left]) {
	  // target 位于 [left, mid-1] 区间中
	  if (nums[left] <= target && target < nums[mid])
		right = mid - 1;
	  else left = mid + 1;    // target 位于 [mid+1, right] 中
	} else {
	  // target 位于 [mid+1, right] 区间中
	  if (nums[mid] < target && target <= nums[right])
		left = mid + 1;
	  else right = mid - 1;        // target 位于 [left, mid-1] 中
	}
  }
  return false;
}
