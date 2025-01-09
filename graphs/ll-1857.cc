
#include <algorithm>
#include <cstring>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// TLE
class DFS_Solution {
private:
  int max_score = 0;
  int hash[26];
  string colors;

  vector<vector<int>> adj;
  vector<bool> visited, inStack;

  bool dfs(int u) {
    visited[u] = 1;
    inStack[u] = 1;

    int color = colors[u] - 'a';

    hash[color]++;

    if (!adj[u].size()) {
      int max_path = 0;
      for (auto occur : hash) {
        max_path = max(max_path, occur);
      }
      max_score = max(max_path, max_score);
      hash[color]--;
      inStack[u] = 0;
      return 0;
    }

    for (auto node : adj[u]) {
      if (!visited[node]) {
        if (dfs(node))
          return 1;
      } else if (!inStack[node]) {
        if (dfs(node))
          return 1;
      } else if (inStack[node]) {
        return 1;
      }
    }

    hash[color]--;
    inStack[u] = 0;

    return 0;
  }

public:
  int largestPathValue(string colors, vector<vector<int>> &edges) {
    int n = colors.length();
    adj.resize(n);
    this->colors = colors;

    for (const auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
    }

    visited.resize(n, 0), inStack.resize(n, 0);

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        memset(hash, 0, sizeof(hash));
        if (dfs(i))
          return -1;
      }
    }

    return this->max_score;
  }
};

//  Topo sort
class Solution {
public:
  int largestPathValue(string colors, vector<vector<int>> &edges) {
    int n = colors.length();

    vector<vector<int>> adj(n);
    int inDegree[n];
    memset(inDegree, 0, sizeof(inDegree));

    for (const auto &edge : edges) {
      int u = edge[0];
      int v = edge[1];

      adj[u].push_back(v);
      inDegree[v]++;
    }

    queue<int> q;
    int memo[n][26];
    memset(memo, 0, sizeof(memo));

    for (int i = 0; i < n; i++) {
      if (inDegree[i] == 0) {
        q.push(i);
        memo[i][colors[i] - 'a'] = 1;
      }
    }

    int ans = 0, count = 0;

    while (!q.empty()) {
      int top = q.front();
      q.pop();
      count++;

      ans = max(ans, memo[top][colors[top] - 'a']);

      for (const auto node : adj[top]) {
        int node_color = colors[node] - 'a';
        for (int i = 0; i < 26; i++) {
          memo[node][i] = max(memo[node][i], memo[top][i] + (node_color == i));
        }
        inDegree[node]--;
        if (inDegree[node] == 0) {
          q.push(node);
        }
      }
    }

    if (count < n) {
      return -1;
    }

    return ans;
  }
};