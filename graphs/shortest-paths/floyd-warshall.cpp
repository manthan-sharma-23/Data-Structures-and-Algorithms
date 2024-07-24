#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution {
public:
  void shortest_distance(vector<vector<int>> &matrix) {

    int n = matrix.size();

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.size(); j++) {
        if (matrix[i][j] == -1) {
          matrix[i][j] = INT_MAX;
        }
        if (i == j)
          matrix[i][j] = 0;
      }
    }

    for (int via = 0; via < matrix.size(); via++) {
      for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
          matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++)
        if (matrix[i][j] < 0) {
          // return {-1};
        }
    }

    for (int i = 0; i < matrix.size(); i++) {
      for (int j = 0; j < matrix.size(); j++) {
        if (matrix[i][j] == INT_MAX) {
          matrix[i][j] = -1;
        }
      }
    }
  }
};
