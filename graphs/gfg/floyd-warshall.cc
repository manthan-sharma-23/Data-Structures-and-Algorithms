#include <vector>

using namespace std;

class Solution {
public:
  void shortestDistance(vector<vector<int>> &mat) {
    int n = mat.size();
    int large = 100000;

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == -1)
          mat[i][j] = large;
      }
    }

    for (int via = 0; via < n; via++) {
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
          mat[i][j] = min(mat[i][j], mat[i][via] + mat[via][j]);
        }
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        if (mat[i][j] == large)
          mat[i][j] = -1;
      }
    }
  }
};