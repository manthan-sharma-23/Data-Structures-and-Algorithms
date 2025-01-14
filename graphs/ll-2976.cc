#include <climits>
#include <cstring>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  long long minimumCost(string source, string target, vector<char> &original,
                        vector<char> &changed, vector<int> &cost) {
    typedef long long ll;
    int n = original.size();
    ll grid[26][26];
    memset(grid, 1e4, sizeof(grid));

    if (source.size() != target.size())
      return -1;

    for (int i = 0; i < n; i++) {

      int from = original[i] - 'a';
      int to = changed[i] - 'a';
      ll c = cost[i];

      grid[from][to] = min(grid[from][to], c);
    }

    for (int i = 0; i < 26; i++)
      grid[i][i] = 0;

    for (int via = 0; via < 26; via++) {
      for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
          grid[i][j] = min(grid[i][j], grid[i][via] + grid[via][j]);
        }
      }
    }
    ll total = 0;
    for (int i = 0; i < source.size(); i++) {
      int s = source[i] - 'a';
      int t = target[i] - 'a';

      if (grid[s][t] >= 1e4) {
        return -1;
      } else {
        total += grid[s][t];
      }
    }

    return total;
  }
};