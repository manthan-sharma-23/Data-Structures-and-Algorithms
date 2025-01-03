#include <queue>
#include <stack>
#include <vector>

using namespace std;

class Stack_Solution {
public:
  void dfs(vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st,
           int node) {
    visited[node] = true;

    for (auto &num : adj[node]) {
      if (!visited[num]) {
        dfs(adj, visited, st, num);
      }
    }

    st.push(node);
  }

  vector<int> topologicalSort(vector<vector<int>> &adj) {
    stack<int> st;
    int n = adj.size();
    vector<bool> visited(n, 0);

    for (int i = 0; i < n; i++) {
      if (!visited[i]) {
        dfs(adj, visited, st, i);
      }
    }

    vector<int> res;

    while (!st.empty()) {
      res.push_back(st.top());
      st.pop();
    }

    return res;
  }
};

class Topo_Solution {
public:
  vector<int> topologicalSort(vector<vector<int>> &adj) {
    int n = adj.size();
    vector<int> in_degree(n, 0);

    vector<int> res;

    queue<int> q;

    for (int i = 0; i < n; i++) {
      for (auto &num : adj[i]) {
        in_degree[num]++;
      }
    }

    for (int i = 0; i < n; i++) {
      if (!in_degree[i])
        q.push(i);
    }

    while (!q.empty()) {
      int front = q.front();
      q.pop();

      res.push_back(front);

      for (auto &num : adj[front]) {
        in_degree[num]--;
        if (!in_degree[num])
          q.push(num);
      }
    }

    return res;
  }
};
