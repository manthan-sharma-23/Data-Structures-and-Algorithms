#include <cmath>
#include <map>
#include <vector>

using namespace std;

vector<int> largestGCDOfKSubsets(vector<int> &arr) {
  int n = arr.size();

  map<int, int> freq;

  for (auto num : arr) {
    for (int i = 1; i <= (int)sqrt(num); i++) {
      if (num % i == 0) {
        freq[i]++;
        if (i != num / i)
          freq[num / i]++;
      }
    }
  }

  vector<int> res(n + 1);

  auto it = freq.rbegin();
  int i = 1;
  while (it != freq.rend() && i <= n) {

    if (it->second >= i) {
      res[i] = it->first;
      i++;
    }

    else
      it++;
  }

  return res;
}