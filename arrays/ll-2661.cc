#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
    int m = mat.size(), n = mat[0].size();
    unordered_map<int, pair<int, int>> grid;

    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        grid[mat[i][j]] = {i, j};
      }
    }

    vector<int> rowFreq(m, 0);
    vector<int> colFreq(n, 0);

    for (int i = 0; i < arr.size(); i++) {
      auto cell = arr[i];
      auto [x, y] = grid[cell];

      rowFreq[x]++;
      colFreq[y]++;

      if (rowFreq[x] == m || colFreq[y] == n)
        return i;
    }

    return -1;
  }
};