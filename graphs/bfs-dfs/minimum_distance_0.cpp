#include <bits/stdc++.h>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

class Solution {
private:
  vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  void findNearest(vector<vector<int>> &distance,
                   const vector<vector<int>> &matrix, int m, int n) {
    vector<vector<int>> visited(m, vector<int>(n, 0));

    queue<pair<pair<int, int>, int>> q;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == 0) {
          visited[i][j] = 1;
          q.push({{i, j}, 0});
        } else {
          visited[i][j] = 0;
        }
      }
    }

    while (!q.empty()) {
      int row = q.front().first.first;
      int col = q.front().first.second;
      int dist = q.front().second;

      q.pop();

      distance[row][col] = dist;

      for (auto dir : directions) {
        int nrow = row + dir.first;
        int ncol = col + dir.second;

        if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n &&
            visited[nrow][ncol] == 0) {
          visited[nrow][ncol] = 1;
          q.push({{nrow, ncol}, dist + 1});
        }
      }
    }
  }

public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    vector<vector<int>> distance(m, vector<int>(n, 0));

    findNearest(distance, mat, m, n);

    return distance;
  }
};

class Solution2 {
public:
  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
    queue<pair<int, int>> q;
    int m = mat.size();
    int n = mat[0].size();

    vector<vector<int>> visited(m, vector<int>(n, 0));

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        if (!mat[i][j]) {
          q.push({i, j});
          visited[i][j] = 1;
        }
      }
    }

    int dis = 1;

    int row[] = {-1, 0, 1, 0};
    int col[] = {0, 1, 0, -1};
    while (!q.empty()) {
      int size = q.size();
      for (int i = 1; i <= size; i++) {
        auto top = q.front();
        int prevrow = top.first;
        int prevcol = top.second;
        q.pop();
        for (int j = 0; j < 4; j++) {
          int newrow = prevrow + row[j];
          int newcol = prevcol + col[j];

          if (newrow >= 0 && newrow < m && newcol >= 0 && newcol < n &&
              !visited[newrow][newcol]) {
            q.push({newrow, newcol});
            mat[newrow][newcol] = dis;
            visited[newrow][newcol] = 1;
          }
        }
      }
      dis++;
    }
    return mat;
  }
};

void print(vector<vector<int>> v) {
  for (auto it : v) {
    for (auto i : it) {
      cout << i << " ";
    }
    cout << endl;
  }
}

int main() {
  vector<vector<int>> grid{{0, 1, 1, 0}, {1, 1, 0, 0}, {0, 0, 1, 41}};
  Solution obj;
  vector<vector<int>> ans = obj.updateMatrix(grid);

  print(ans);
  return 0;
}
