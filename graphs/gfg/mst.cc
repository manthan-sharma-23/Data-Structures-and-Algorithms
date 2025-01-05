
#include <queue>
#include <vector>

using namespace std;
class Prims_Solution {
public:
  // Prim's Algo
  //  < weight, to, from>
  typedef tuple<int, int, int> Node;
  int spanningTree(int V, vector<vector<int>> vec[]) {
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    vector<vector<pair<int, int>>> adj;

    for (auto &node : *vec) {
      adj[node[0]].push_back({node[1], node[2]});
      adj[node[1]].push_back({node[0], node[2]});
    }

    pq.push({0, 0, -1});

    vector<bool> visited(V, false);

    vector<Node> mst;
    while (!pq.empty()) {
      auto &[currWt, to, from] = pq.top();
      pq.pop();
      if (visited[to])
        continue;

      visited[to] = true;
      mst.push_back({currWt, to, from});

      for (auto &[nextNode, wt] : adj[to]) {
        if (!visited[nextNode]) {
          pq.push({wt, nextNode, to});
        }
      }
    }

    int sum = 0;

    for (auto &[_, __, wt] : mst) {
      sum += wt;
    }

    return sum;
  }
};
