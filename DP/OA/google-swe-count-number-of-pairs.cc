//  link- >
//  https://docs.google.com/document/d/1l4TgrtK10ei8wKauu0gOdeXD99M1saP_9wuq0ZcMLWo/edit?tab=t.0

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Palindromic {
  vector<vector<int>> count;
  int n;
  string s;

  int numOfPairs(string &s, int start) {

    int pairs = 0;
    int n = s.length();

    for (int i = start; i < n - 1; i++) {
      int left = 0;
      int right = query(i + 1, n - 1);

      for (int it = i; it >= start; it--) {
        left += query(it, i);
      }
    }

    return pairs;
  }

public:
  Palindromic(string s) {
    n = s.length();
    this->s = s;

    count.assign(n, vector<int>(n, 0));

    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int len = 1; len <= n; len++) {
      for (int i = 0; i + len - 1 < n; i++) {
        int j = i + len - 1;

        if (len == 1) {
          dp[i][j] = 1;
        } else if (len == 2) {
          dp[i][j] = (s[i] == s[j]);
        } else {
          dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
        }

        count[i][j] =
            dp[i][j] +
            (i < j ? dp[i][j - 1] + dp[i + 1][j] - dp[i + 1][j - 1] : 0);
      }
    }
  }

  int query(int i, int j) { return count[i][j]; }

  int numOfTriplets() {
    int n = s.length();
    vector<int> countPairs(n + 1, 0);

    int count = 0;
    for (int i = 0; i < n - 1; i++) {
      countPairs[i] = numOfPairs(s, i);
    }

    for (int i = 0; i < n - 2; i++) {
      int left = 0;
      int right = countPairs[i + 1];

      for (int it = i; it >= 0; it--) {
        left += query(it, i);
      }

      count += left * right;
    }

    return count;
  }
};

int main() {
  Palindromic p("aabcdsdkljodhggh");

  cout << p.numOfTriplets() << endl;
}