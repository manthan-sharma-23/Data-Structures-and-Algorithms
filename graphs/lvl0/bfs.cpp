#include <iostream>
#include <queue>
#include <set>
#include <vector>

std::vector<int> bfs_on_graph(std::vector<int> adj[]) {
  std::vector<int> result;
  std::set<int> visited_set;
  std::queue<int> q;

  q.push(0);

  while (!q.empty()) {
    auto node = q.front();
    q.pop();

    if (visited_set.find(node) == visited_set.end()) {
      result.push_back(node);
      visited_set.insert(node);
    }

    for (auto n : adj[node]) {
      if (visited_set.find(n) == visited_set.end()) {
        q.push(n);
      }
    }
  }

  return result;
}

int main() {
  // Adjacency List Representation
  std::vector<int> adj[5];
  adj[0] = {1, 4};
  adj[1] = {3, 2};
  adj[2] = {};
  adj[3] = {4};
  adj[4] = {};

  // Perform DFS
  std::vector<int> res = bfs_on_graph(adj);

  // Print DFS Traversal
  for (auto i : res) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
