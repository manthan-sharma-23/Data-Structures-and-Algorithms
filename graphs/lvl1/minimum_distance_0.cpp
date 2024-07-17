#include <bits/stdc++.h>
#include <vector>

using namespace std;

class Solution {

public:
  vector<pair<int, int>> directions = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  int findZero(int row, int col, const vector<vector<int>> &mat, int &dist) {
    if (mat[row][col] == 0)
      return dist;

    int m = mat.size(), n = mat[0].size();

    for (auto dir : directions) {
      int nrow = row + dir.first;
      int ncol = col + dir.second;

      if (nrow >= 0 && ncol >= 0 && nrow < m && ncol < n) {
        dist++;
        findZero(nrow, ncol, mat, dist);
        dist--;
      }
    }

    return -1;
  }

  vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {}
};
