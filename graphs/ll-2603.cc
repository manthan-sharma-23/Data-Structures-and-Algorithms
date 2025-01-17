#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

class Solution {
public:
  vector<vector<int>> adj;
  vector<int> has_coin;

  vector<int> subTreeTime;
  vector<int> rootTime;

  vector<vector<int>> subTreeCoins;
  vector<vector<int>> rootCoins;

  void mergeCoins(vector<int> &src, vector<int> &child) {
    src[1] += child[0];
    src[2] += child[1];
    src[3] += child[2] + child[3];
  }

  void mergeTime(int &srcTime, int &childTime, vector<int> &child) {
    if (child[2] + child[3] > 0) {
      srcTime += childTime + 2;
    }
  }

  void removeCoins(vector<int> &src, vector<int> &child) {
    src[1] -= child[0];
    src[2] -= child[1];
    src[3] -= (child[2] + child[3]);
  }

  void removeTime(int &srcTime, int &childTime, vector<int> &child) {
    if (child[2] + child[3] > 0) {
      srcTime -= (childTime + 2);
    }
  }

  void dfsIn(int root, int parent) {
    for (auto child : adj[root]) {
      if (child == parent)
        continue;

      dfsIn(child, root);

      mergeCoins(subTreeCoins[root], subTreeCoins[child]);
      mergeTime(subTreeTime[root], subTreeTime[child], subTreeCoins[child]);
    }

    if (has_coin[root]) {
      subTreeCoins[root][0] = 1;
    }
  }

  void dfsOut(int root, int parent) {
    for (auto child : adj[root]) {
      if (child == parent)
        continue;

      vector<int> root_coins = rootCoins[root];
      removeCoins(root_coins, subTreeCoins[child]);

      int root_time = rootTime[root];
      removeTime(root_time, subTreeTime[child], subTreeCoins[child]);

      rootCoins[child] = subTreeCoins[child];
      mergeCoins(rootCoins[child], root_coins);

      rootTime[child] = subTreeTime[child];
      mergeTime(rootTime[child], root_time, root_coins);

      dfsOut(child, root);
    }
  }

  int collectTheCoins(vector<int> &coins, vector<vector<int>> &edges) {
    int n = coins.size();

    if (n <= 1)
      return 0;

    has_coin = coins;
    subTreeCoins.resize(n, vector<int>(4, 0));
    rootCoins.resize(n, vector<int>(4, 0));

    rootTime.resize(n, 0);
    subTreeTime.resize(n, 0);

    adj.resize(n);
    for (const auto &edge : edges) {
      adj[edge[0]].push_back(edge[1]);
      adj[edge[1]].push_back(edge[0]);
    }

    dfsIn(0, -1);
    rootTime[0] = subTreeTime[0];
    rootCoins[0] = subTreeCoins[0];

    dfsOut(0, -1);

    int minTime = INT_MAX;

    for (auto time : rootTime)
      minTime = min(minTime, time);

    return minTime;
  }
};