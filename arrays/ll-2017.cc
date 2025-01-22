#include <functional>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  long long gridGame(vector<vector<int>> &grid) {
    int n = grid[0].size();

    vector<int> rowSum(2, 0);

    vector<int> colSum(n, 0);

    function<bool(int, int)> isValid = [&](int r, int c) {
      return r >= 0 && c >= 0 && r < 2 && c < n;
    };

    for (int i = 0; i < n; i++) {
      colSum[i] = grid[i][0] + grid[i][1];
    }
    rowSum[1] = accumulate(grid[1].begin(), grid[1].end(), 0);
    rowSum[0] = accumulate(grid[0].begin(), grid[0].end(), 0);

    int row = 0, col = 0;

    while (row != 1 && col != (n - 1)) {
      int rnc = col + 1;
      int rwt = 0;
      if (isValid(row, rnc)) {
        rwt = colSum[rnc] * rowSum[row];
      }

      int rnr = row + 1;
      int dwt = 0;
      if (isValid(row, rnr)) {
        dwt = colSum[col] * rowSum[rnr];
      }
      rowSum[row] -= grid[row][col];
      colSum[col] -= grid[row][col];
      grid[row][col] = 0;

      if (dwt > rwt) {
        row++;
      } else {
        col++;
      }
    }

    rowSum[row] -= grid[row][col];
    colSum[col] -= grid[row][col];
    grid[row][col] = 0;
  }
};