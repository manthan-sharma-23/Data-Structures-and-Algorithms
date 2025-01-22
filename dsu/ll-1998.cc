#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class DisjointSet {
  vector<int> parent, size;
  int components;

public:
  DisjointSet(int n) {
    parent.resize(n);
    size.resize(n);
    components = n;

    for (int i = 0; i < n; i++) {
      parent[i] = i;
      size[i] = 1;
    }
  }

  int findParent(int n) {
    if (parent[n] == n)
      return n;

    return parent[n] = findParent(parent[n]);
  }

  bool unionBySize(int u, int v) {
    int ult_u = findParent(u);
    int ult_v = findParent(v);

    if (ult_u == ult_v)
      return false;

    if (size[ult_u] > size[ult_v]) {
      parent[ult_v] = ult_u;
      size[ult_u] += size[ult_v];
    } else {
      parent[ult_u] = ult_v;
      size[ult_v] += size[ult_u];
    }
    components--;

    return true;
  }

  bool isSingle() { return components <= 1; }
};

class Solution {
public:
  bool isSwappable(int a, int b) {
    for (int i = 2; i <= min(a, b); i++) {
      if (a % i == 0 && b % i == 0)
        return true;
    }
    return false;
  }

  bool gcdSort(vector<int> &nums) {
    int n = nums.size();
    int maxNum = *max_element(nums.begin(), nums.end());
    DisjointSet ds(maxNum + 1);

    vector<int> smallestPrime(maxNum + 1, 0);

    for (int i = 0; i < n; ++i) {
      for (int j = 2; j <= sqrt(nums[i]); ++j) {
        if (nums[i] % j == 0) {
          ds.unionBySize(nums[i], j);
          ds.unionBySize(nums[i], nums[i] / j);
        }
      }
    }

    vector<int> sorted_nums = nums;
    sort(sorted_nums.begin(), sorted_nums.end());

    for (int i = 0; i < n; i++) {
      if (ds.findParent(nums[i]) != ds.findParent(sorted_nums[i]))
        return false;
    }

    return true;
  }
};