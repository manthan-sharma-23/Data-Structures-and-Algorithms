#include <climits>
#include <vector>

using namespace std;

class Solution {
public:
  int kInversePairs(int n, int k) {
    typedef long long ll;
    const int MOD = 1e9 + 7;
    vector<vector<ll>> dp(n + 1, vector<ll>(k + 1, 0));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }

    /**
     * we are trying to move the last element we are trying to place to create
     * inversion
     *
     * for eg
     *  1 2 3 , 0 inversion
     *  1 3 2 , 1 inversion when 3 is moved by 1
     *  3 1 2 , 1 inversion when 3 is moved by 2
     *
     *  max we can make (i-1) or k moves ;
     *
     *
     **/

    for (int i = 1; i <= n; i++)
      for (int j = 1; j <= k; j++)
        for (int move = 0; move <= min(j, i - 1); move++)
          dp[i][j] = (dp[i][j] + dp[i - 1][j - move]) % MOD;

    return dp[n][k];
  }
};