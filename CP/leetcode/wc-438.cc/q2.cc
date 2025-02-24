
#include <algorithm>
#include <vector>

using namespace std;
class Solution {
public:
  long long maxSum(vector<vector<int>> &grid, vector<int> &limits, int k) {

    vector<int> z;
    int m = grid.size();

    for (int i = 0; i < m; ++i) {
      int col = grid[i].size();

      sort(grid[i].rbegin(), grid[i].rend());

      int limit = min(col, limits[i]);
      z.insert(z.end(), grid[i].begin(), grid[i].begin() + limit);
    }

    long long res = 0;
    int n = z.size();
    for (int i = 0; i < min(k, n); i++) {
      res += z[i];
    }

    return res;
  }
};