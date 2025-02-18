#include <vector>

using namespace std;

class Solution {
public:
  int n;
  vector<int> parentTime;

  //     <node,distance>
  vector<pair<int, int>> largestChild;
  vector<pair<int, int>> secondLargestChild;

  vector<vector<int>> adj;

  void updateLargestSecondLargest(int node, int child, int distance) {
    if (distance > largestChild[node].second) {
      secondLargestChild[node] = largestChild[node];
      largestChild[node] = {child, distance};
    } else if (distance <= largestChild[node].second &&
               distance > secondLargestChild[node].second) {
      secondLargestChild[node] = {child, distance};
    }
  }

  bool isEven(int n) { return n % 2 == 0; }

  int newParentTime(int node, int parent) {
    int maxFromParent = 0;

    if (largestChild[parent].first != node) {
      maxFromParent = largestChild[parent].second;
    } else {
      maxFromParent = secondLargestChild[parent].second;
    }
    maxFromParent += (isEven(parent) ? 2 : 1);

    updateLargestSecondLargest(node, parent, maxFromParent);

    return largestChild[node].second;
  }

  int dfsIn(int node, int parent) {

    int sum = 0;

    for (auto child : adj[node]) {
      if (child == parent)
        continue;

      int distance = dfsIn(child, node);

      updateLargestSecondLargest(node, child, distance);

      sum = max(sum, distance);
    }

    return sum + (isEven(node) ? 2 : 1);
  }

  void dfsOut(int node, int parent) {
    parentTime[node] = newParentTime(node, parent);

    for (auto child : adj[node]) {
      if (child == parent)
        continue;

      dfsOut(child, node);
    }
  }

  vector<int> timeTaken(vector<vector<int>> &edges) {
    n = edges.size() + 1;
    parentTime.resize(n, -1);
    largestChild.resize(n);
    secondLargestChild.resize(n);

    adj.resize(n);

    for (auto edge : edges) {
      int u = edge[0], v = edge[1];
      adj[u].push_back(v);
      adj[v].push_back(u);
    }

    parentTime[0] = dfsIn(0, -1) - 2;

    for (auto child : adj[0]) {
      dfsOut(child, 0);
    }

    return parentTime;
  }
};