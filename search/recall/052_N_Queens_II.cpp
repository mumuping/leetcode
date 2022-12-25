//
// Created by lp on 2022/10/8.
//
void backtracking(int row, int &count, int n,
				  bool *col_visited,
				  bool *left_diag_visited,
				  bool *right_diag_visit) {
  if (row==n) {
	++count;
	return;
  }

  for (int col = 0; col < n; ++col) {
	if (!col_visited[col] && !left_diag_visited[col + row] && !right_diag_visit[col - row + n - 1]) {
	  col_visited[col] = left_diag_visited[col + row] = right_diag_visit[col - row + n - 1] = true;

	  backtracking(row + 1, count, n, col_visited, left_diag_visited, right_diag_visit);

	  col_visited[col] = left_diag_visited[col + row] = right_diag_visit[col - row + n - 1] = false;
	}
  }
}

int totalNQueens(int n) {
  if (n==1)return 1;

  bool *col_visited = new bool[n]();
  bool *left_diag_visited = new bool[2*n - 1]();
  bool *right_diag_visited = new bool[2*n - 1]();

  int count=0;
  backtracking(0,count,n,col_visited,left_diag_visited,right_diag_visited);

  delete[] col_visited;
  delete[] left_diag_visited;
  delete[] right_diag_visited;

  return count;
}