#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
#include <cmath>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
  typedef long long ll;

public:
  void DFS(int u, unordered_set<int> &visited, vector<vector<int>> adj) {
    visited.insert(u);

    for (auto &bomb : adj[u]) {
      if (visited.find(bomb) == visited.end()) {
        DFS(bomb, visited, adj);
      }
    }
  }

  int maximumDetonation(vector<vector<int>> &bombs) {
    int n = bombs.size();
    vector<vector<int>> adj(n);

    for (int i = 0; i < bombs.size(); i++) {

      ll x1, y1, r1;
      x1 = bombs[i][0];
      y1 = bombs[i][1];
      r1 = bombs[i][2];

      for (int j = 0; j < bombs.size(); j++) {
        ll x2, y2, r2;
        x2 = bombs[j][0];
        y2 = bombs[j][1];
        r2 = bombs[j][2];

        if (i != j) {
          ll distance = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));

          if (distance <= ll(r1)) {
            adj[i].push_back(j);
          }
        }
      }
    }

    unordered_set<int> visited;
    int max_bombs = -1;
    for (int i = 0; i < n; i++) {

      DFS(i, visited, adj);

      auto bombs_detonated = visited.size();

      max_bombs = (max_bombs > bombs_detonated ? max_bombs : bombs_detonated);

      visited.clear();
    }

    return max_bombs;
  }
};
