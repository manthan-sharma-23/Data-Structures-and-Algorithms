
#include <algorithm>
#include <cmath>
#include <unordered_map>
#include <vector>

using namespace std;

vector<int> largestGCDOfKSubsets(vector<int> &arr, vector<int> &queries) {
  int n = arr.size();

  unordered_map<int, int> freq;

  for (auto num : arr) {
    for (int i = 1; i <= (int)sqrt(num); i++) {
      if (num % i == 0) {
        freq[i]++;
        if (i != num / i)
          freq[num / i]++;
      }
    }
  }

  vector<pair<int, int>> st;

  for (auto it : freq) {
    st.push_back({it.second, it.first});
  }

  sort(st.begin(), st.end(), [](pair<int, int> &a, pair<int, int> &b) {
    if (a.first == b.first)
      return a.second > b.second;
    return a.first > b.first;
  });

  vector<int> res;

  for (auto query : queries) {

    for (auto it : st) {
      if (it.first >= query) {
        res.push_back(it.second);
        break;
      }
    }
  }

  return res;
}