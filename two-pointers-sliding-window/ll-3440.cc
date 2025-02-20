#include <vector>

using namespace std;

class Solution {
public:
  int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime) {
    int n = startTime.size();
    vector<int> freeTime;

    freeTime.push_back(startTime[0]);

    for (int i = 1; i < n; i++) {
      int time = startTime[i] - endTime[i - 1];

      freeTime.push_back(time);
    }

    freeTime.push_back(eventTime - endTime[n - 1]);

    vector<int> right(n);
    vector<int> left(n);

    int maxi = 0;
    for (int i = n - 1; i >= 0; i--) {
      right[i] = maxi;
      maxi = max(maxi, freeTime[i]);
    }

    maxi = 0;
    for (int i = 0; i < n; i++) {
      left[i] = maxi;
      maxi = max(maxi, freeTime[i]);
    }

    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
      int sum = freeTime[i] + freeTime[i + 1];
      int temp = endTime[i] - startTime[i];

      if (right[i + 1] >= temp || left[i] >= temp) {
        sum += temp;
      }

      ans = max(ans, sum);
    }

    return ans;
  }
};