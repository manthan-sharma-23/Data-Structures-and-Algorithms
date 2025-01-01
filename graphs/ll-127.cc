#include <queue>
#include <set>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {

    set<string> s(wordList.begin(), wordList.end());

    if (s.find(endWord) == s.end())
      return 0;

    s.insert(beginWord);
    queue<string> q;

    q.push(beginWord);
    int depth = 1;

    while (!q.empty()) {
      int size = q.size();

      for (int i = 0; i < size; i++) {
        string top = q.front();
        q.pop();

        for (int j = 0; j < top.length(); j++) {
          char originalChar = top[j];
          for (char c = 'a'; c <= 'z'; c++) {
            if (c == originalChar)
              continue;

            top[j] = c;

            if (top == endWord)
              return depth + 1;

            if (s.find(top) != s.end()) {
              q.push(top);
              s.erase(top);
            }
          }
          top[j] = originalChar;
        }
      }

      depth++;
    }

    return 0;
  }
};