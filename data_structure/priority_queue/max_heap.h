//
// Created by lp on 2022/11/16.
//
#include "vector"
#include "initializer_list"
#include "cassert"

template<typename T>
class Heap {
 public:
  Heap() : m_data() {}
  explicit Heap(const std::vector<T> &data) : m_data(data) { make_heap(); }
  Heap(const std::initializer_list<T> &l) : m_data(l) { make_heap(); }
  Heap(const Heap<T> &heap) : m_data(heap.m_data) {}
  Heap(Heap<T> &&heap) noexcept {
	m_data = std::move(heap.m_data);
  }
  ~Heap() = default;

 public:
  void make_heap() {
	int size = m_data.size();
	if (size <= 1) return;

	for (int i = (size - 2)/2; i >= 0; --i) {
	  _top2down(i);
	}
  }

  void pop() {
	m_data[0] = m_data.back();
	m_data.pop_back();
	_top2down(0);
  }

  void push(const T &value) {
	m_data.push_back(value);
	_down2top(m_data.size() - 1);
  }

  int top() {
	assert(!m_data.empty());
	return m_data[0];
  }

  int size() {
	return m_data.size();
  }

 private:
  void _top2down(int pos) {
	int size = m_data.size();
	int left_child = pos*2 + 1, right_child = pos*2 + 2;
	int largest = pos;

	if (left_child < size && m_data[left_child] > m_data[largest]) largest = left_child;
	if (right_child < size && m_data[right_child] > m_data[largest]) largest = right_child;
	if (largest!=pos) {
	  std::swap(m_data[largest], m_data[pos]);
	  _top2down(largest);
	}
  }

  void _down2top(int pos) {
	int parent = (pos - 1)/2;
	while (pos > 0 && m_data[pos] > m_data[parent]) {
	  std::swap(m_data[pos], m_data[parent]);
	  pos = parent;
	  parent = (pos - 1)/2;
	}
  }

 private:
  std::vector<T> m_data;
};