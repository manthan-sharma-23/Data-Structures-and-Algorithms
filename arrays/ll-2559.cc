#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool is_vowel(string s) {
    int n = s.length();

    if ((s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' ||
         s[0] == 'u') &&
        (s[n - 1] == 'a' || s[n - 1] == 'e' || s[n - 1] == 'i' ||
         s[n - 1] == 'o' || s[n - 1] == 'u'))
      return true;

    return false;
  }

  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {

    int q = queries.size();
    int w = words.size();

    vector<int> res(q);
    vector<int> cummSum(w);

    cummSum[0] = is_vowel(words[0]) ? 1 : 0;
    for (int i = 1; i < w; i++) {
      cummSum[i] = is_vowel(words[i]) ? cummSum[i - 1] + 1 : cummSum[i - 1];
    }

    for (int i = 0; i < q; i++) {
      int l = queries[i][0];
      int r = queries[i][1];

      res[i] = cummSum[r] - (l > 0 ? cummSum[l - 1] : 0);
    }

    return res;
  }
};