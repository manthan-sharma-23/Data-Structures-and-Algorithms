#include <algorithm>
#include <queue>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> validArrangement(vector<vector<int>> &pairs) {

    unordered_map<int, vector<int>> adj;
    unordered_map<int, int> indegree;
    unordered_map<int, int> outdegree;

    for (auto pair : pairs) {
      int v = pair[0];
      int u = pair[1];

      adj[v].push_back(u);

      indegree[u]++;
      outdegree[v]++;
    }
    int startNode = -1;

    for (auto [node, degree] : outdegree) {
      if (outdegree[node] - indegree[node] == 1) {
        startNode = node;
        break;
      }
    }

    vector<int> path;
    stack<int> st;
    st.push(startNode);

    while (!st.empty()) {
      auto currNode = st.top();

      if (!adj[currNode].empty()) {
        int ngbr = adj[currNode].back();
        adj[currNode].pop_back();
        st.push(ngbr);
      } else {
        path.push_back(currNode);
        st.pop();
      }
    }

    reverse(begin(path), end(path));
    vector<vector<int>> result;
    for (int i = 0; i < path.size() - 1; i++) {
      result.push_back({path[i], path[i + 1]});
    }

    return {};
  }
};