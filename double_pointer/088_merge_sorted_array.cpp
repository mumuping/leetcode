//
// Created by lp on 2022/9/20.
//
#include "vector"

void merge(std::vector<int> &nums1, int m, std::vector<int> &nums2, int n) {
  int pointer_to_end_nums1 = m - 1, pointer_to_end_nums2 = n - 1;
  int index_to_add = m + n - 1;

  while (pointer_to_end_nums1 >= 0 || pointer_to_end_nums2 >= 0) {
	// 此处判断必须放在前面，因为如果 pointer_to_end_nums1 == -1 则调用 nums1[pointer_to_end_nums1] 会出界
	if (pointer_to_end_nums1==-1 && pointer_to_end_nums2!=-1) {
	  std::copy(nums2.begin(), nums2.begin() + pointer_to_end_nums2 + 1, nums1.begin());
	  return;
	}
	if (pointer_to_end_nums2==-1 && pointer_to_end_nums1!=-1)
	  return;

	if (nums1[pointer_to_end_nums1] > nums2[pointer_to_end_nums2]) {
	  nums1[index_to_add] = nums1[pointer_to_end_nums1];
	  --pointer_to_end_nums1;
	} else {
	  nums1[index_to_add] = nums2[pointer_to_end_nums2];
	  --pointer_to_end_nums2;
	}
	--index_to_add;
  }
  return;
}