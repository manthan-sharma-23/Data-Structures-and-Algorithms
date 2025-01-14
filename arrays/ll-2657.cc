#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    int n = A.size();
    int freq[n][n + 1];
    memset(freq, 0, sizeof(freq));

    int res[n];

    for (int i = 0; i < n; i++) {
      freq[i][A[i]]++;
      freq[i][B[i]]++;

      
    }
  }
};