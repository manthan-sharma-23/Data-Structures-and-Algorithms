#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int maxSumTwoNoOverlap(vector<int> &nums, int firstLen, int secondLen) {

    int n = nums.size();

    vector<vector<int>> dp(n + 1, vector<int>(2, INT_MIN));

    vector<int> pref(n + 1, 0);

    for (int i = 1; i <= n; i++)
      pref[i] = pref[i - 1] + nums[i - 1];

    //  for 1;
    for (int j = firstLen; j <= n; j++) {
      int i = j - firstLen - 1;
      dp[i][1] = max(pref[j] - pref[i], dp[i - 1][1]);
    }

    for (int i = (firstLen + secondLen); i <= n; i++) {

      for (int cut = i - 1; cut >= firstLen; cut--) {
        /* code */
      }
    }
  }
};