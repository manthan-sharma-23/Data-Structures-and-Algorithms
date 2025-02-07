#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int n;
  unordered_map<string, int> memo;

  bool solve(vector<int> &stones, int index, int lastJump) {
    string key = to_string(index) + "_" + to_string(lastJump);

    if (index == n - 1)
      return true;

    if (memo.find(key) != memo.end()) {
      return memo[key];
    }

    for (int stone = index + 1; stone < n; stone++) {
      int nextJump = stones[stone] - stones[index];
      if ((nextJump == lastJump || nextJump == lastJump - 1 ||
           nextJump == lastJump + 1) &&
          solve(stones, stone, nextJump)) {
        return memo[key] = true;
      }
    }

    return memo[key] = false;
  }

  bool canCross(vector<int> &stones) {
    n = stones.size();
    memo.clear();

    return solve(stones, 0, 0);
  }
};

class TopDown {
public:
  bool canCross(vector<int> &stones) {
    int n = stones.size();
    int maxJump = stones[n - 1] - stones[0];

    vector<vector<bool>> dp(n + 1, vector<bool>(maxJump + 1, false));
  }
};