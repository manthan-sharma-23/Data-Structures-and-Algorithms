#include <algorithm>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int lenLongestFibSubseq(vector<int> &arr) {
    int n = arr.size();

    unordered_map<int, int> mp;

    vector<int> dp(n, 0);

    for (int i = 0; i < n; i++) {
      int mainNumber = arr[i];
      for (int j = i - 1; j >= 0; j--) {
        int last = arr[j];
        int secondLast = mainNumber - last;
        int len = 0;
        if (mp.find(secondLast) != mp.end()) {
          len = mp[secondLast] + 2;
        }
        dp[i] = max(dp[i], len);
      }

      mp[mainNumber] = dp[i];
    }

    return *max_element(dp.begin(), dp.end());
  }
}; 