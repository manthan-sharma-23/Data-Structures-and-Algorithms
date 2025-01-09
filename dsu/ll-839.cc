#include <string>
#include <vector>

using namespace std;

class DisjointSet {
  vector<int> parent;

public:
  DisjointSet(int n) {
    parent.resize(n);

    for (int i = 0; i < n; i++) {
      parent[i] = i;
    }
  }

  int findParent(int n) {
    if (parent[n] == n)
      return n;

    return parent[n] = findParent(parent[n]);
  }

  void union_set(int u, int v) {
    int ult_u = findParent(u);
    int ult_v = findParent(v);

    if (ult_u != ult_v) {
      if (ult_u < ult_v) {
        parent[ult_v] = ult_u;
      } else {
        parent[ult_u] = ult_v;
      }
    }
  }
};

class Solution {
private:
  //   rather than checking by swapping count the missimilarities in the
  //   solution way more effecient
  bool is_simillar(const string &a, const string &b) {
    if (a.length() != b.length())
      return false;

    int mismatch = 0;
    vector<int> indices;

    for (int i = 0; i < a.length(); i++) {
      if (a[i] != b[i]) {
        mismatch++;
        indices.push_back(i);

        if (mismatch > 2)
          return false;
      }
    }

    return mismatch == 0 || (mismatch == 2 && a[indices[0]] == b[indices[1]] &&
                             a[indices[1]] == b[indices[0]]);
  }

public:
  int numSimilarGroups(vector<string> &strs) {
    int N = strs.size();
    DisjointSet ds(N);

    for (int i = 0; i < N; i++) {
      for (int j = i + 1; j < N; j++) {
        string a = strs[i], b = strs[j];
        if (is_simillar(a, b)) {
          ds.union_set(i, j);
        }
      }
    }

    int group = 0;
    for (int i = 0; i < N; i++) {
      if (ds.findParent(i) == i)
        group++;
    }

    return group;
  }
};