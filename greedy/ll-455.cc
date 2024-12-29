#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
  int findContentChildren(vector<int> &g, vector<int> &s) {
    int n_cookie = s.size();
    int n_child = g.size();

    sort(g.begin(), g.end());
    sort(s.begin(), s.end());

    int cook = 0, child = 0;
    while (cook < n_cookie && child < n_child) {
      if (s[cook] >= g[child]) {
        child++;
      }
      cook++;
    }

    return child;
  }
};