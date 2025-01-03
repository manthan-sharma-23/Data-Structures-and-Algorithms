
#include <cstring>
#include <vector>

using namespace std;

vector<pair<int, int>> directions = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int water = -1, land = 1;

void dfs(vector<vector<int>> &globe, vector<vector<bool>> &visited, int x,
         int y) {
  int n = globe.size(), m = globe[0].size();
  visited[x][y] = true;

  for (auto &[dx, dy] : directions) {
    int nx = x + dx;
    int ny = y + dy;

    if (nx >= 0 && nx < n && ny >= 0 && ny < m && globe[nx][ny] == land &&
        !visited[nx][ny]) {
      dfs(globe, visited, nx, ny);
    }
  }
}

vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q) {
  int n_queries = q.size();

  vector<vector<int>> globe(n, vector<int>(m, water));
  vector<vector<bool>> visited(n, vector<bool>(m, 0));
  vector<int> res;

  int islands = 0;
  for (auto &query : q) {
    int X = query[0];
    int Y = query[1];

    if (globe[X][Y] == land) {
      res.push_back(islands);
      continue;
    }

    globe[X][Y] = land;
    islands = 0;

    visited.assign(n, vector<bool>(m, false));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        if (!visited[i][j] && globe[i][j] == land) {
          islands++;
          dfs(globe, visited, i, j);
        }
      }
    }

    res.push_back(islands);
  }

  return res;
}