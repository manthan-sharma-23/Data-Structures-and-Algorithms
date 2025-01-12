#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  int maximalNetworkRank(int n, vector<vector<int>> &roads) {
    vector<int> inDegree(n, 0);
    bool is_same_road[n][n];

    memset(is_same_road, false, sizeof(is_same_road));

    for (const auto &road : roads) {
      inDegree[road[0]]++;
      inDegree[road[1]]++;
      is_same_road[road[0]][road[1]] = true;
      is_same_road[road[1]][road[0]] = true;
    }

    int max_ = 0;

    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {

        int tsum = inDegree[i] + inDegree[j] - is_same_road[i][j];
        max_ = max(max_, tsum);
      }
    }

    return max_;
  }
};