#include <algorithm>
#include <climits>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
  int maximumLength(vector<int> &nums, int maxDiff) {
    int n = nums.size();

    map<pair<int, int>, int> memo;

    int maxT = 0;

    vector<int> prevK(n + 1, 0);

    for (int i = 1; i <= n; i++) {
      memo[{nums[i - 1], 0}] = max(1, 1 + memo[{nums[i - 1], 0}]);
      prevK[i] = max(prevK[i - 1], memo[{nums[i - 1], 0}]);
      maxT = max(maxT, memo[{nums[i - 1], 0}]);
    }
    for (int k = 1; k <= maxDiff; k++) {
      vector<int> newK(n + 1, 0);

      for (int i = 1; i <= n; i++) {
        int t = max(1 + prevK[i - 1], 1 + memo[{nums[i - 1], k}]);
        newK[i] = max(newK[i - 1], t);
        memo[{nums[i - 1], k}] = t;
        maxT = max(maxT, t);
      }

      prevK = newK;
    }

    return maxT;
  }
};