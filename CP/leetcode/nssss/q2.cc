#include <algorithm>
#include <set>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> assignElements(vector<int> &g, vector<int> &e) {
    int m = *max_element(g.begin(), g.end()) + 1;
    vector<vector<int>> pos(m);
    for (int i = 0; i < (int)g.size(); ++i) {
      pos[g[i]].push_back(i);
    }
    vector<int> a(g.size(), -1);
    set<int> visited;
    for (int i = 0; i < (int)e.size(); ++i) {
      if (visited.find(e[i]) != visited.end())
        continue;
      visited.insert(e[i]);
      for (int j = e[i]; j < m; j += e[i])
        if (!pos[j].empty()) {
          for (auto &k : pos[j]) {
            a[k] = i;
          }
          pos[j].clear();
        }
    }

    return a;
  }
};