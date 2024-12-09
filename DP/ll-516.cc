#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
    unordered_map<string, int> memo;

    int dfs(string s)
    {
        if (memo.find(s) != memo.end())
            return memo[s];
        if (s.length() == 1)
        {
            return memo[s] = 1;
        }
        if (s.empty())
        {
            return memo[s] = 0;
        }

        if (s[0] == s[s.length() - 1])
        {

            return memo[s] = 2 + dfs(s.substr(1, s.length() - 2));
        }
        else
        {
            return memo[s] =
                       max(dfs(s.substr(1)), dfs(s.substr(0, s.length() - 1)));
        }
    }

public:
    int longestPalindromeSubseq(string s)
    {
        return dfs(s);
    }
};

int main()
{
    Solution s;
    auto l = s.longestPalindromeSubseq("bbbab");
    cout << l << endl;
}