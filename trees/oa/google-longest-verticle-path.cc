
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
  vector<vector<int>> adj;
  int maxVerticleHeight = 0;

  int dfs(int node, int parent, const vector<int> &vals) {

    int maxV = 0;

    for (auto child : adj[node]) {
      if (child == parent)
        continue;

      int thisV = dfs(child, node, vals);

      maxV = max(maxV, thisV);
    }

    if (vals[node] == 0) {
      maxVerticleHeight = max(maxV, maxVerticleHeight);
      return 0;
    } else {
      ++maxV;
      maxVerticleHeight = max(maxV, maxVerticleHeight);
      return maxV;
    }
  }

public:
  int maximumVerticleHeight(vector<vector<int>> &edges, vector<int> &val) {
    int n = edges.size() + 1;

    adj.resize(n);

    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    dfs(0, -1, val);

    return maxVerticleHeight;
  }
};

// Follow - up - Path might not necessarily be vertical
class FollowUpSolution {
private:
  vector<vector<int>> adj;
  int maxOnesPath = 0;

  int dfs(int node, int parent, const vector<int> &vals) {

    int largest = 0, secondLargest = 0;

    for (auto child : adj[node]) {
      if (child == parent)
        continue;

      int thisPath = dfs(child, node, vals);

      if (thisPath > largest) {
        secondLargest = largest;
        largest = thisPath;
      } else if (thisPath > secondLargest) {
        secondLargest = thisPath;
      }
    }

    if (vals[node] == 1) {
      maxOnesPath = max(maxOnesPath, largest + secondLargest + 1);
      return largest + 1;
    } else {
      maxOnesPath = max(maxOnesPath, largest);
      return 0;
    }
  }

public:
  int maximumOnesPath(vector<vector<int>> &edges, vector<int> &val) {
    int n = edges.size() + 1;

    adj.resize(n);

    for (auto edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    dfs(0, -1, val);

    return maxOnesPath;
  }
};

int main() {
  vector<vector<int>> edges = {{0, 1},   {0, 2},   {0, 3},  {2, 4}, {2, 5},
                               {5, 6},   {5, 7},   {3, 8},  {8, 9}, {9, 10},
                               {10, 11}, {11, 12}, {12, 13}};

  vector<int> vals = {1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1};

  Solution s1;

  cout << s1.maximumVerticleHeight(edges, vals) << endl;

  FollowUpSolution s2;

  cout << s2.maximumOnesPath(edges, vals) << endl;
}