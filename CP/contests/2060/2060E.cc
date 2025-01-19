#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class DSU {
public:
  DSU(int n) {
    parent.resize(n);
    rank.resize(n, 0);
    for (int i = 0; i < n; ++i) {
      parent[i] = i;
    }
  }

  int find(int x) {
    if (parent[x] != x) {
      parent[x] = find(parent[x]);
    }
    return parent[x];
  }

  void union_sets(int x, int y) {
    int rootX = find(x);
    int rootY = find(y);
    if (rootX != rootY) {
      if (rank[rootX] > rank[rootY]) {
        parent[rootY] = rootX;
      } else if (rank[rootX] < rank[rootY]) {
        parent[rootX] = rootY;
      } else {
        parent[rootY] = rootX;
        rank[rootX]++;
      }
    }
  }

private:
  vector<int> parent;
  vector<int> rank;
};

void solve() {
  int t;
  cin >> t;
  while (t--) {
    int n, m1, m2;
    cin >> n >> m1 >> m2;

    DSU dsu_f(n), dsu_g(n);

    // Reading edges for graph F
    for (int i = 0; i < m1; ++i) {
      int u, v;
      cin >> u >> v;
      dsu_f.union_sets(u - 1, v - 1); // 0-based indexing
    }

    // Reading edges for graph G
    for (int i = 0; i < m2; ++i) {
      int u, v;
      cin >> u >> v;
      dsu_g.union_sets(u - 1, v - 1); // 0-based indexing
    }

    // Collecting the connected components for F and G
    unordered_map<int, vector<int>> components_f, components_g;

    for (int i = 0; i < n; ++i) {
      int root_f = dsu_f.find(i);
      int root_g = dsu_g.find(i);
      components_f[root_f].push_back(i);
      components_g[root_g].push_back(i);
    }

    // Counting the number of operations needed
    int remove_operations = 0, add_operations = 0;

    for (auto &comp_f : components_f) {
      if (components_g.find(comp_f.first) == components_g.end()) {
        remove_operations++;
      }
    }

    for (auto &comp_g : components_g) {
      if (components_f.find(comp_g.first) == components_f.end()) {
        add_operations++;
      }
    }

    // The result for this test case
    cout << remove_operations + add_operations << endl;
  }
}

int main() {
  solve();
  return 0;
}
