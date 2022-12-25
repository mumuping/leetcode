//
// Created by lp on 2022/9/27.
//
#include "vector"

// 方法一：先找到这个旋转点，再两边分别进行二分搜索
// 采用左闭右闭
// 采用 left=mid or right=mid，因为如果采用 left=mid+1 or right=mid+1 那么可能会导致跳过这个断点
// 从而导致无法分清每种情况应该返回 left 还是 right
// 这样 left 和 right 才不会跳过断点，而只会在断点的两边
int find_the_position_of_rotated(const std::vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1, mid;
  while (left + 1 < right) {
	mid = (left + right)/2;
	if (nums[mid] > nums[left])left = mid;
	else right = mid;
  }
  return left;
}

int binary_search(const std::vector<int> &nums, int target, int left, int right) {
  int mid;
  while (left <= right) {
	mid = (left + right)/2;
	if (nums[mid]==target)return mid;
	else if (nums[mid] < target)left = mid + 1;
	else right = mid - 1;
  }
  return -1;
}

int search(std::vector<int> &nums, int target) {
  int right = nums.size() - 1;
  if (right==0) return nums[0]==target ? 0 : -1;

  int position = find_the_position_of_rotated(nums, target);
  int result = binary_search(nums, target, 0, position);
  if (result==-1)
	return binary_search(nums, target, position + 1, right);
  else
	return result;
}

// 方法二：在寻找断点的过程中，顺带查找 target
int search_another(std::vector<int> &nums, int target) {
  int left = 0, right = nums.size() - 1, mid;
  if (right==0)return target==nums[0] ? 0 : -1;

  // 采用左闭右闭
  while (left <= right) {
	mid = (left + right)/2;
	if (nums[mid]==target)return mid;

	if (nums[mid] >= nums[left]) {
	  // 如果 target 在 [left,mid) 区间
	  if (nums[left] <= target && target < nums[mid])
		right = mid - 1;    // 把 right 更新为 mid-1
	  else left = mid + 1;    // 否则把 left 更新为 mid+1
	} else {
	  // 如果 target 在 (mid, right] 区间
	  if (nums[mid] < target && target <= nums[right])
		left = mid + 1;
	  else right = mid - 1;
	}
  }

  return -1;
}