#include <cstring>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> findThePrefixCommonArray(vector<int> &A, vector<int> &B) {
    unordered_map<int, int> mp;

    vector<int> res;
    int count = 0;
    for (int i = 0; i < A.size(); i++) {
      if (A[i] == B[i])
        count++;
      else {
        if (mp.find(A[i]) != mp.end()) {
          count++;
        }

        if (mp.find(B[i]) != mp.end())
          count++;
      }

      mp[A[i]]++, mp[B[i]]++;

      res[i] = count;
    }

    return res;
  }
};