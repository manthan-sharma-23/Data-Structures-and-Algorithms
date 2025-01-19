#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> topoSort(int n, unordered_map<int, vector<int>> &graph,
                       vector<int> &indegree) {
    queue<int> q;

    for (int i = 0; i < n; i++) {
      if (indegree[i] == 0)
        q.push(i);
    }

    vector<int> res;
    while (!q.empty()) {
      int top = q.front();
      q.pop();

      res.push_back(top);

      for (int neighbor : graph[top]) {
        indegree[neighbor]--;
        if (indegree[neighbor] == 0)
          q.push(neighbor);
      }
    }

    if (res.size() != n)
      return {};
    return res;
  }

  vector<int> sortItems(int n, int m, vector<int> &group,
                        vector<vector<int>> &beforeItems) {
    for (int i = 0; i < n; i++) {
      if (group[i] == -1)
        group[i] = m++;
    }

    unordered_map<int, vector<int>> itemGraph, groupGraph;
    vector<int> itemIndegree(n, 0), groupIndegree(m, 0);

    for (int i = 0; i < n; i++) {
      for (int prev : beforeItems[i]) {
        itemGraph[prev].push_back(i);
        itemIndegree[i]++;

        if (group[i] != group[prev]) {
          groupGraph[group[prev]].push_back(group[i]);
          groupIndegree[group[i]]++;
        }
      }
    }

    vector<int> itemOrder = topoSort(n, itemGraph, itemIndegree);
    vector<int> groupOrder = topoSort(m, groupGraph, groupIndegree);

    if (itemOrder.empty() || groupOrder.empty())
      return {};

    unordered_map<int, vector<int>> groupToItems;
    for (int item : itemOrder) {
      groupToItems[group[item]].push_back(item);
    }

    vector<int> res;
    for (int grp : groupOrder) {
      res.insert(res.end(), groupToItems[grp].begin(), groupToItems[grp].end());
    }

    return res;
  }
};
