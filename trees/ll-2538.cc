#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> adj;
  vector<int> values;
  vector<int> parents;
  vector<int> maxPaths;
  vector<int> secondMaxPaths;
  int n;

  int ans = INT_MIN;

  int dfsIn(int node, int parent) {
    int maxPath = 0, secondMaxPath = 0;
    parents[node] = parent;

    for (int child : adj[node]) {
      if (child == parent)
        continue;

      int t = dfsIn(child, node);

      if (t > maxPath) {
        secondMaxPath = maxPath;
        maxPath = t;
      } else if (t > secondMaxPath) {
        secondMaxPath = t;
      }
    }

    maxPath += values[node];
    secondMaxPath += values[node];

    maxPaths[node] = maxPath;
    secondMaxPaths[node] = secondMaxPath;

    return maxPath;
  }

  void dfsOut(int node, int parent) {
    int maxPathFromChild = maxPaths[node];

    int newMaxPath;

    if (maxPathFromChild + values[parent] == maxPaths[parent]) {
      newMaxPath = secondMaxPaths[parent] + values[node];
    } else {
      newMaxPath = maxPaths[parent] + values[node];
    }

    if (newMaxPath > maxPaths[node]) {
      secondMaxPaths[node] = maxPaths[node];
      maxPaths[node] = newMaxPath;
    } else if (newMaxPath > secondMaxPaths[node]) {
      secondMaxPaths[node] = newMaxPath;
    }

    ans = max(maxPaths[node] - values[node], ans);

    for (int &child : adj[node]) {
      if (child == parent)
        continue;

      dfsOut(child, node);
    }
  }

  long long maxOutput(int n, vector<vector<int>> &edges, vector<int> &price) {
    this->n = n;
    adj.resize(n);
    maxPaths.resize(n), secondMaxPaths.resize(n);
    parents.resize(n, -1);
    values.insert(values.end(), price.begin(), price.end());

    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    dfsIn(0, -1);

    ans = maxPaths[0] - values[0];

    for (int i = 0; i < n; i++) {
      cout << maxPaths[i] << " " << secondMaxPaths[i] << endl;
    }

    for (auto node : adj[0])
      dfsOut(node, 0);

    return ans;
  }
};