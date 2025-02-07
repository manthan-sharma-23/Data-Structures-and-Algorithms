#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &arr, int k) {
    unordered_map<int, int> occurence;
    int prefixSum = 0;
    int len = 0;
    for (int i = 0; i < arr.size(); i++) {
      prefixSum += arr[i];

      if (prefixSum == k) {
        len = i + 1;
      }

      if (occurence.find(prefixSum - k) != occurence.end()) {
        int j = occurence[prefixSum - k];
        len = max(len, i - j + 1);
      }

      if (occurence.find(prefixSum) == occurence.end())
        occurence[prefixSum] = i;
    }

    return len;
  }
};