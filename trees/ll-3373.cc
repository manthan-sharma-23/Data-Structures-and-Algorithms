#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int n1, n2;
  const int t1 = 0, t2 = 1;
  vector<vector<int>> adj1, adj2;
  vector<unordered_map<int, pair<int, int>>> evenOddNodesStore;
  vector<unordered_map<int, int>> parentStore;
  vector<int> result;

  //   even , odd
  pair<int, int> dfsIn(int node, int parent, const int tree,
                       const vector<vector<int>> &adj) {
    parentStore[tree][node] = parent;
    pair<int, int> src = {1, 0};

    for (auto child : adj[node]) {
      if (child == parent)
        continue;

      auto newPair = dfsIn(child, node, tree, adj);
      src.first += newPair.second;
      src.second += newPair.first;
    }

    return evenOddNodesStore[tree][node] = src;
  }

  void dfsOut(int node, int parent) {
    auto t = evenOddNodesStore[t1][parent];
    evenOddNodesStore[t1][node].first = t.second;
    evenOddNodesStore[t1][node].second = t.first;

    {
      int e1 = evenOddNodesStore[t1][node].first,
          o1 = evenOddNodesStore[t2][0].first,
          o2 = evenOddNodesStore[t2][0].second;
      result[node] = max(e1 + o1, e1 + o2);
    }

    for (auto child : adj1[node]) {
      if (child == parent)
        continue;

      dfsOut(child, node);
    }
  }

  vector<int> maxTargetNodes(vector<vector<int>> &edges1,
                             vector<vector<int>> &edges2) {
    n1 = edges1.size() + 1, n2 = edges2.size() + 1;
    adj1.resize(n1), adj2.resize(n2);
    parentStore.resize(2), evenOddNodesStore.resize(2);
    result.resize(n1);

    for (const auto &edge : edges1) {
      int u = edge[0], v = edge[1];
      adj1[u].push_back(v);
      adj1[v].push_back(u);
    }

    for (const auto &edge : edges2) {
      int u = edge[0], v = edge[1];
      adj2[u].push_back(v);
      adj2[v].push_back(u);
    }

    dfsIn(0, -1, t1, adj1);
    dfsIn(0, -1, t2, adj2);

    //  for node 0
    {
      int e1 = evenOddNodesStore[t1][0].first,
          o1 = evenOddNodesStore[t2][0].second,
          o2 = evenOddNodesStore[t2][0].first;

      result[0] = max(e1 + o1, e1 + o2);
    }

    for (auto node : adj1[0]) {
      dfsOut(node, 0);
    }

    return result;
  }
};