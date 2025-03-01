#include <vector>

using namespace std;

class Solution {
public:
  int countArrays(vector<int> &original, vector<vector<int>> &bounds) {
    int n = original.size();
    vector<int> diff(n);

    for (int i = 0; i < n; i++) {
      diff[i] = original[i] - original[0];
    }

    int minVal = bounds[0][0] - diff[0];
    int maxVal = bounds[0][1] - diff[0];

    for (int i = 1; i < n; i++) {
      minVal = max(minVal, bounds[i][0] - diff[i]);
      maxVal = min(maxVal, bounds[i][1] - diff[i]);

      if (minVal > maxVal)
        return 0;
    }

    return max(0, maxVal - minVal + 1);
  }
};
