#include <climits>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> countOfPairs(int n, int x, int y) {
    int grid[n][n];
    x--, y--;

    memset(grid, INT_MAX, sizeof(grid));

    for (int i = 0; i < n; i++) {
      grid[i][i] = 0;
    }

    for (int i = 0; i < n; i++) {
      grid[i][i + 1] = 1;
      grid[i + 1][i] = 1;
    }
    grid[x][y] = 1;
    grid[y][x] = 1;

    for (int via = 0; via < n; via++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
        }
      }
    }

    vector<int> ans(n);
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int dist = grid[i][j];
        if (dist <= n) {
          ans[dist - 1]++;
        }
      }
    }

    return ans;
  }
};