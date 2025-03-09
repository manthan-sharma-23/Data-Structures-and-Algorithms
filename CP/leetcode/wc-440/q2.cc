#include <algorithm>
#include <queue>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  typedef long long ll;
  vector<long long> findMaxSum(vector<int> &nums1, vector<int> &nums2, int k) {
    int n = nums1.size();

    vector<pair<int, int>> sorted1;

    for (int i = 0; i < n; i++) {
      sorted1.push_back({nums1[i], i});
    }

    sort(
        sorted1.begin(), sorted1.end(),
        [](pair<int, int> &a, pair<int, int> &b) { return a.first < b.first; });

    vector<ll> ans(n, 0LL);
    multiset<int> st;
    ll sum = 0;
    ll prev = -1, prevAns = 0;
    for (auto it : sorted1) {
      if (it.first == prev) {
        ans[it.second] = prevAns;
      } else {
        ans[it.second] = sum;
        prevAns = sum;
        prev = it.first;
      }

      int val = nums2[it.second];

      if (st.size() < k) {
        st.insert(val);
        sum += val;
      } else {
        auto it = st.begin();
        if (*it <= val) {
          sum -= *it, sum += val;
          st.erase(it);
          st.insert(val);
        }
      }
    }

    return ans;
  }
};