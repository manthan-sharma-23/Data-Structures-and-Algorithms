/*
 Given a string ‘s’; please find the longest subsequence which is of the form
 “a…..e…..i…..o…..u….” and output the length.

 example = "aaaeibbbouaaaeeiou"
 output -> 11 (aaaaaaeeiou)

*/
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int numberChar(char a) {
  switch (a) {
  case 'a':
    return 0;
  case 'e':
    return 1;
  case 'i':
    return 2;
  case 'o':
    return 3;
  case 'u':
    return 4;
  default:
    return -1;
  }
}

char charNumber(int a) {
  switch (a) {
  case 0:
    return 'a';
  case 1:
    return 'e';
  case 2:
    return 'i';
  case 3:
    return 'o';
  case 4:
    return 'u';
  default:
    return '#';
  }
}

int longestVowelledSubsequence(string &s) {
  int n = s.length();
  vector<vector<int>> dp(n + 1, vector<int>(5, INT_MIN));

  for (int i = 0; i < 5; i++)
    dp[0][i] = 0;

  // aaaeioubbaaeeiou
  for (int i = 1; i <= n; i++) {
    dp[i][0] = dp[i - 1][0] + (numberChar(s[i - 1]) == 0 ? 1 : 0);
  }

  for (int i = 1; i <= n; i++) {
    for (int l = 1; l <= 4; l++) {
      int add = (numberChar(s[i - 1]) == l) ? 1 : 0;
      if (add || (dp[i - 1][l] > 0))
        dp[i][l] = add + max(dp[i - 1][l - 1], dp[i - 1][l]);
    }
  }

  return dp[n][4];
}

int main() {

  string s;
  cin >> s;

  cout << longestVowelledSubsequence(s) << endl;
}