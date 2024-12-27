#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int n = values.size();
    int maxScore{0};
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int score = values[i] + values[j] - (j - i);
        maxScore = max(score, maxScore);
      }
    }

    return maxScore;
  }
};

class Optimal_Solution {
public:
  int maxScoreSightseeingPair(vector<int> &values) {
    int n = values.size();
    int leftMax = values[0];
    int maxScore{0};

    for (int i = 1; i < n; i++) {
      int score = leftMax + (values[i] - i);
      maxScore = max(maxScore, score);

      leftMax = max(leftMax, values[i] + i);
    }

    return maxScore;
  }
};