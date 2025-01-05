#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
  int countPalindromes(string s) {
    int n = s.length();

    string a = s;

    string b = s;
    reverse(b.begin(), b.end());

    int dp[n + 1][n + 1];
    
  }
};