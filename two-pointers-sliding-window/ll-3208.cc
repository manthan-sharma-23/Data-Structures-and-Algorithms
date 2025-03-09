#include <vector>

using namespace std;

class Solution {
public:
  int numberOfAlternatingGroups(vector<int> &colors, int k) {

    int c = k;
    for (int i = colors.size() - 1; i > 0 && c > 0; i--) {
      colors.insert(colors.begin(), colors[i]);
      c--;
    }


    
  }
};