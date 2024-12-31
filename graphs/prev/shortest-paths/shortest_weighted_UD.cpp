#include <bits/stdc++.h>
#include <climits>
#include <functional>
#include <queue>
#include <utility>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> shortestPath(int n, int m, vector<vector<int>> &edges) {
    typedef pair<int, pair<int, int>> node;
    const vector<pair<int, int>> directions = {
        {1, 0}, {0, 1}, {-1, 0}, {0, -1}};

    vector<vector<int>> dist(n,vector<int>(m,INT_MA));
    priority_queue<node, vector<node>, greater<node>> pq;

    pq.push({0, {0, 0}});


  }
};
