//
// Created by lp on 2022/11/19.
//
#include "vector"
#include "deque"
#include "queue"

// 双端队列
// 此题跟单调栈很相似
std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
  int n = nums.size();
  if (k==1) return nums;

  std::deque<int> dq;        // 存储索引
  std::vector<int> ans;
  for (int i = 0; i < n; ++i) {
	// 把前面不在范围内的数去除
	while (!dq.empty() && dq.front() <= i - k) {
	  dq.pop_front();
	}

	// 把从后往前的、小于等于 nums[i] 的数去除
	while (!dq.empty() && nums[dq.back()] <= nums[i]) {
	  dq.pop_back();
	}
	dq.push_back(i);

	if (i >= k - 1) ans.push_back(nums[dq.front()]);
  }

  return ans;
}

// 也可以使用堆，其时间复杂度为 O(nlogn)
std::vector<int> maxSlidingWindow_heap(std::vector<int> &nums, int k) {
  int n = nums.size();
  if (k==1) return nums;

  std::priority_queue<std::pair<int, int>> pq;
  std::vector<int> ans;

  // 初始化
  int i = 0;
  for (; i < k; ++i) {
	pq.emplace(nums[i], i);
  }
  ans.push_back(pq.top().first);

  for (; i < n; ++i) {
	pq.emplace(nums[i], i);
	while (pq.top().second <= i - k) {
	  pq.pop();
	}
	ans.push_back(pq.top().first);
  }

  return ans;
}

// 分块加预处理，时间复杂度 O(n)
std::vector<int> maxSlidingWindow_block(std::vector<int> &nums, int k) {
  int n = nums.size();
  if (k==1) return nums;

  std::vector<int> prefixMax(n), suffixMax(n);
  for (int i = 0; i < n; ++i) {
	if (i%k==0) {
	  prefixMax[i] = nums[i];
	} else {
	  prefixMax[i] = std::max(prefixMax[i - 1], nums[i]);
	}
  }

  for (int i = n - 1; i >= 0; --i) {
	if (i==n - 1 || (i + 1)%k==0) {
	  suffixMax[i] = nums[i];
	} else {
	  suffixMax[i] = std::max(suffixMax[i + 1], nums[i]);
	}
  }

  std::vector<int> ans;
  for (int i = 0; i <= n - k; ++i) {
	ans.push_back(std::max(suffixMax[i], prefixMax[i + k - 1]));
  }

  return ans;
}