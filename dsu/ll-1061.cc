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
public:
  int charToNum(char a) { return a - 'a'; }

  char numToChar(int num) { return 'a' + num; }

  string smallestEquivalentString(string s1, string s2, string baseStr) {
    int n = s1.length();
    DisjointSet ds(26);
    for (int i = 0; i < n; i++) {
      ds.union_set(charToNum(s1[i]), charToNum(s2[i]));
    }
    for (int i = 0; i < baseStr.length(); i++) {
      int parentNum = ds.findParent(charToNum(baseStr[i]));
      baseStr[i] = numToChar(parentNum);
    }

    return baseStr;
  }
};
