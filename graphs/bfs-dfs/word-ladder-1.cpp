#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    queue<string> q;
    q.push(beginWord);
    unordered_set<string> st(wordList.begin(), wordList.end());

    st.erase(beginWord);
    int pass = 1;

    while (!q.empty()) {
      int size = q.size();

      while (size--) {
        string word = q.front();
        if (word == endWord) {
          return pass;
        }
        q.pop();

        for (int i = 0; i < word.length(); i++) {
          char original = word[i];
          for (char ch = 'a'; ch <= 'z'; ch++) {
            word[i] = ch;
            if (st.find(word) != st.end()) {
              st.erase(word);
              q.push(word);
            }
          }
          word[i] = original;
        }
      }
      pass++;
    }

    return 0;
  }
};
