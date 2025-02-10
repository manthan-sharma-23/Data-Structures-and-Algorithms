#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &arr, int k) {
    int left = 0, right = 0, maxLen = 0, sum = 0;

    while (right < arr.size()) {
      sum += arr[right++];

      while (sum > k && left < right) {
        sum -= arr[left];
        left++;
      }

      if (sum == k) {
        maxLen = max(maxLen, right - left);
      }
    }

    return maxLen;
  }
};