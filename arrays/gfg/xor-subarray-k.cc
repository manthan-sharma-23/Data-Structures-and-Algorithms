
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  long subarrayXor(vector<int> &arr, int k) {

    unordered_map<int, int> mp;
    int prefixXor = 0;

    long count = 0;

    for (int i = 0; i < arr.size(); i++) {
      prefixXor ^= arr[i];

      if (prefixXor == k)
        count++;
      else if (mp.count(prefixXor ^ k)) {
        count += mp[prefixXor ^ k];
      }

      mp[prefixXor]++;
    }

    return count;
  }
};