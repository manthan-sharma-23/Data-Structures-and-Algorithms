#include <iostream>
#include <vector>

using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    string s;
    const int NOT = 1e8;
    cin >> n >> m >> s;

    vector<vector<int>> arr(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
      }
    }

    int i = 0, j = 0, idx = 0;

    while (idx < s.length() && i < n && j < m) {
      char dir = s[idx];
      arr[i][j] = NOT;
      if (dir == 'D') {
        i++;
      } else {
        j++;
      }
    }

    
  }
}