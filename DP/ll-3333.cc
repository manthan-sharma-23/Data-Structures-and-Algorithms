#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int possibleStringCount(string word, int k) {
    int n = word.length();
    const int MOD = 1e9 + 7;
    int x = k - 1;

    vector<vector<int>> dp(n + 1, vector<int>(x + 1, 0));

    vector<int> c;
    int totalWays = 1;

    {
      char prev;
      int count = 0;
      for (int i = 0; i < n; i++) {
        if (word[i] == prev)
          count++;
        else {
          if (count > 0) {
            c.push_back(count);
            totalWays *= count;
          }
          prev = word[i];
          count = 1;
        }
      }
      if (count > 0) {
        c.push_back(count);
        totalWays *= count;
      }
    }
  

    

}
};