#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;
class Solution {
public:
  int minMutation(string startGene, string endGene, vector<string> &bank) {
    set<string> s(bank.begin(), bank.end());
    char possibleMutation[4] = {'A', 'C', 'G', 'T'};

    if (s.find(endGene) == s.end())
      return -1;

    queue<string> q;
    q.push(startGene);

    int depth = 0;
    while (!q.empty()) {
      int size = q.size();

      for (int level = 0; level < size; level++) {
        string top = q.front();
        q.pop();

        for (int i = 0; i < top.size(); i++) {
          char originalChar = top[i];

          for (int j = 0; j < 4; j++) {
            if (originalChar == possibleMutation[j])
              continue;
            top[i] = possibleMutation[j];

            if (top == endGene) {
              return depth + 1;
            }

            if (s.find(top) != s.end()) {
              q.push(top);
              s.erase(top);
            }
          }

          top[i] = originalChar;
        }
      }
      depth++;
    }

    return -1;
  }
};