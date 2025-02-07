#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> queryResults(int limit, vector<vector<int>> &queries) {
    unordered_map<int, int> freq;
    unordered_map<int, int> colors;

    vector<int> res(queries.size(), 0);

    for (int i = 0; i < queries.size(); i++) {
      auto query = queries[i];

      int ball = query[0], color = query[1];

      if (colors[ball] != 0) {
        int prev = colors[ball];
        freq[prev]--;
        if (freq[prev] == 0)
          freq.erase(prev);
      }

      colors[ball] = color;
      freq[color]++;

      res[i] = freq.size();
    }

    return res;
  }
};