#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> sortMatrix(vector<vector<int>> &grid) {

    int n = grid.size();

    vector<vector<int>> diagonals;

    for (int i = n - 1; i >= 0; i--) {
      vector<int> diagonal;
      int r = i, c = 0;
      while (r >= 0 && c >= 0 && r < n && c < n) {
        diagonal.push_back(grid[r][c]);
        r++, c++;
      }
      sort(diagonal.begin(), diagonal.end(),
           [](int a, int b) { return a > b; });
      diagonals.push_back(diagonal);

      r = i, c = 0;
      for (int val : diagonal) {
        grid[r][c] = val;
        r++, c++;
      }
    }

    for (int i = 1; i < n; i++) {
      vector<int> diagonal;
      int r = 0, c = i;
      while (r >= 0 && c > 0 && r < n && c < n) {
        diagonal.push_back(grid[r][c]);
        r++, c++;
      }
      sort(diagonal.begin(), diagonal.end());
      diagonals.push_back(diagonal);

      r = 0, c = i;
      for (int val : diagonal) {
        grid[r][c] = val;
        r++, c++;
      }
    }

    return grid;
  }
};