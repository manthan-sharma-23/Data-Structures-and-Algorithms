#include <functional>
#include <queue>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int minFlips(vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    const vector<pair<int, int>> directions = {
        {0, 0}, {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    auto matrixToBitmask = [&]() {
      int mask = 0;
      for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
          if (mat[i][j]) {
            mask |= (1 << (i * n + j));
          }
        }
      }
      return mask;
    };

    auto flip = [&](int mask, int r, int c) {
      for (auto &[dr, dc] : directions) {
        int nr = r + dr, nc = c + dc;
        if (nr >= 0 && nr < m && nc >= 0 && nc < n) {
          mask ^= (1 << (nr * n + nc));
        }
      }
      return mask;
    };

    int start = matrixToBitmask();
    if (start == 0)
      return 0;

    unordered_set<int> visited;
    queue<int> q;
    q.push(start);
    visited.insert(start);

    int steps = 0;

    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        int curr = q.front();
        q.pop();

        for (int i = 0; i < m; ++i) {
          for (int j = 0; j < n; ++j) {
            int next = flip(curr, i, j);
            if (next == 0)
              return steps + 1;
            if (visited.count(next) == 0) {
              visited.insert(next);
              q.push(next);
            }
          }
        }
      }
      ++steps;
    }

    return -1;
  }
};
