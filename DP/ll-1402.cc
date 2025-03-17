#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int n;
  vector<vector<int>> memo;

  int f(vector<int> &satisfaction, int i, int time) {
    if (i >= n)
      return 0;

    if (memo[i][time] != -1e4) {
      return memo[i][time];
    }

    int pick = (time * satisfaction[i]) + f(satisfaction, i + 1, time + 1);
    int notPick = f(satisfaction, i + 1, time);

    return memo[i][time] = max(pick, notPick);
  }

  int maxSatisfaction(vector<int> &satisfaction) {
    n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());

    memo.resize(n + 1, vector<int>(n + 1, -1e4));

    return max(f(satisfaction, 0, 1), 0);
  }
};