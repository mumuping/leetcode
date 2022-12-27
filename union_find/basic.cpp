//
// Created by lp on 2022/12/26.
//

struct node {
  node *parent;
  int rank;
  node() : parent(this), rank(0) {}
  node(node *p) : parent(p) {}
};

// 第一种方法：按秩合并
node *Find(node *x) {
  if (x->parent==x) return x;
  return Find(x->parent);
}

node *Union(node *first, node *second) {
  node *parent1 = Find(first);
  node *parent2 = Find(second);
  if (parent1==parent2) return parent1;
  else if (parent1->rank < parent2->rank) {
	parent1->parent = parent2;
	return parent2;
  } else if (parent1->rank > parent2->rank) {
	parent2->parent = parent1;
	return parent1;
  } else {
	parent1->parent = parent2;
	parent2->rank += 1;
	return parent2;
  }
}

// 第二种方法：压缩
node *Find_Compression(node *x) {
  if (x->parent==x) return x;
  x->parent = Find_Compression(x->parent);
  return x->parent;
}

node *Union_Compression(node *first, node *second) {
  node *parent1 = Find_Compression(first);
  node *parent2 = Find_Compression(second);
  if (parent1==parent2) return parent1;
  parent1->parent = parent2;
  return parent2;
}