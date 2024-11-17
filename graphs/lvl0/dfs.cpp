#include <iostream>
#include <set>
#include <stack>
#include <vector>

// stack
std::vector<int> dfs_on_graph(std::vector<int> adj[]) {
  std::stack<int> st;
  std::set<int> visited;
  std::vector<int> result;
  st.push(0);

  while (!st.empty()) {
    int node = st.top();
    st.pop();
    if (visited.find(node) == visited.end()) {
      visited.insert(node);
      result.push_back(node);
    }
    for (auto n : adj[node]) {
      if (visited.find(n) == visited.end()) {
        st.push(n);
      }
    }
  }

  return result;
};

int main() {
  // Adjacency List Representation
  std::vector<int> adj[5];
  adj[0] = {1, 4};
  adj[1] = {2, 3};
  adj[2] = {};
  adj[3] = {4};
  adj[4] = {};

  // Perform DFS
  std::vector<int> res = dfs_on_graph(adj);

  // Print DFS Traversal
  for (auto i : res) {
    std::cout << i << " ";
  }
  std::cout << std::endl;

  return 0;
}
