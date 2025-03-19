#include <climits>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
  vector<int> smallestSufficientTeam(vector<string> &req_skills,
                                     vector<vector<string>> &people) {
    int n = req_skills.size();

    unordered_map<string, int> mp;

    for (int i = 0; i < n; i++) {
      mp[req_skills[i]] = i;
    }
    int allSkills = (1 << n) - 1;

    vector<int> devs(people.size());

    for (int i = 0; i < people.size(); i++) {
      int skill = 0;
      for (string s : people[i]) {
        skill |= (1 << mp[s]);
      }
      devs[i] = skill;
    }

    vector<vector<int>> dp(devs.size() + 1, vector<int>(allSkills + 1, 1e7));
    vector<vector<int>> parent(devs.size() + 1, vector<int>(allSkills + 1, -1));

    for (int i = 0; i <= n; i++) {
      dp[i][0] = 0;
    }

    for (int i = 1; i <= devs.size(); i++) {
      int currSkill = devs[i - 1];
      for (int j = 0; j <= allSkills; j++) {
        dp[i][j] = dp[i - 1][j];
        parent[i][j] = j;

        int neededSkill = (j & currSkill) ^ j;
        if (dp[i][j] > 1 + dp[i - 1][neededSkill]) {
          dp[i][j] = 1 + dp[i - 1][neededSkill];
          parent[i][j] = neededSkill;
        }
      }
    }

    vector<int> path;
    int currSkill = allSkills, r = devs.size();

    while (currSkill > 0) {
      if (parent[r][currSkill] != currSkill) {
        path.push_back(r - 1);
        currSkill = parent[r][currSkill];
      }
      r--;
    }

    return path;
  }
};
