#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

class TopDownSolution {
  long long great = 1e6;

public:
  int minimumStepsToReduceToOne(int n, int steps, vector<int> &memo) {
    if (n == 1) {
      return steps;
    }
    int q1 = great, q2 = great, q3 = great;

    if (memo[n] != -1)
      return memo[n];

    if (n % 3 == 0) {
      q1 = minimumStepsToReduceToOne(n / 3, steps + 1, memo);
    }
    if (n % 2 == 0) {
      q2 = minimumStepsToReduceToOne(n / 2, steps + 1, memo);
    }
    q3 = minimumStepsToReduceToOne(n - 1, steps + 1, memo);

    auto minimum = min(min(q1, q2), q3);
    memo[n] = minimum;

    return minimum;
  }
};

class BottomUpSolution {
public:
  int minimumStepsToReduceToOne(int n) {
    vector<int> dp(n + 1, 0);

    for (int i = 2; i <= n; i++) {
      int q1 = dp[i - 1];
      int q2 = (i % 3 == 0) ? dp[i / 3] : 1e4;
      int q3 = (i % 2 == 0) ? dp[i / 2] : 1e4;

      dp[i] = min({q1, q2, q3}) + 1;
    }

    return dp[n];
  }
};

int main() {
  int n =100;
  TopDownSolution os1;
  BottomUpSolution os2;
  vector<int> dp(n + 1, -1);
  dp[0] = 0;

  const auto step = os1.minimumStepsToReduceToOne(n, 0, dp);
  const auto steps = os2.minimumStepsToReduceToOne(n);

  cout << steps << endl;

  return 0;
}
