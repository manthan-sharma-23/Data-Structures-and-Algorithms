//  link ->
//  https://docs.google.com/document/d/1tEbY2U6-csqe17-S4dpBAegeEvSoy8CWXI5_tCNTI-Y/edit?tab=t.0

#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> adj;
vector<int> nSums;
vector<vector<int>> wts;

int minNode = 1;

int minBusses = INT_MAX;

int dfsIn(int node, int parent, vector<bool> &value) {
  int nSum = 0;

  for (const auto &child : adj[node]) {
    if (child == parent)
      continue;
    int tChild = dfsIn(child, node, value);

    wts[child][node] = tChild, wts[node][child] = tChild;
    nSum += tChild;
  }

  nSums[node] = nSum;

  int self = value[node] > 0;

  return max(nSum, self);
}

void dfsOut(int node, int parent, vector<bool> &value) {
  int newParentBusses = nSums[parent] - wts[node][parent];

  nSums[node] += newParentBusses;
  int newBusses = (nSums[node] == 0 ? value[node] : nSums[node]);

  if (newBusses <= minBusses) {
    minBusses = newBusses;
    minNode = node;
  }

  for (auto child : adj[node]) {
    if (child == parent)
      continue;

    dfsOut(child, node, value);
  }
}

int findMinimumBusses(vector<vector<int>> &edges, vector<bool> &hasPassengers) {
  int V = edges.size() + 1;

  adj.resize(V + 1);
  nSums.resize(V + 1, 0);
  wts.resize(V + 1, vector<int>(V + 1, 0));

  for (auto &edge : edges) {
    adj[edge[0]].push_back(edge[1]);
    adj[edge[1]].push_back(edge[0]);
  }

  minBusses = dfsIn(1, -1, hasPassengers);

  for (auto node : adj[1]) {
    dfsOut(node, 1, hasPassengers);
  }

  return minBusses;
}

int main() {
  vector<vector<int>> edges = {{1, 2},  {1, 3},  {2, 4},   {2, 5},
                               {4, 10}, {4, 13}, {10, 11}, {10, 12},
                               {3, 6},  {3, 7},  {6, 8},   {6, 9}};

  vector<bool> hasPassengers = {0, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0, 1};

  cout << findMinimumBusses(edges, hasPassengers) << " " << minNode << endl;
}