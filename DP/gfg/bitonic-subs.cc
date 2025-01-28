#include <vector>

using namespace std;

class Solution {
public:
  int LongestBitonicSequence(int n, vector<int> &nums) {
    vector<int> increasing(n, 1);
    vector<int> decreasing(n, 1);

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i] && increasing[j] + 1 > increasing[i]) {
          increasing[i] = increasing[j] + 1;
        }
      }
    }

    for (int i = n - 1; i >= 0; i--) {
      for (int j = n - 1; j > i; j--) {
        if (nums[i] > nums[j] && decreasing[j] + 1 > decreasing[i]) {
          decreasing[i] = decreasing[j] + 1;
        }
      }
    }
    int maxL = 0;
    for (int i = 0; i < n; i++) {
      if (increasing[i] > 1 && decreasing[i] > 1)
        maxL = max(increasing[i] + decreasing[i] - 1, maxL);
    }

    return maxL;
  }
};