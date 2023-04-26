//
// Created by lp on 2023/4/26.
//
/**
 * http://codefun2000.com/p/P1002
 * 塔子哥要去学校接他的弟弟，但是他不想排队。他发现学校的学生放学回家有五个优先级，
 * 学习成绩越好回家时间越快，1 表示学习成绩最好，5 表示学习成绩最差。
 * 现在他知道如果他弟弟是当前学习成绩最好的学生，那么他可以插队到其他人前面去接他弟弟。
 * 给定一个学生的编号和他的学习成绩的时间表，输出每次被接回家的学生时的学生编号。
 * 如果有多个同级优先级的学生，按照到达顺序被接回家。
*/

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

int main() {
  int n;
  std::cin >> n;

  char c;
  std::priority_queue<int, std::vector<int>, std::greater<int>> grades;
  std::unordered_map<int, std::vector<int>> grade_to_nums;
  int grade, num;
  while (n != 0) {
    --n;
    std::cin >> c;
    if (c == 'a') {
      std::cin >> num >> grade;
      grades.push(grade);
      grade_to_nums[grade].emplace_back(num);
    } else if (c == 'p') {
      grade = grades.top();
      grades.pop();
      std::cout << grade_to_nums[grade].front() << std::endl;
      grade_to_nums[grade].erase(grade_to_nums[grade].begin());
    }
  }
  return 0;
}