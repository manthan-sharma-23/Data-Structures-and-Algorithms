#include <climits>
#include <string>

using namespace std;

class Solution {
public:
  int solve(string &src, string &dest, int i, int j, int ways) {
    if (i == src.length() || j == dest.length()) {
      if (src == dest) {
        return ways;
      }

      return INT_MAX;
    }

    solve(src, dest, i, j, ways);
  }

  int minDistance(string word1, string word2) {
    int n1 = word1.length();
    int n2 = word2.length();
  }
};