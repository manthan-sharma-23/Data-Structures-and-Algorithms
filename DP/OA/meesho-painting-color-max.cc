//  link -> https://www.desiqna.in/16229/meesho-oa-sde-intern-ctc-25l-jan-2024

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int minBottlesLeft(vector<int> &nums) {
  int n = nums.size();

  vector<int> dp(n + 1, 0);

  dp[0] = 0;

  for (int i = 1; i <= n; i++) {
    for (int cut = i - 1; cut >= 0; cut--) {
      int len = i - cut;
      if (len > 1 && nums[cut] == nums[i - 1]) {
        dp[i] = max(dp[cut] + len, dp[i]);
      }
    }
  }

  return n - dp[n];
}

int minBottlesLest(vector<int> &nums) {
  int n = nums.size();
  unordered_map<int, int> mp;

  for (int i = 0; i < n; i++) {
    

}
}

int main() {
  int n;
  cin >> n;

  vector<int> nums(n);

  for (int i = 0; i < n; i++)
    cin >> nums[i];

  cout << minBottlesLeft(nums) << endl;
}