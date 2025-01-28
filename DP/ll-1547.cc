#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>
using namespace std;

class Solution {
public:
  int N;

  int f(vector<int> &cuts, int i, int j) {
    if (i >= j)
      return 0;
    int minCost = INT_MAX;

    for (int k = i; k < j; k++) {
      int cost = (cuts[j] - cuts[i - 1]) + f(cuts, i, k) + f(cuts, k + 1, j);
      minCost = min(minCost, cost);
    }

    return minCost;
  }

  int minCost(int n, vector<int> &cuts) {
    cuts.insert(cuts.begin(), 0);
    cuts.push_back(n);

    int N = cuts.size();

    return f(cuts, 1, N - 1);
  }
};