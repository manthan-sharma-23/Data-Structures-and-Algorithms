#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

bool checkPermutationInGraph(vector<int> &perm, vector<string> &graph) {

  for (int i = 0; i < perm.size(); i++) {
    for (int j = 0; j < perm.size(); j++) {
      if (i == j)
        continue;

      if (perm[i] < perm[j] && graph[i][j] != '0') {
        return false;
      } else if (perm[i] > perm[j] && graph[i][j] != '1') {
        return false;
      }
    }
  }

  return true;
}

void reconstructPermutation(int n, vector<string> &graph) {
  vector<int> perm(n, 0);
  for (int i = 0; i < n; i++)
    perm[i] = i + 1;

  while (!checkPermutationInGraph(perm, graph)) {
    for (int i = 0; i < n; i++) {
      cout << perm[i] << " ";
    }
    cout << endl;
    next_permutation(perm.begin(), perm.end());
  }

  for (int i = 0; i < n; i++) {
    cout << perm[i] << " ";
  }
}

int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<string> graph(n);
    for (int i = 0; i < n; ++i) {
      cin >> graph[i];
    }
    reconstructPermutation(n, graph);
  }
  return 0;
}
