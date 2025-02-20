#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int totalElements(vector<int> &arr) {
    int n = arr.size();

    unordered_map<int, int> mp;

    int len = 0;

    int i = 0;
    for (int j = 0; j < n; j++) {
      mp[arr[j]]++;

      if (mp.size() > 2) {
        mp[arr[i]]--;
        if (mp[arr[i]] == 0) {
          mp.erase(arr[i]);
        }

        i++;
      }

      len = max(len, j - i + 1);
    }

    return len;
  }
};