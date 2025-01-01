#include <algorithm>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class GFG_Solution {
public:
  vector<vector<string>> findSequences(string beginWord, string endWord,
                                       vector<string> &wordList) {
    set<string> s(wordList.begin(), wordList.end());
    vector<vector<string>> res;

    if (s.find(endWord) == s.end())
      return res;

    s.insert(beginWord);
    queue<vector<string>> q;

    set<string> visited;

    q.push({beginWord});
    bool found = false;
    while (!q.empty()) {
      int size = q.size();
      visited.clear();

      for (int i = 0; i < size; i++) {
        auto vc = q.front();
        string top = vc.back();
        q.pop();

        for (int j = 0; j < top.length(); j++) {
          char originalChar = top[j];
          for (char c = 'a'; c <= 'z'; c++) {
            if (c == originalChar)
              continue;

            top[j] = c;

            if (top == endWord) {
              found = true;
              vc.push_back(endWord);
              res.push_back(vc);
              vc.pop_back();
            }

            if (s.find(top) != s.end()) {
              vc.push_back(top);
              visited.insert(top);
              q.push(vc);
              vc.pop_back();
            }
          }
          top[j] = originalChar;
        }
      }

      for (auto &word : visited) {
        s.erase(word);
      }

      if (found)
        break;
    }

    return res;
  }
};

class LC_Solution {
private:
  unordered_map<string, int> mpp;
  vector<vector<string>> res;
  string B;

  void dfs(vector<string> &path, string word) {
    if (word == B) {
      reverse(path.begin(), path.end());
      res.push_back(path);
      reverse(path.begin(), path.end());
      return;
    }
    int steps = mpp[word];

    for (int i = 0; i < word.length(); i++) {
      char originalChar = word[i];
      for (char c = 'a'; c <= 'z'; c++) {
        word[i] = c;

        if ((mpp.find(word) != mpp.end()) && (mpp[word] + 1 == steps)) {
          path.push_back(word);

          dfs(path, word);

          path.pop_back();
        }
      }

      word[i] = originalChar;
    }
  }

public:
  vector<vector<string>> findLadders(string beginWord, string endWord,
                                     vector<string> &wordList) {

    set<string> s(wordList.begin(), wordList.end());

    queue<string> q;
    B = beginWord;

    mpp[B] = 1;
    q.push(B);
    s.erase(B);

    while (!q.empty()) {
      auto word = q.front();
      q.pop();
      int steps = mpp[word];

      for (int i = 0; i < word.length(); i++) {
        char originalChar = word[i];
        for (char c = 'a'; c <= 'z'; c++) {
          word[i] = c;

          if (s.count(word)) {
            mpp[word] = steps + 1;
            q.push(word);
            s.erase(word);
          }
        }
        word[i] = originalChar;
      }
    }

    if (mpp.find(endWord) != mpp.end()) {
      vector<string> path;
      path.push_back(endWord);
      dfs(path, endWord);
    }

    return res;
  }
};