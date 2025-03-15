#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int maxLengthTiles(vector<string> &A) {
  int n = A.size();

  unordered_map<char, int> mp;

  mp['R'] = -1, mp['G'] = -1;

  int maxT = 0;

  for (int i = 1; i <= n; i++) {
    auto tile = A[i - 1];
    int t;
    if (mp[tile[0]] != -1) {
      t = 1 + mp[tile[0]];
    } else {
      t = 1;
    }

    mp[tile[1]] = max(mp[tile[1]], t);
    maxT = max(maxT, t);
  }

  return maxT;
}

int main() {
  vector<string> A = {"RR", "RG", "GG", "GR", "GG", "GR"};

  cout << maxLengthTiles(A) << endl;
}