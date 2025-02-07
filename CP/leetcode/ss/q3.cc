
#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

class Solution {
public:
  bool findFreeGap(vector<int> &startTime, vector<int> &endTime, int ri, int ei,
                   int eventTime, int duration) {
    int n = startTime.size();

    if (ei <= 0 && (startTime[0] >= duration)) {
      return true;
    }

    for (int i = 0; i < ri; i++) {
      int starttime = startTime[i];
      int endtime = endTime[i];

      int lastMeetingEndtime = (i == 0) ? 0 : endTime[i - 1];
      int nextMeetingStartime = (i == (n - 1)) ? eventTime : startTime[i + 1];

      if (nextMeetingStartime - endtime >= duration)
        return true;

      if (starttime - lastMeetingEndtime >= duration)
        return true;
    }

    if (ei >= n - 1 && (eventTime - endTime[n - 1] >= duration)) {
      return true;
    }

    for (int i = ei + 1; i < n; i++) {
      int starttime = startTime[i];
      int endtime = endTime[i];

      int lastMeetingEndtime = (i == 0) ? 0 : endTime[i - 1];
      int nextMeetingStartime = (i == (n - 1)) ? eventTime : startTime[i + 1];

      if (nextMeetingStartime - endtime >= duration)
        return true;

      if (starttime - lastMeetingEndtime >= duration)
        return true;
    }

    return false;
  }

  int maxFreeTime(int eventTime, vector<int> &startTime, vector<int> &endTime) {
    int n = startTime.size();

    int maxFreeTime = 0;
    for (int i = 0; i < n; i++) {
      int starttime = startTime[i];
      int endtime = endTime[i];

      int lastMeetingEndtime = (i == 0) ? 0 : endTime[i - 1];
      int nextMeetingStartime = (i == (n - 1)) ? eventTime : startTime[i + 1];

      maxFreeTime = max(maxFreeTime, max(starttime - lastMeetingEndtime,
                                         nextMeetingStartime - endtime));
    }

    for (int i = 0; i < n; i++) {

      int starttime = startTime[i];
      int endtime = endTime[i];
      int duration = endtime - starttime;

      int lastMeetingEndtime = (i == 0) ? 0 : endTime[i - 1];
      int nextMeetingStartime = (i == (n - 1)) ? eventTime : startTime[i + 1];

      if (findFreeGap(startTime, endTime, i - 1, i + 1, eventTime, duration)) {
        maxFreeTime =
            max(maxFreeTime, nextMeetingStartime - lastMeetingEndtime);
      } else {
        int shiftMeetingInRow =
            (nextMeetingStartime - lastMeetingEndtime) - duration;

        maxFreeTime = max(maxFreeTime, shiftMeetingInRow);
      }
    }

    return maxFreeTime;
  }
};

int main() {

  vector<int> startTime = {
      0,
      17,
  };
  vector<int> endTime = {14, 19};

  Solution s;
  int m = s.maxFreeTime(34, startTime, endTime);

  cout << m << endl;
}