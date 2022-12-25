//
// Created by lp on 2022/9/29.
//

#include "vector"

/**
 * 找到两个数组中第 k 小的数
 * @param nums1
 * @param nums2
 * @param k
 * @return
 */
int findKthMinimum(const std::vector<int> &nums1, const std::vector<int> &nums2, int k) {
  /* 主要思路：每次去除第 [0, k-1] 小的一部分，直到去除所有 [0,k-1]
   * 要找到第 k (k>1) 小的元素，那么就取 pivot1 = nums1[k/2-1] 和 pivot2 = nums2[k/2-1] 进行比较
   * 这里的 "/" 表示整除
   * nums1 中小于等于 pivot1 的元素有 nums1[0 .. k/2-2] 共计 k/2-1 个
   * nums2 中小于等于 pivot2 的元素有 nums2[0 .. k/2-2] 共计 k/2-1 个
   * 取 pivot = min(pivot1, pivot2)，两个数组中小于等于 pivot 的元素共计不会超过 (k/2-1) + (k/2-1) <= k-2 个
   * 这样 pivot 本身最大也只能是第 k-1 小的元素
   * 如果 pivot = pivot1，那么 nums1[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums1 数组
   * 如果 pivot = pivot2，那么 nums2[0 .. k/2-1] 都不可能是第 k 小的元素。把这些元素全部 "删除"，剩下的作为新的 nums2 数组
   * 由于我们 "删除" 了一些元素（这些元素都比第 k 小的元素要小），因此需要修改 k 的值，减去删除的数的个数
   */
  int size_nums1 = nums1.size(), size_nums2 = nums2.size();
  int left1 = 0, left2 = 0;

  int pivot1, pivot2;
  while (true) {
	// 如果 nums1 或 nums2 为空，则直接返回剩下数组的 left+k
	if (left1==size_nums1) return nums2[left2 + k - 1];
	if (left2==size_nums2) return nums1[left1 + k - 1];

	// 如果 k==1 时，直接返回 nums1 和 nums2 中最左边的最小值即可
	// 注意这里要放到上式的下面，因为可能出现 当 k==1 时，恰好 left1===size_nums1，
	// 此时就会出现越界的情况
	if (k==1)
	  return std::min(nums1[left1], nums2[left2]);

	// 考虑 k/2-1 超界的问题
	// 如果超界，则用最后一个元素代替
	pivot1 = std::min(k/2 - 1 + left1, size_nums1 - 1);
	pivot2 = std::min(k/2 - 1 + left2, size_nums2 - 1);

	// 开始处理正常情况
	if (nums1[pivot1] <= nums2[pivot2]) {
	  k -= pivot1 - left1 + 1;
	  left1 = pivot1 + 1;

	} else {
	  k -= pivot2 - left2 + 1;
	  left2 = pivot2 + 1;
	}
  }
}

double findMedianSortedArrays(std::vector<int> &nums1, std::vector<int> &nums2) {
  int total_length = nums1.size() + nums2.size();
  if (total_length%2==0)
	return (findKthMinimum(nums1, nums2, total_length/2) + findKthMinimum(nums1, nums2, total_length/2 + 1))/2.0;
  else return findKthMinimum(nums1, nums2, (total_length + 1)/2);
}