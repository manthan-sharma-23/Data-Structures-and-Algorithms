#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int maxLen(vector<int> &arr) {
    unordered_map<int, int> occur;

    int prefixSum = 0;
    int maxLen = 0;
    for (int r = 0; r < arr.size(); r++) {
      prefixSum += arr[r];

      if (prefixSum == 0)
        maxLen = r + 1;

      if (occur.find(prefixSum) != occur.end()) {
        int l = occur[prefixSum];
        maxLen = max(maxLen, r - l);
      } else
        occur[prefixSum] = r;
    }

    return maxLen;
  }
};