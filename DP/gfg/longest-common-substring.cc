#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPalindrome(int i, int j, string &s) {
    while (i < j) {
      if (s[i] != s[j])
        return false;
      i++;
      j--;
    }
    return true;
  }

  // Recursive function to find the minimum number of partitions to make
  // palindromes.
  int minPartitions(int i, int n, string &str) {
    // Base case: If we've reached the end of the string.
    if (i == n)
      return 0;

    int minCost = 1e9;
    // Consider all possible substrings starting from the current index.
    for (int j = i; j < n; j++) {
      if (isPalindrome(i, j, str)) {
        // If the substring is a palindrome, calculate the cost and minimize it.
        int cost = 1 + minPartitions(j + 1, n, str);
        minCost = min(minCost, cost);
      }
    }
    return minCost;
  }

  // Main function to find the minimum number of partitions for palindrome
  // partitioning.
  int palindromePartitioning(string str) {
    int n = str.size();
    // Calling the recursive function and subtracting 1 as it counts partitions,
    // not cuts.
    return minPartitions(0, n, str) - 1;
  }
};

class TopDownDP {
public:
  int longestCommonSubstr(string &s1, string &s2) {
    int n = s1.length(), m = s2.length();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    int maxLen = 0;

    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= m; j++) {
        if (s1[i - 1] == s2[j - 1]) {
          dp[i][j] = 1 + dp[i - 1][j - 1];
          maxLen = max(maxLen, dp[i][j]);
        } else {
          dp[i][j] = 0;
        }
      }
    }

    return maxLen;
  }
};
