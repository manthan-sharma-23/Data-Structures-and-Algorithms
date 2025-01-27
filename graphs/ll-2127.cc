#include <vector>

using namespace std;

class Solution {
public:
  int maximumInvitations(vector<int> &favorite) {
    int n = favorite.size();

    vector<vector<int>> adj(n);

    for (auto i = 0; i < n; i++)
      adj[favorite[i]].push_back(i);
  }
};