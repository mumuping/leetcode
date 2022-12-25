//
// Created by lp on 2022/9/30.
//

#include "vector"
#include "random"
#include "algorithm"

// 选择随机的 pivot
void random_pivot(std::vector<int> &nums, int left, int right) {
  int tmp = random()%(right - left + 1) + left;
  std::swap(nums[left], nums[tmp]);
}

int quick_selection(std::vector<int> &nums, int left, int right) {
  // 这里我们没采用随机化，最坏情况为 O(n^2)
  int pivot = nums[left];
  while (left < right) {
	// 从后往前找，找到小于 pivot 的元素并交换之
	while (left < right && nums[right] >= pivot)--right;
	nums[left] = nums[right];
	// 从前往后找，找到大于 pivot 的元素并交换之
	while (left < right && nums[left] <= pivot)++left;
	nums[right] = nums[left];
  }
  // 把 pivot 放入正确的位置
  nums[left] = pivot;
  return left;
}

int findKthLargest(std::vector<int> &nums, int k) {
  int left = 0, right = nums.size() - 1;
  if (right==0)return nums[0];

  k = nums.size() - k;

  int pivot = 0;
  while (true) {
	pivot = quick_selection(nums, left, right);
	// 如果下标相等，表明找到了
	if (pivot==k)return nums[pivot];
	// 如果 pivot>k 则表明在左边部分
	if (pivot > k) right = pivot - 1;
	  // 否则在右边部分
	else left = pivot + 1;
  }
}

// 另一种方法是采用堆排序
int findKthLargest_(std::vector<int> &nums, int k) {
  std::make_heap(nums.begin(), nums.end());
  int count = 0;
  while (k > 0) {
	std::pop_heap(nums.begin(), nums.end() - count);
	--k;
	++count;
  }
  return nums[nums.size() - count];
}

// 写到这里，就顺便写一个堆排序

// top-to-down
void maxHeapify(std::vector<int> &nums, int i, int heapSize) {
  int left_child = 2*i + 1, right_child = 2*i + 2;

  int tmp = i;
  // 如果左孩子存在
  if (left_child < heapSize) {
	// 如果右孩子也存在
	if (right_child < heapSize) {
	  // 找到最大的
	  if (nums[i] > std::max(nums[left_child], nums[right_child])) return;
	  else i = nums[left_child] > nums[right_child] ? left_child : right_child;
	} else {
	  // 如果右孩子不存在
	  i = nums[i] >= nums[left_child] ? i : left_child;
	}

	// 判断 i 是否发生变化
	if (tmp==i)return;
	std::swap(nums[i], nums[tmp]);
	maxHeapify(nums, i, heapSize);
  }
  // 如果左孩子不存在，则直接返回
  return;
}

// or
//void maxHeapify(vector<int>& a, int i, int heapSize) {
//  int l = i * 2 + 1, r = i * 2 + 2, largest = i;
//  if (l < heapSize && a[l] > a[largest]) {
//	largest = l;
//  }
//  if (r < heapSize && a[r] > a[largest]) {
//	largest = r;
//  }
//  if (largest != i) {
//	swap(a[i], a[largest]);
//	maxHeapify(a, largest, heapSize);
//  }
//}

void buildMaxHeap(std::vector<int> &nums, int size) {
  for (int i = nums.size()/2; i >= 0; --i) {
	maxHeapify(nums, i, size);
  }
}

int findKthLargest__(std::vector<int> &nums, int k) {
  int heapSize = nums.size();
  buildMaxHeap(nums, heapSize);
  for (int i = nums.size() - 1; i >= nums.size() - k + 1; --i) {
	std::swap(nums[0], nums[i]);
	--heapSize;
	maxHeapify(nums, 0, heapSize);
  }
  return nums[0];
}
