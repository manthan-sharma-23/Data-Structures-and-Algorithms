#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int find(int parent[], int i) {
    if (parent[i] == i) {
      return i;
    }
    // path compression
    return parent[i] = find(parent, parent[i]);
  }

  void unionSet(int parent[], int a, int b) {
    int parent_a = find(parent, a);
    int parent_b = find(parent, b);

    if (parent_a != parent_b) {
      parent[parent_a] = parent[b];
    }
  }
};
