#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class DisjointSet {
  vector<int> parent, size;

public:
  DisjointSet(int n) {
    parent.resize(n);
    size.resize(n);

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

  void unionBySize(int u, int v) {
    int ult_u = findParent(u);
    int ult_v = findParent(v);

    if (ult_u == ult_v)
      return;

    if (size[ult_u] > size[ult_v]) {
      parent[ult_v] = ult_u;
      size[ult_u] += size[ult_v];
    } else {
      parent[ult_u] = ult_v;
      size[ult_v] += size[ult_u];
    }
  }
};

class Solution {
public:
  vector<vector<string>> accountsMerge(vector<vector<string>> &accounts) {
    int n = accounts.size();
    DisjointSet ds(n);
    unordered_map<string, int> mp;
    for (int i = 0; i < n; i++) {
      for (int j = 1; j < accounts[i].size(); j++) {
        string mail = accounts[i][j];

        if (mp.find(mail) == mp.end()) {
          mp[mail] = i;
        } else {
          ds.unionBySize(i, mp[mail]);
        }
      }
    }

    unordered_map<int, vector<string>> mergedAccounts;

    for (auto &it : mp) {
      string mail = it.first;
      int idx = it.second;

      int pt = ds.findParent(idx);
      mergedAccounts[pt].push_back(mail);
    }

    vector<vector<string>> ans;

    for (auto &it : mergedAccounts) {
      int idx = it.first;
      vector<string> &emails = it.second;

      sort(emails.begin(), emails.end());
      emails.insert(emails.begin(), accounts[idx][0]);
      ans.push_back(emails);
    }

    return ans;
  }
};
