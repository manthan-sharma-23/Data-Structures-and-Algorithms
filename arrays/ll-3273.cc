#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
  long long minDamage(int power, vector<int> &damage, vector<int> &health) {

    int n = damage.size();
    vector<pair<int, int>> enemies;

    long long sumDamage = accumulate(damage.begin(), damage.end(), 0);

    for (int i = 0; i < n; i++) {
      int timeToKill = health[i] / power + (health[i] % power > 0);
      enemies.emplace_back(damage[i], timeToKill);
    }

    sort(enemies.begin(), enemies.end(),
         [](pair<int, int> &a, pair<int, int> &b) -> bool {
           return a.first * b.second > b.first * a.second;
         });

    long long totalDamage = 0;

    for (int i = 0; i < n; i++) {
      int damage = enemies[i].first;
      int time = enemies[i].second;

      totalDamage += sumDamage * time;
      sumDamage -= damage;
    }

    return totalDamage;
  }
};