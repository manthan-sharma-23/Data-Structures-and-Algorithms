#include <vector>

using namespace std;

class Solution {
public:
  const vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
  void dfs(vector<vector<char>> &board, vector<vector<bool>> &visited, int x,
           int y, int m, int n) {
    board[x][y] = '1';
    visited[x][y] = true;

    for (auto &[dx, dy] : directions) {
      int nx = x + dx;
      int ny = y + dy;

      if (nx >= 0 && nx < m && ny >= 0 && ny < n && board[nx][ny] == 'O' &&
          !visited[nx][ny]) {
        dfs(board, visited, nx, ny, m, n);
      }
    }
  }

  void solve(vector<vector<char>> &board) {

    int m = board.size(), n = board[0].size();
    vector<vector<bool>> visited(m, vector<bool>(n, 0));

    for (int i = 0; i < m; i++) {
      if (board[i][0] == 'O' && !visited[i][0])
        dfs(board, visited, i, 0, m, n);
      if (board[i][n - 1] == 'O' && !visited[i][n - 1])
        dfs(board, visited, i, n - 1, m, n);
    }
    for (int j = 0; j < n; j++) {
      if (board[0][j] == 'O' && !visited[0][j])
        dfs(board, visited, 0, j, m, n);
      if (board[m - 1][j] == 'O' && !visited[m - 1][j])
        dfs(board, visited, m - 1, j, m, n);
    }

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (board[i][j] == 'O') {
          board[i][j] = 'X';
        } else if (board[i][j] == '1') {
          board[i][j] = 'O';
        }
      }
    }
  }
};