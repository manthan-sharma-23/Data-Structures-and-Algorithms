#include <climits>
#include <cmath>
#include <cstring>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int numberOfSets(int n, int maxDistance, vector<vector<int>> &roads) {
    int ans = 0;

    for (int set = 0; set < pow(2, n); set++) {
      int grid[n][n];
      memset(grid, 1e9, sizeof(grid));

      for (auto &road : roads) {
        int u = road[0];
        int v = road[1];
        int wt = road[2];

        if ((set >> u & 1) && (set >> v & 1)) {
          grid[u][v] = min(grid[u][v], wt);
          grid[v][u] = min(grid[v][u], wt);
        }
      }

      for (int i = 0; i < n; i++)
        grid[i][i] = 0;

      for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
          for (int j = 0; j < n; j++) {
            grid[i][j] = min(grid[i][j], grid[i][k] + grid[k][j]);
          }
        }
      }

      bool ok = true;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (i == j)
            continue;

          if ((set >> i & 1) && (set >> j & 1)) {
            if (grid[i][j] > maxDistance) {
              ok = false;
              break;
            }
          }
        }
      }

      if (ok) {
        ans++;
      }
    }

    return ans;
  }
};