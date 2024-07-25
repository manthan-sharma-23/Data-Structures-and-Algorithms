#include <algorithm>
#include <bits/stdc++.h>
#include <climits>

using namespace std;

class Solution {
public:
  void shortest_distance(vector<vector<int>> &matrix) {
    int n = matrix.size();

    // Initialize the matrix: replace -1 with INT_MAX for initial distance setup
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == -1) {
          matrix[i][j] = INT_MAX;
        }
        if (i == j) {
          matrix[i][j] = 0;
        }
      }
    }

    // Floyd-Warshall algorithm to find the shortest paths
    for (int via = 0; via < n; via++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          if (matrix[i][via] != INT_MAX && matrix[via][j] != INT_MAX) {
            matrix[i][j] = min(matrix[i][j], matrix[i][via] + matrix[via][j]);
          }
        }
      }
    }

    // Convert INT_MAX back to -1 to indicate no path
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (matrix[i][j] == INT_MAX) {
          matrix[i][j] = -1;
        }
      }
    }
  }
};
