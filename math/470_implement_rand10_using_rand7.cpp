//
// Created by lp on 2022/11/8.
//

// 随机生成 [1, 7]
extern int rand7();

// 拒绝采样
int rand10() {
  int col = 0, row = 0, index = 0;
  do {
	col = rand7();
	row = rand7();
	index = (row - 1)*7 + col;
  } while (index > 40);

  return 1 + (index - 1)%10;
}

int rand10_() {
  int a, b, index;
  while (true) {
	a = rand7();
	b = rand7();
	index = b + (a - 1)*7;
	if (index <= 40) {
	  return 1 + (index - 1)%10;
	}
	a = index - 40;
	b = rand7();
	// get uniform dist from 1 - 63
	index = b + (a - 1)*7;
	if (index <= 60) {
	  return 1 + (index - 1)%10;
	}
	a = index - 60;
	b = rand7();
	// get uniform dist from 1 - 21
	index = b + (a - 1)*7;
	if (index <= 20) {
	  return 1 + (index - 1)%10;
	}
  }
}
