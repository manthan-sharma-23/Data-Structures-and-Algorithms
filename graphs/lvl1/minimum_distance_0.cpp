#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {

private:
  vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  int findNearestZero(int row, int col, const vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> visited(m, vector<int>(n, 0));

    if (mat[row][col] == 0) {
      return 0;
    }
    int min_d = INT_MAX;

    queue<pair<pair<int, int>, int>> q;
    q.push({{row, col}, 0});

    while (!q.empty()) {
      int row = q.front().first.first;
      int col = q.front().first.second;
      int dis = q.front().second;

      if (mat[row][col] == 0) {
        min_d = min(min_d, dis);
      }

      q.pop();

      for (auto dir : directions) {
        int nrow = row + dir.first;
        int ncol = col + dir.second;

        if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n) {
          if (visited[nrow][ncol] == 0) {
            visited[nrow][ncol] = 1;
            q.push({{nrow, ncol}, dis + 1});
          }
        }
      }
    }

    return min_d < m * n ? min_d : -1;
  }

public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> distance(m, vector<int>(n, -1));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        int el = findNearestZero(i, j, mat);
        distance[i][j] = el;
      }
    }

    return distance;
  }
};
