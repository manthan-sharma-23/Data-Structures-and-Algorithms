#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
  int solve(int m, int n, vector<vector<int>> &grid) {
    int rows = m;
    int cols = n;

    // DP table: dp[i][j1][j2] represents the maximum chocolates collected
    // by Robot 1 at column j1 and Robot 2 at column j2 in row i
    vector<vector<vector<int>>> dp(
        rows, vector<vector<int>>(cols, vector<int>(cols, 0)));

    // Initialize the DP table for the last row
    for (int j1 = 0; j1 < cols; ++j1) {
      for (int j2 = 0; j2 < cols; ++j2) {
        if (j1 == j2) {
          dp[rows - 1][j1][j2] = grid[rows - 1][j1];
        } else {
          dp[rows - 1][j1][j2] = grid[rows - 1][j1] + grid[rows - 1][j2];
        }
      }
    }

    // Fill the DP table from the second last row to the top row
    for (int row = rows - 2; row >= 0; --row) {
      for (int j1 = 0; j1 < cols; ++j1) {
        for (int j2 = 0; j2 < cols; ++j2) {
          int maxChocolates = INT_MIN;

          // Try all possible moves for both robots
          for (int dj1 = -1; dj1 <= 1; ++dj1) {
            for (int dj2 = -1; dj2 <= 1; ++dj2) {
              int newJ1 = j1 + dj1;
              int newJ2 = j2 + dj2;

              // Check if the new positions are within bounds
              if (newJ1 >= 0 && newJ1 < cols && newJ2 >= 0 && newJ2 < cols) {
                int currentChocolates =
                    (j1 == j2) ? grid[row][j1] : grid[row][j1] + grid[row][j2];
                currentChocolates += dp[row + 1][newJ1][newJ2];
                maxChocolates = max(maxChocolates, currentChocolates);
              }
            }
          }

          dp[row][j1][j2] = maxChocolates;
        }
      }
    }

    // The answer is the maximum chocolates collected starting from (0, 0) and
    // (0, cols - 1)
    return dp[0][0][cols - 1];
  }
};
