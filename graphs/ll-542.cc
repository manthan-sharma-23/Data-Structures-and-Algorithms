#include <queue>
#include <vector>

using namespace std;
class Solution {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    if (m == 0)
      return {};

    const vector<pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    vector<vector<int>> matrix(m, vector<int>(n, -1));
    queue<pair<int, int>> q;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == 0) {
          matrix[i][j] = 0;
          q.push({i, j});
        }
      }
    }

    while (!q.empty()) {
      auto [x, y] = q.front();
      q.pop();

      for (auto [dx, dy] : directions) {
        int nx = x + dx;
        int ny = y + dy;

        if (nx >= 0 && nx < m && ny >= 0 && ny < n && matrix[nx][ny] == -1) {
          matrix[nx][ny] = matrix[x][y] + 1;
          q.push({nx, ny});
        }
      }
    }

    return matrix;
  }
};