#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> memo;
  int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

  int f(int mask, int opr, const vector<int> &nums) {
    if (opr == 0)
      return 0;

    if (memo[mask][opr] != -1)
      return memo[mask][opr];
    int f1 = -1, f2 = -1;

    int s = 0;

    for (int i = 0; i < nums.size(); i++) {
      if (mask & (1 << i))
        continue;
      for (int j = 0; j < nums.size(); j++) {
        if (i == j)
          continue;

        if (mask & (1 << j))
          continue;

        int newMask = mask;
        newMask |= (1 << i);
        newMask |= (1 << j);

        s = max(s, opr * gcd(nums[i], nums[j]) + f(newMask, opr - 1, nums));
      }
    }

    return memo[mask][opr] = s;
  }

  int maxScore(vector<int> &nums) {
    int n = nums.size();

    memo.resize((1 << n), vector<int>(n / 2 + 1, -1));

    return f(0, n / 2, nums);
  }
};