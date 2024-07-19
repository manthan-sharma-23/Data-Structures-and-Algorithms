#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {

private:
  vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

  void dfs(int row, int col, vector<vector<bool>> &visited,
           const vector<vector<int>> &grid, int m, int n, int row0, int col0,
           vector<pair<int, int>> &vec) {
    visited[row][col] = true;
    vec.push_back({row - row0, col - col0});

    for (auto dir : directions) {
      int nrow = row + dir.first;
      int ncol = col + dir.second;

      if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] &&
          !visited[nrow][ncol]) {
        dfs(nrow, ncol, visited, grid, m, n, row0, col0, vec);
      } else {
        continue;
      }
    }
  }

public:
  int countDistinctIslands(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<bool>> visited(n, vector<bool>(m, false));
    set<vector<pair<int, int>>> st;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && grid[i][j]) {
          vector<pair<int, int>> vec;
          dfs(i, j, visited, grid, m, n, i, j, vec);
          st.insert(vec);
        }
      }
    }

    return st.size();
  }
};
