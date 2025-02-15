#include <cstdlib>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &nums, int limit) {
    int n = nums.size();
    int len = 0;

    multiset<int> st;
    int i = 0, sum = 0;

    for (int j = 0; j < n; j++) {
      st.insert(nums[j]);

      while (abs(*st.begin() - *st.rbegin()) <= limit) {
        st.erase(st.find(nums[i]));
        i++;
      }

      len = max(len, j - i + 1);
    }

    return len;
  }
};