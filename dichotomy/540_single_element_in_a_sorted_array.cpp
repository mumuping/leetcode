//
// Created by lp on 2022/9/28.
//

#include "vector"

// 采用二分法，每次去掉左边或右边成对的元素
int singleNonDuplicate(std::vector<int> &nums) {
  int left = 0, right = nums.size() - 1, mid;
  if (right==0) return nums[0];

  while (left < right) {
	mid = (left + right)/2;

	// mid 和左右两边都不相同，显然结果就是它，如 3，3，4，5，5
	if (nums[mid]!=nums[mid - 1] && nums[mid]!=nums[mid + 1]) return nums[mid];

	// mid 和 mid1+1 值相同，如 3，4（mid），4
	if (nums[mid]==nums[mid + 1]) {
	  // 如果 mid 右边是偶数，则表示右边全是成对的，去掉右边
	  if ((right - mid + 1)%2==0) right = mid - 1;
		// 否则去掉左边
	  else left = mid + 2;
	} else {    // mid 和 mid-1 值相同，如 3，3（mid），4
	  // 如果 mid 左边是偶数，则表示左边全是成对的，去掉左边
	  if ((mid - left + 1)%2==0) left = mid + 1;
	  else right = mid - 2;
	}
  }
  return nums[left];
}

// 方法二：采用下标是奇数还是偶数来进行判断
// 1，1，2，2，3，4，4

int singleNonDuplicate_(std::vector<int> &nums) {
  int left = 0, right = nums.size() - 1, mid;
  if (right==0)return nums[0];

  while (left < right) {
	mid = left + (right - left)/2;

	// 如果 mid 是偶数，则比较 mid 和 mid+1 是否相等（mid+1=mid^1）
	// 如果相等表示 mid 左边是成对的，否则表示右边是成对的
	// 如果 mid 是奇数，则比较 mid 和 mid-1 是否相等（mid-1=mid^1）
	// 如果相等表示 mid 左边是成对的，否则表示右边是成对的
	if (nums[mid]==nums[mid ^ 1]) left = mid + 1;
	else right = mid;
  }
  return nums[left];
}
