#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

class BFS_Solution {
public:
  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int nodes = graph.size();
    vector<vector<int>> reverseGraph(nodes);
    vector<int> indegree(nodes, 0);
    queue<int> q;

    for (int i = 0; i < nodes; i++) {
      for (auto &v : graph[i]) {
        reverseGraph[v].push_back(i);
        indegree[i]++;
      }
    }

    for (int i = 0; i < nodes; i++) {
      if (indegree[i] == 0)
        q.push(i);
    }

    vector<int> safeNodes;

    while (!q.empty()) {
      int node = q.front();

      q.pop();

      safeNodes.push_back(node);

      for (auto &num : reverseGraph[node]) {
        indegree[num]--;
        if (indegree[num] == 0) {
          q.push(num);
        }
      }
    }

    sort(safeNodes.begin(), safeNodes.end());

    return safeNodes;
  }
};

class DFS_Solution {
public:
  const int not_visited = 0, node_safe = 1, in_path = 2;

  bool is_cycle(vector<vector<int>> &graph, vector<int> &visited, int node) {

    visited[node] = in_path;

    for (auto &v : graph[node]) {
      if (visited[v] == not_visited) {
        if (is_cycle(graph, visited, v))
          return true;
      } else if (visited[v] == in_path) {
        return true;
      }
    }

    visited[node] = node_safe;
    return false;
  }

  vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
    int V = graph.size();

    vector<int> visited(V, not_visited);

    for (int i = 0; i < V; i++) {
      if (visited[i] == not_visited)
        is_cycle(graph, visited, i);
    }

    vector<int> ans;
    for (int i = 0; i < V; i++) {
      if (visited[i] == node_safe)
        ans.push_back(i);
    }

    sort(ans.begin(), ans.end());
    return ans;
  }
};