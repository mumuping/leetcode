//
// Created by lp on 2022/11/29.
//
#include "vector"
#include "algorithm"
#include "numeric"

std::vector<int> advantageCount(std::vector<int> &nums1, std::vector<int> &nums2) {
  int n = nums1.size();
  if (n==1) return nums1;

  std::vector<int> index1(n), index2(n);
  std::iota(index1.begin(), index1.end(), 0);
  std::iota(index2.begin(), index2.end(), 0);
  std::sort(index1.begin(), index1.end(), [&](int i, int j) { return nums1[i] < nums1[j]; });
  std::sort(index2.begin(), index2.end(), [&](int i, int j) { return nums2[i] < nums2[j]; });

  std::vector<int> res(n);
  int left = 0, right = n - 1;
  for (int i = 0; i < n; ++i) {
	if (nums1[index1[i]] > nums2[index2[left]]) {
	  res[index2[left]] = nums1[index1[i]];
	  ++left;
	} else {
	  res[index2[right]] = nums1[index1[i]];
	  --right;
	}
  }

  return res;
}

// 上面的方法还可以优化
std::vector<int> advantageCount_(std::vector<int> &nums1, std::vector<int> &nums2) {
  int n = nums1.size();
  if (n==1) return nums1;

  std::vector<int> index2(n);
  std::iota(index2.begin(), index2.end(), 0);
  std::sort(index2.begin(), index2.end(), [&](int i, int j) { return nums2[i] < nums2[j]; });
  std::sort(nums1.begin(), nums1.end());

  int left = 0, right = n - 1;
  for (const int i : nums1) {
	if (i > nums2[index2[left]]) nums2[index2[left++]] = i;
	else nums2[index2[right--]] = i;
  }

  return nums2;
}