#include <functional>
#include <vector>

using namespace std;

class Solution {
public:
  typedef long long ll;
  vector<vector<ll>> PT;
  ll N;
  const int MOD = 1e9 + 7;

  void buildPascalsTriangle() {
    for (int i = 0; i <= N; i++) {
      PT[i][0] = 1, PT[i][i] = 1;
    }

    for (int i = 2; i <= N; ++i) {
      for (int j = 1; j < i; ++j) {
        PT[i][j] = (PT[i - 1][j - 1] + PT[i - 1][j]) % MOD;
      }
    }
  }

  int solve(vector<int> &nums) {
    int n = nums.size();

    if (n < 3)
      return 1;

    vector<int> leftarr, rightarr;
    int root = nums[0];

    for (int i = 1; i < n; i++) {
      if (nums[i] < root) {
        leftarr.push_back(nums[i]);
      } else {
        rightarr.push_back(nums[i]);
      }
    }

    ll x = solve(leftarr) % MOD;
    ll y = solve(rightarr) % MOD;

    int z = PT[n - 1][leftarr.size()] % MOD;

    return (x * y * z) % MOD;
  }

  int numOfWays(vector<int> &nums) {
    int n = nums.size();
    this->N = n, this->PT.resize(n + 1, vector<ll>(n + 1, 0));
    this->buildPascalsTriangle();

    return (solve(nums) - 1) % MOD;
  }
};