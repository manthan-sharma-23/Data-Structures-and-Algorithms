#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int cherryPickup(vector<vector<int>> &grid) {
    int n = grid.size();

    vector<vector<vector<int>>> memo(
        n, vector<vector<int>>(n, vector<int>(n, -1)));

    int result = f(grid, memo, 0, 0, 0, n);

    return max(0, result);
  }

private:
  int f(const vector<vector<int>> &grid, vector<vector<vector<int>>> &memo,
        int r1, int c1, int c2, const int n) {

    int r2 = r1 + c1 - c2;

    if (r1 >= n || r2 >= n || c1 >= n || c2 >= n || grid[r1][c1] == -1 ||
        grid[r2][c2] == -1) {
      return INT_MIN;
    }
    if (r1 == n - 1 && c1 == n - 1) {
      return grid[r1][c1];
    }

    if (memo[r1][c1][c2] != -1) {
      return memo[r1][c1][c2];
    }
    int cherry = 0;
    if (r1 == r2 && c1 == c2) {
      cherry += grid[r1][c1];
    } else {
      cherry += grid[r1][c1] + grid[r2][c2];
    }

    int f1 = f(grid, memo, r1 + 1, c1, c2, n);
    int f2 = f(grid, memo, r1, c1 + 1, c2 + 1, n);
    int f3 = f(grid, memo, r1 + 1, c1, c2 + 1, n);
    int f4 = f(grid, memo, r1, c1 + 1, c2, n);

    int maxCherry = max({f1, f2, f3, f4});

    if (maxCherry == INT_MIN) {
      return memo[r1][c1][c2] = INT_MIN;
    }

    return memo[r1][c1][c2] = cherry + maxCherry;
  }
};