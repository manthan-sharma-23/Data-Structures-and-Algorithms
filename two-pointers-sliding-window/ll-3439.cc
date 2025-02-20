#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxFreeTime(int eventTime, int k, vector<int> &startTime,
                  vector<int> &endTime) {
    int n = startTime.size();
    vector<int> freeTime;

    if (startTime[0] > 0) {
      freeTime.push_back(startTime[0]);
    }

    for (int i = 1; i < n; i++) {
      int time = startTime[i] - endTime[i - 1];

      freeTime.push_back(time);
    }

    if (eventTime - endTime[n - 1] > 0)
      freeTime.push_back(eventTime - endTime[n - 1]);

    int i = 0, maxT = 0, freeT = 0;

    for (int j = 0; j < freeTime.size(); j++) {
      freeT += freeTime[j];

      while (j - i + 1 > k + 1) {
        freeT -= freeTime[i];
        i++;
      }

      maxT = max(maxT, freeT);
    }

    return maxT;
  }
};
