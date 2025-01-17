#include "vector"
#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> topoSort(int k, vector<vector<int>> &edges) {
    unordered_map<int, vector<int>> adj;
    vector<int> inDegree(k, 0);

    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      inDegree[edge[1] - 1]++;
    }

    queue<int> q;

    for (int i = 0; i < k; i++) {
      if (inDegree[i] == 0) {
        q.push(i + 1);
      }
    }

    vector<int> res;

    while (!q.empty()) {
      int u = q.front();
      q.pop();
      res.push_back(u);
      for (int node : adj[u]) {
        inDegree[node - 1]--;
        if (inDegree[node - 1] == 0) {
          q.push(node);
        }
      }
    }

    if (res.size() != k) {
      return {};
    }

    return res;
  }

  vector<vector<int>> buildMatrix(int k, vector<vector<int>> &rowConditions,
                                  vector<vector<int>> &colConditions) {
    auto rowV = topoSort(k, rowConditions);
    auto colV = topoSort(k, colConditions);

    if (rowV.empty() || colV.empty()) {
      return {};
    }

    unordered_map<int, int> rowPos, colPos;
    for (int i = 0; i < k; i++) {
      rowPos[rowV[i]] = i;
      colPos[colV[i]] = i;
    }

    vector<vector<int>> matrix(k, vector<int>(k, 0));

    for (int i = 1; i <= k; i++) {
      int row = rowPos[i];
      int col = colPos[i];
      matrix[row][col] = i;
    }

    return matrix;
  }
};