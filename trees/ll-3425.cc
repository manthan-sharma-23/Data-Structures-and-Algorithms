#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  vector<vector<pair<int, int>>> adj;
  vector<int> colors;
  int maxLength = 0, minNodes = 0;

  void dfs(int node, int parent, int start, int end, int pathSum,
           vector<int> &path, unordered_map<int, int> &colorMap) {
    int prevIndex = colorMap.count(colors[node]) ? colorMap[colors[node]] : -1;

    while (start <= prevIndex) {
      pathSum -= path[start++];
    }

    if (pathSum > maxLength) {
      maxLength = pathSum;
      minNodes = end - start + 1;
    } else if (pathSum == maxLength) {
      minNodes = min(minNodes, end - start + 1);
    }

    colorMap[colors[node]] = end;

    for (auto [child, wt] : adj[node]) {
      if (child == parent)
        continue;
      path.push_back(colors[child]);
      dfs(child, node, start, end + 1, pathSum + wt, path, colorMap);
      path.pop_back();
    }

    colorMap[colors[node]] = prevIndex;
  }

public:
  vector<int> longestSpecialPath(vector<vector<int>> &edges,
                                 vector<int> &nums) {
    int n = nums.size();
    this->colors.insert(this->colors.begin(), nums.begin(), nums.end()),
        this->adj.resize(n);

    for (const auto &edge : edges) {
      int u = edge[0], v = edge[1], wt = edge[2];
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }

    vector<int> path;
    unordered_map<int, int> colorsMap;

    dfs(0, -1, 0, 0, 0, path, colorsMap);

    return {maxLength, minNodes};
  }
};