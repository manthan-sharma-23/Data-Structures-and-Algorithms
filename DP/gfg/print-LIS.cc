#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> longestIncreasingSubsequence(int n, vector<int> &arr) {
    vector<int> dp(n, 0);

    vector<int> hash(n, 0);
    for (int i = 0; i < n; i++)
      hash[i] = i;

    int maxIndx = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (arr[j] < arr[i] && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          hash[i] = j;
        }
      }

      if (dp[i] > dp[maxIndx]) {
        maxIndx = i;
      }
    }

    vector<int> res;
    int current = maxIndx;
    while (hash[current] != current) {
      res.push_back(arr[current]);
      current = hash[current];
    }
    res.push_back(arr[current]);
    reverse(res.begin(), res.end());

    return res;
  }
};
