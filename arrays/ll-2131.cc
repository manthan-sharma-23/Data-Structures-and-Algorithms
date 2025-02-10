#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
  int longestPalindrome(vector<string> &words) {
    unordered_map<string, int> wordCount;
    unordered_map<string, int> middles;

    for (auto &word : words) {
      if (word[0] == word[1]) {
        middles[word]++;
      } else {
        wordCount[word]++;
      }
    }

    int wordL = 0;

    for (auto it = wordCount.begin(); it != wordCount.end();) {
      string word = it->first;
      int freq = it->second;

      string rev = word;
      reverse(rev.begin(), rev.end());

      if (wordCount.find(rev) != wordCount.end()) {
        wordL += min(wordCount[rev], freq) * 4;
      }

      wordCount.erase(rev);
      it = wordCount.erase(it);
    }

    int middleL = 0;
    bool mid = false;

    for (auto &it : middles) {
      int freq = it.second;

      middleL += (freq / 2) * 4;

      if (freq % 2 != 0) {
        mid = true;
      }
    }

    return middleL + wordL + (mid ? 2 : 0);
  }
};
