#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void dfs(int node, int &curans, vector<vector<int>> &adj,
           vector<int> &visited, vector<pair<int, int>> &inStack, int curDis) {

    visited[node] = 1;
    inStack[node] = {1, curDis};

    for (auto it : adj[node]) {
      if (visited[it] && inStack[it].first) {
        curans = max(curans, curDis + 1 - inStack[it].second);
      }

      if (!visited[it]) {
        dfs(it, curans, adj, visited, inStack, curDis + 1);
      }
    }

    inStack[node].first=0;
  }
  int longestCycle(vector<int> &edges) {
    int n = edges.size();
    vector<vector<int>> adj(n);

    for (int i = 0; i < n; i++) {

      if (edges[i] != -1)
        adj[i].push_back(edges[i]);
    }
    
    vector<int> visited(n, 0);
    int ans = 0;

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        vector<pair<int, int>> inStack(n, {0, 0});
        int curans = 0;
        dfs(i, curans, adj, visited, inStack, 0);

        ans = max(ans, curans);
      }
    }
    return ans == 0 ? -1 : ans;
  }
};