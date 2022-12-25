//
// Created by lp on 2022/10/10.
//
#include "vector"
#include "string"
#include "unordered_set"
#include "queue"
#include "unordered_map"

std::vector<std::vector<std::string>> findLadders(std::string beginWord,
												  std::string endWord,
												  std::vector<std::string> &wordList) {
  // 首先将 wordList 转化为 unordered_set，空间换时间
  std::unordered_set<std::string> search_wordList(wordList.begin(), wordList.end());

  // 若 wordList 中不存在 endWord，则直接返回空结果
  if (search_wordList.find(endWord)==search_wordList.end()) return {};

  // 要返回的结果
  std::vector<std::vector<std::string>> res;
  // bfs 层次遍历所需要的队列，里面存放的是*当前的路径*，
  // 当前路径的最后一个 word 就是当前应该遍历的
  std::queue<std::vector<std::string>> que;
  que.push({beginWord});

  // 开始进行 bfs 遍历
  std::vector<std::string> front_element_of_que;
  int length_of_current_level;    // 当前层的元素个数
  std::string current_word;        // 当前遍历到的 word
  bool is_find = false;            // 是否找到了 endWord
  std::vector<std::string> ready_to_remove;    // 每一层待删除元素
  while (!que.empty()) {
	length_of_current_level = que.size();

	// 对当前一层的所有元素进行遍历
	for (int i = 0; i < length_of_current_level; ++i) {
	  front_element_of_que = que.front();
	  que.pop();
	  current_word = front_element_of_que.back();    // 获取到当前应该遍历的 word

	  // 如果当前 word 就是 endWord，则将当前路径加入到结果 res 中，并在此层遍历结束后直接返回
	  if (current_word==endWord) {
		is_find = true;
		res.push_back(front_element_of_que);
		continue;    // 找到了就不用再往下搜索
	  }

	  // 将 current_word 有连接的单词也加入到 que 中
	  // 这里采用的方法是遍历 current_word 每个位置的不同单词是否存在 wordList 中
	  for (int j = 0; j < current_word.size(); ++j) {
		for (int k = 'a'; k <= 'z'; ++k) {
		  // 26 个英文字母
		  if (current_word[j]==k) continue;
		  char tmp = current_word[j];
		  current_word[j] = k;
		  if (search_wordList.find(current_word)!=search_wordList.end()) {
			front_element_of_que.push_back(current_word);    // 将新 word 插入到当前路径中
			que.push(front_element_of_que);            // 将当前路径插入到 que 中
			front_element_of_que.pop_back();                // 再将新 word 从当前路径取出来，恢复元素状态
			/* search_wordList.erase(current_word);         // 将新 word 从 wordList 中删除
			 * 不能在这里删除，因为可能此层的其他路径也会用到该 word
			 * 因此，需要将该 word 暂存，等到此层遍历结束后再删除
			 */
			ready_to_remove.push_back(current_word);    // 保存至待删除队列中
		  }
		  current_word[j] = tmp;
		}
	  }
	}
	// 在 wordList 中删除此层用到的 word
	for (auto &word : ready_to_remove)
	  search_wordList.erase(word);
	ready_to_remove.clear();
	// 如果此层找到了 endWord 直接返回结果
	if (is_find) return res;
  }

  return {};
}


