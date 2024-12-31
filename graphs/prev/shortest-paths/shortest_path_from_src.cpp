#include <bits/stdc++.h>
#include <climits>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> shortestPath(vector<vector<int>> &edges, int N, int M, int src) {
    vector<int> nodes(N, INT_MAX);

    vector<vector<int>> adj(N);
    for (auto it : edges) {
      if (it[0] >= 0 && it[0] < N && it[1] >= 0 && it[1] < N) {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
      }
    }

    queue<pair<int, int>> q;

    q.push({src, 0});
    nodes[src] = 0;

    while (!q.empty()) {

      int node = q.front().first;
      int distance = q.front().second;

      q.pop();

      for (int i : adj[node]) {
        int nd = distance + 1;
        if (nodes[i] > nd) {
          nodes[i] = nd;
          q.push({i, nd});
        }
      }
    }

    for (int i = 0; i < nodes.size(); i++) {
      if (nodes[i] == INT_MAX) {
        nodes[i] = -1;
      }
    }

    return nodes;
  }
};
