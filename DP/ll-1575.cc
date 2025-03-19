#include <cstdlib>
#include <vector>

using namespace std;

class Solution {
public:
  const int MOD = 1e9 + 7;
  int countRoutes(vector<int> &locations, int start, int finish, int fuel) {
    int n = locations.size();

    vector<vector<int>> dp(n, vector<int>(fuel + 1, 0));

    for (int f = 0; f <= fuel; f++)
      dp[finish][f] = 1;

    for (int s = 0; s < n; s++) {
      for (int f = 0; f <= fuel; f++) {

        for (int i = 0; i < n; i++) {
          int cost = abs(locations[i] - locations[s]);
          if (i != s && cost <= f) {
            dp[s][f] = (dp[s][f] + dp[i][f - cost]) % MOD;
          }
        }
      }
    }

    return dp[start][fuel];
  }
};