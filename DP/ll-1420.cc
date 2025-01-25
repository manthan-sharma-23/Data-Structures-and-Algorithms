#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {

  int N, M, K;
  const int MOD = 1e9 + 7;
  int memo[51][101][100];
  int dfs(int size, int maxElement, int searchCost) {
    if (size == N) {
      if (searchCost == K)
        return 1;
      return 0;
    }
    if (memo[size][maxElement][searchCost] != -1)
      return memo[size][maxElement][searchCost];

    int result = 0;
    for (int i = 1; i <= M; i++) {
      int newSearch = i > maxElement ? searchCost + 1 : searchCost;
      if (newSearch <= K) {
        result += (dfs(size + 1, max(maxElement, i), newSearch) % MOD);
      }
    }

    return memo[size][maxElement][searchCost] = result % MOD;
  }

public:
  int numOfArrays(int n, int m, int k) {
    N = n, M = m, K = k;
    memset(memo, -1, sizeof(memo));
    return dfs(0, 0, 0);
  }
};