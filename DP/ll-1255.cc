#include <cstring>
#include <vector>

#include <string>

using namespace std;

class Solution {
public:
  int n;
  int freq[26];
  int values[26];

  vector<string> Words;

  int f(int i) {
    if (i == n)
      return 0;

    string word = Words[i];

    int notTake = f(i + 1);

    int take = 0;
    bool canTake = true;

    vector<int> word_freq(26, 0);

    for (auto c : word) {
      word_freq[c - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
      if (freq[i] < word_freq[i]) {
        canTake = false;
        break;
      }
    }

    if (canTake) {
      int score = 0;
      for (char c : word) {
        int i = c - 'a';
        freq[i]--;
        score += values[i];
      }
      take = score + f(i + 1);
      for (char c : word) {
        int i = c - 'a';
        freq[i]++;
      }
    }

    return max(take, notTake);
  }

  int maxScoreWords(vector<string> &words, vector<char> &letters,
                    vector<int> &score) {
    n = words.size();
    Words = words;

    memset(freq, 0, sizeof(freq));

    for (const char &letter : letters) {
      int i = letter - 'a';
      freq[i]++;
    }

    for (int i = 0; i < 26; i++) {
      values[i] = score[i];
    }

    return f(0);
  }
};