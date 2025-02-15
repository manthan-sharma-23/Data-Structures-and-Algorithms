/*
Given two array A and B :- Find the number of good indices in array B

Good Index meaning - When you remove this index :- array B becomes a subsequence
of array A

link ->
https://docs.google.com/document/d/18JsYIqpFFBRxa9k63jeotMcPnGeU9-rlC3IvNEGw-8s/edit?tab=t.0
*/

#include <vector>
using namespace std;

int goodIndices(vector<int> &a, vector<int> &b) {
  int n = a.size(), m = b.size();

  vector<int> suffB(m, -1);
  vector<int> prefB(m, -1);

  // calculate suffix of B
  int i = 0, j = 0;

  while (i < n && j < m) {

    if (a[i] == b[j]) {
      i++, j++;
      suffB[j] = i;
    } else
      i++;
  }

  i = n - 1, j = m - 1;
  while (i >= 0 && j >= 0) {

    if (a[i] == b[j]) {
      i--, j--;
      suffB[j] = i;
    } else
      i--;
  }

  int good = (suffB[1] != -1) ? 1 : 0;

  good += (prefB[m - 1] != -1) ? 1 : 0;

  for (int i = 1; i < m - 1; i++) {
    if (prefB[i - 1] != -1 && suffB[i + 1] != -1 &&
        prefB[i - 1] < suffB[i + 1]) {

      good++;
    }
  }

  return good;
}
