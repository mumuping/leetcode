//
// Created by lp on 2023/4/14.
//
#include <vector>
#include <climits>

/**
 * Take the example of the maximum value stored in the segment tree.
 */
class SegmentTreeMax {
 public:
  explicit SegmentTreeMax(const std::vector<int> &array) :
	  segment_tree_(static_cast<int>(array.size() << 2)),
	  lazy_tag_(static_cast<int>(array.size() << 2)) {
	Build(1, array.size(), 1, array);
  }

  /**
   * Build the segment tree.
   * @param l the left border of the interval
   * @param r the right border of the interval
   * @param curr_node the node that presents the interval
   * @param raw_array the raw array
   */
  auto Build(int l, int r, int curr_node, const std::vector<int>& raw_array) -> void {
	/** Reach the leaf node */
	if (l==r) {
	  segment_tree_[curr_node] = raw_array[l];
	  return;
	}
	int mid = l + ((r - l) >> 1);
	/** Build the left child tree and right child tree separately */
	Build(l, mid, curr_node << 1, raw_array);
	Build(mid + 1, r, curr_node << 1 | 1, raw_array);
	/** Update the current node */
	Pushup(curr_node);
  }

  /**
   * Update the raw_array_[index_to_be_updated] by the delta.
   * @param index_to_be_update the index of raw_array_[index_to_be_updated]
   * @param delta the amount of changes
   * @param l the left border of the interval
   * @param r the right border of the interval
   * @param curr_node current node that presents the interval
   */
  auto Update(int index_to_be_updated, int delta, int l, int r, int curr_node) -> void {
	/** Reach the leaf node */
	if (l==r) {
	  segment_tree_[curr_node] += delta;
	  return;
	}
	int mid = l + ((r - l) >> 1);
	/** Find the leaf node */
	if (index_to_be_updated <= mid) {
	  Update(index_to_be_updated, delta, l, mid, curr_node << 1);
	} else {
	  Update(index_to_be_updated, delta, mid + 1, r, curr_node << 1 | 1);
	}
	/** Update the current node */
	Pushup(curr_node);
  }

  /**
   * Query the value of the interval
   * @param query_l the left border of the query interval
   * @param query_r the right border of the query interval
   * @param l the left border
   * @param r the right border
   * @param curr_node the current node
   * @return
   */
  auto Query(int query_l, int query_r, int l, int r, int curr_node) -> int {
	/** If the query interval contains the interval [l, r] */
	if (query_l <= l && query_r >= r) {
	  return segment_tree_[curr_node];
	}
	Pushdown(curr_node);
	int mid = l + ((r - l) >> 1);
	int value = INT_MIN;
	if (query_l <= mid) {
	  value = std::max(value, Query(query_l, query_r, l, mid, curr_node << 1));
	}
	if (query_r > mid) {
	  value = std::max(value, Query(query_l, query_r, mid + 1, r, curr_node << 1 | 1));
	}
	return value;
  }

  /**
   * Interval range update.
   * @param update_l
   * @param update_r
   * @param delta
   * @param l
   * @param r
   * @param curr_node
   */
  auto UpdateInterval(int update_l, int update_r, int delta, int l, int r, int curr_node) -> void {
	if (update_l <= l && update_r >= r) {
	  lazy_tag_[curr_node] += delta;
	  segment_tree_[curr_node] += delta;
	  return;
	}
	Pushdown(curr_node);
	int mid = l + ((r - l) >> 1);
	if (update_l <= mid) {
	  UpdateInterval(update_l, update_r, delta, l, mid, curr_node << 1);
	}
	if (update_r > mid) {
	  UpdateInterval(update_l, update_r, delta, mid + 1, r, curr_node << 1 | 1);
	}
	Pushup(curr_node);
  }

 private:
  /**
   * Update the father node as the child node update.
   * @param k the father node index
   * @warning k is at least 1
   */
  auto Pushup(int k) -> void {
	segment_tree_[k] = std::max(segment_tree_[k << 1], segment_tree_[k << 1 | 1]);
  }

  /**
   * Update the left child node and right child as the father node lazy updates
   * @param curr_node
   */
  auto Pushdown(int curr_node) -> void {
	int lazy_value = lazy_tag_[curr_node];
	if (lazy_value) {
	  lazy_tag_[curr_node << 1] += lazy_value;
	  lazy_tag_[curr_node << 1 | 1] += lazy_value;
	  segment_tree_[curr_node << 1] += lazy_value;
	  segment_tree_[curr_node << 1 | 1] += lazy_value;
	  lazy_tag_[curr_node] = 0;
	}
  }

 private:
  /** The segment tree. It starts at index 1 */
  std::vector<int> segment_tree_;
  /** The lazy update array */
  std::vector<int> lazy_tag_;
};