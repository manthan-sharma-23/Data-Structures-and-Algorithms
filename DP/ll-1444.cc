#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
  const int MOD = 1e9 + 7;
  vector<vector<vector<int>>> memo;

  bool contains_apple(vector<string> &pizza, int row1, int col1, int row2, int col2)
  {
    for (int i = row1; i <= row2; i++)
    {
      for (int j = col1; j <= col2; j++)
      {
        if (pizza[i][j] == 'A')
          return true;
      }
    }
    return false;
  }

  int dfs(vector<string> &pizza, int row, int col, int k)
  {
    if (k == 0)
      return contains_apple(pizza, row, col, pizza.size() - 1, pizza[0].length() - 1) ? 1 : 0;

    if (memo[row][col][k] != -1)
      return memo[row][col][k];

    int m = pizza.size();
    int n = pizza[0].length();
    int ans = 0;

    for (int i = row + 1; i < m; i++)
    {
      if (contains_apple(pizza, row, col, i - 1, n - 1))
      {
        ans = (ans + dfs(pizza, i, col, k - 1)) % MOD;
      }
    }

    for (int j = col + 1; j < n; j++)
    {
      if (contains_apple(pizza, row, col, m - 1, j - 1))
      {
        ans = (ans + dfs(pizza, row, j, k - 1)) % MOD;
      }
    }

    return memo[row][col][k] = ans;
  }

  int bottomUP(vector<string> &pizza, int k)
  {
    int m = pizza.size(), n = pizza[0].length();
    vector<vector<int>> apples(m + 1, vector<int>(n + 1, 0));

    for (int i = m - 1; i >= 0; i--)
    {
      for (int j = n - 1; j >= 0; j--)
      {
        apples[i][j] = (pizza[i][j] == 'A') + apples[i + 1][j] + apples[i][j + 1] - apples[i + 1][j + 1];
      }
    }

    vector<vector<vector<int>>> dp(k, vector<vector<int>>(m, vector<int>(n, 0)));

    for (int i = 0; i < m; i++)
    {
      for (int j = 0; j < n; j++)
      {
        if (apples[i][j] > 0)
          dp[0][i][j] = 1;
      }
    }
  }

  int ways(vector<string> &pizza, int k)
  {
    int m = pizza.size();
    int n = pizza[0].length();
    memo = vector<vector<vector<int>>>(m, vector<vector<int>>(n, vector<int>(k, -1)));
    return dfs(pizza, 0, 0, k - 1);
  }
};