// 上述的解决方案可能对某些测试用例会超时，因此采用另一种方法
/*
 * 双向BFS处理逻辑
 * 基本和单向BFS处理逻辑是差不多的，以 层节点 为单位来处理节点业务逻辑。
 * 只是当每一次层节点上的逻辑处理完后，再根据 两边 层节点的个数来优先选择处理那边。
 * 优先处理 层节点 数更少的一边。（关键词：更少）
 * 基本都是左进一层，换右进一层，再换左进一层.......这样两边缩进的方式

 * 本题双向BFS处理细节
 * 节点遍历逻辑：
 * 因为是2边同时向中间压缩的方式，没办法向上面单向BFS那样，以单层完整的转换路径作为节点的数据结构。
 * 所以本题先使用 双向BFS 先建立好单词之间完整的 树型转换序关系。
 * 再对此树型结构做回溯遍历，获取不同的转换序列。
 * 双向BFS退出条件：
 * 虽然是双向压缩，但是每次只处理一层的节点数，所以不会存在重复，或超过遍历的 层。
 * 当遍历到左右层高差距为 1 时就退出。
 * 也就是前层节点的 子节点 出现在另一层。
 * 树型 数据结构的建立：
 * 为了方便，选用 HashMap 来做树型数据的容器。（也不是不能真的做像多叉树的那样，用指针搭建树型结构。只是重新定义结构，代码和逻辑会变得更复杂，没必要）
 * HashMap这种 Key/Value 对的形式是具有递归的属性的，即Value里面的值，是别一个Key。
 * 数据保存：
 * 注意代码里面的这句 reversed ? next[s].push_back(w) : next[w].push_back(s);
 * 当是 左->右 遍历时，是以 父节点 为基准去转换成 子节点。（ w 为 KEY，s 为 VALUE）
 * 当是 右->左 遍历时，因为反向遍历，是以子节点为基准，去转换成 父节点。（ s 为 KEY，w 为 VALUE）

 * 作者：fengziL
 * 链接：https://leetcode.cn/problems/word-ladder-ii/solution/2chong-jie-fa-jian-ji-dai-ma-qing-xi-jie-3sjt/
 * 来源：力扣（LeetCode）
 * 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
 */
void backtracking(const std::string &src,
				  const std::string &dst,
				  std::unordered_map<std::string, std::vector<std::string>> &next,
				  std::vector<std::string> &path,
				  std::vector<std::vector<std::string>> &res);
std::vector<std::vector<std::string>> findLadders_(std::string beginWord,
												   std::string endWord,
												   std::vector<std::string> &wordList) {
  using namespace std;
  vector<vector<string>> res;
  unordered_set<string> dict(wordList.begin(), wordList.end()), head{beginWord}, tail{endWord};
  if (!dict.count(endWord)) return res;
  dict.erase(beginWord), dict.erase(endWord);
  unordered_map<string, vector<string>> next;
  bool reversed = false, found = false; // 一些初始化准备
  while (!head.empty()) {
	unordered_set<string> temp; // 保存已转化过的 string
	for (const auto &w : head) { // 层 遍历
	  string s = w;
	  for (size_t i = 0; i < s.size(); ++i) { // 回溯查找子节点
		char c = s[i];
		for (char j = 'a'; j <= 'z'; ++j) {
		  s[i] = j;
		  if (tail.count(s)) { // 退出条件
			reversed ? next[s].push_back(w) : next[w].push_back(s);
			found = true;
		  }
		  if (dict.count(s)) { // 保存已转换的子节点
			reversed ? next[s].push_back(w) : next[w].push_back(s);
			temp.insert(s);
		  }
		}
		s[i] = c;
	  }
	}
	if (found) break; // 退出
	for (const auto &w : temp) dict.erase(w); // 删除已转换的 string
	if (temp.size() <= tail.size()) head = temp; // 根据左右层节点大小来切换遍历方向
	else {
	  reversed = !reversed;
	  head = tail;
	  tail = temp;
	}
  }
  if (found) { // 根据上面双向BFS构建的树型数据结构来梳理出不同的转换序
	vector<string> path = {beginWord};
	backtracking(beginWord, endWord, next, path, res); // 回溯算法的应用
  }
  return res;
}

void backtracking(const std::string &src,
				  const std::string &dst,
				  std::unordered_map<std::string, std::vector<std::string>> &next,
				  std::vector<std::string> &path,
				  std::vector<std::vector<std::string>> &res) {
  if (src==dst) res.push_back(path);
  for (const auto &w : next[src]) { // 按 层 为单位回溯求不同的转换序
	path.push_back(w);
	backtracking(w, dst, next, path, res);
	path.pop_back();
  }
}