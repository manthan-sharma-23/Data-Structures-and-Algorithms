#include <climits>
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  vector<vector<pair<int, int>>> adj;
  vector<int> colors;
  int maxLength = 0, minNodes = INT_MAX;

  void dfs(int node, int parent, int start, int end, int pathSum,
           int duplicateColor, vector<int> &path,
           unordered_map<int, pair<int, int>> &colorMap) {
    auto thisColorOcc = colorMap.find(colors[node]) != colorMap.end()
                            ? colorMap[colors[node]]
                            : make_pair(-1, -1);

    auto duplicateColorOcc = colorMap.find(colors[node]) != colorMap.end()
                                 ? colorMap[duplicateColor]
                                 : make_pair(-1, -1);

    pair<int, int> thisColorNewOcc;
    pair<int, int> duplicateColorNewOcc;
    int newDuplicateColor = duplicateColor;

    if (thisColorOcc.first != -1) {
      if (duplicateColor != -1 && duplicateColor != colors[node]) {
        while (start <= duplicateColorOcc.second) {
          pathSum -= path[start++];
        }
        duplicateColorNewOcc.second = -1;
        duplicateColorNewOcc.first = duplicateColorOcc.first;
      } else if (thisColorOcc.second != -1) {
        cout << " Hllo<" << endl;
        while (start <= thisColorOcc.second) {
          pathSum -= path[start++];
        }
      }
      thisColorNewOcc.second = thisColorOcc.first;
      thisColorNewOcc.first = end;
      newDuplicateColor = colors[node];
    } else {
      thisColorNewOcc.first = end;
      thisColorNewOcc.second = -1;
      duplicateColorNewOcc = duplicateColorOcc;
    }

    cout << endl;
    cout << node << endl;
    cout << duplicateColor << endl;
    cout << "Sum :: " << pathSum << " " << start << " " << end << endl;
    cout << "Color : " << colors[node] << endl;
    cout << "Path" << endl;
    for (auto p : path) {
      cout << p << " ";
    }
    cout << endl;
    for (auto it : colorMap) {
      cout << it.first << "  :: " << it.second.first << " " << it.second.second
           << endl;
    }

    if (pathSum > maxLength) {
      maxLength = pathSum;
      minNodes = end - start + 1;
    } else if (pathSum == maxLength) {
      minNodes = min(minNodes, end - start + 1);
    }

    colorMap[colors[node]] = thisColorNewOcc;
    colorMap[duplicateColor] = duplicateColorNewOcc;

    for (auto [child, wt] : adj[node]) {
      if (child == parent) {
        continue;
      }
      path.push_back(wt);
      dfs(child, node, start, end + 1, pathSum + wt, newDuplicateColor, path,
          colorMap);
      path.pop_back();
    }

    colorMap[colors[node]] = thisColorOcc;
    colorMap[duplicateColor] = duplicateColorOcc;
  }

public:
  vector<int> longestSpecialPath(vector<vector<int>> &edges,
                                 vector<int> &nums) {
    int n = nums.size();
    colors.insert(this->colors.begin(), nums.begin(), nums.end());
    adj.resize(n);

    for (const auto &edge : edges) {
      int u = edge[0], v = edge[1], wt = edge[2];
      adj[u].push_back({v, wt});
      adj[v].push_back({u, wt});
    }

    vector<int> path;
    unordered_map<int, pair<int, int>> colorsMap;

    dfs(0, -1, 0, 0, 0, -1, path, colorsMap);

    return {maxLength, minNodes};
  }
};