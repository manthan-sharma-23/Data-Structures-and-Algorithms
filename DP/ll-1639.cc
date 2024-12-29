#include <cstring>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  typedef long long int ll;
  ll memo[1001][1001];
  const int static MOD = 1e9 + 7;

  int n_columns;
  int n_words;
  int target_size;

  int f(vector<string> &words, string target, int size, int col) {
    if (memo[size][col] != -1) {
      return memo[size][col];
    }

    if (size == target_size) {
      return 1;
    }
    if (col >= n_columns || (target_size - size) > (n_columns - col)) {
      return 0;
    }

    int count = 0;

    for (int i = 0; i < n_words; i++) {
      if (target[size] == words[i][col]) {
        count += f(words, target, size + 1, col + 1);
        count %= MOD;
      }
    }
    count += f(words, target, size, col + 1);

    return memo[size][col] = (count % MOD);
  }

  int numWays(vector<string> &words, string target) {
    n_columns = words[0].length();
    n_words = words.size();
    target_size = target.length();
    memset(memo, -1, sizeof(memo));
    return f(words, target, 0, 0);
  }
};

class TopDownSolution {
public:
  typedef long long int ll;
  const int static MOD = 1e9 + 7;
  int numWays(vector<string> &words, string target) {
    int n_columns = words[0].length();
    int n_words = words.size();
    int target_size = target.length();

    ll freq[26][n_columns];
    memset(freq, 0, sizeof(freq));

    for (int row = 0; row < n_words; row++) {
      for (int col = 0; col < n_columns; col++) {
        freq[words[row][col] - 'a'][col]++;
      }
    }

    ll dp[target_size + 1][n_columns + 1];
    memset(dp, 0, sizeof(dp));
    for (int i = 0; i <= n_columns; i++)
      dp[0][i] = 1;

    for (int i = 1; i <= target_size; i++) {
      for (int j = 1; j <= n_columns; j++) {
        if (i > j)
          continue;

        dp[i][j] = dp[i][j - 1];

        int target_char = target[i - 1] - 'a';
        if (freq[target_char][j - 1] > 0)
          dp[i][j] =
              (dp[i][j - 1] + dp[i - 1][j - 1] * freq[target_char][j - 1]) %
              MOD;
      }
    }

    return dp[target_size][n_columns];
  }
};