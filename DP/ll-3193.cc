#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
class Solution {
private:
  int n, allVisitedMask;
  const int MOD = 1e9 + 7;
  unordered_map<int, int> queries;
  unordered_map<string, int> memo;

  string Key(int mask, int i, int prev) {
    return to_string(mask) + "_" + to_string(i) + "_" + to_string(prev);
  }

  bool canTake(int mask, int i) { return !(mask & (1 << i)); }

  int createNewMask(int mask, int i) {
    int temp = mask;
    temp = temp | (1 << i);
    return temp;
  }

  int countInversions(int mask, int i) {
    int count = 0;
    for (int b = i + 1; b < n; b++) {
      if (mask & (1 << b))
        count++;
    }

    return count;
  }

  int f(int mask, int index, int prevInversions) {
    if (index == n) {
      return 1;
    }

    auto key = Key(mask, index, prevInversions);

    if (memo.find(key) != memo.end())
      return memo[key];

    int inversionsNeeded = -1;
    if (queries.find(index) != queries.end()) {
      inversionsNeeded = queries[index];
    }

    int answer = 0;

    for (int el = 0; el < n; el++) {
      if (!canTake(mask, el))
        continue;

      int newMask = createNewMask(mask, el);
      int newInversions = countInversions(mask, el) + prevInversions;

      if (newInversions > 400)
        continue;

      if (inversionsNeeded != -1) {
        if (newInversions == inversionsNeeded) {
          answer += f(newMask, index + 1, newInversions);
          answer %= MOD;
        }
      } else {
        answer += f(newMask, index + 1, newInversions);
        answer %= MOD;
      }
    }

    return memo[key] = answer % MOD;
  }

public:
  int numberOfPermutations(int n, vector<vector<int>> &requirements) {
    this->n = n;
    this->allVisitedMask = (1 << n) - 1;

    for (const auto &requirement : requirements) {
      int r1 = requirement[0], r2 = requirement[1];
      if (r1 == 0 && r2 == 0)
        continue;
      queries[r1] = r2;
    }

    return f(0, 0, 0);
  }
};
