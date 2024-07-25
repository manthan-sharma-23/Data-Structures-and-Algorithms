#include <bits/stdc++.h>
#include <cstdlib>
#include <functional>
#include <queue>
#include <vector>

using namespace std;

class Solution {
private:
  typedef pair<int, int> P;
  int prims(vector<vector<P>> adj) {
    int n = adj.size();
    vector<bool> visited(n, false);
    priority_queue<P, vector<P>, greater<P>> pq;

    int ans = 0;

    pq.push({0, 0});

    while (!pq.empty()) {
      auto top = pq.top();
      int distance = top.first;
      int node = top.second;

      pq.pop();

      if (visited[node]) {
        continue;
      }
      visited[node] = true;
      ans += distance;

      for (auto it : adj[node]) {
        int adjnode = it.first;
        int adjwt = it.second;

        if (!visited[adjnode]) {
          pq.push({adjwt, adjnode});
        }
      }
    }

    return ans;
  }

public:
  int minCostConnectPoints(vector<vector<int>> &points) {
    int n = points.size();
    vector<bool> visited(n, false);
    vector<vector<P>> adj(n);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {

        int x1 = points[i][0];
        int y1 = points[i][1];

        int x2 = points[j][0];
        int y2 = points[j][1];

        int d = abs(x1 - x2) + abs(y1 - y2);

        adj[i].push_back({j, d});
        adj[j].push_back({i, d});
      }
    }

    return prims(adj);
  }
};
