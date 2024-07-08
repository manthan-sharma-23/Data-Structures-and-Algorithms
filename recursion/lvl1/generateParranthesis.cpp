#include <bits/stdc++.h>

using namespace std;

void MakeStrings(vector<string> &r, string &s, int n, int &o)
{
    if (s.size() == 2 * n)
    {
        cout << s << endl;
        r.push_back(s);
        return;
    }

    if (o < 2 * n - s.size())
    {
        s.push_back('(');
        ++o;
        MakeStrings(r, s, n, o);
        s.pop_back();
        --o;
    }

    if (o > 0)
    {

        s.push_back(')');
        --o;
        MakeStrings(r, s, n, o);
        s.pop_back();
        ++o;
    }
}

vector<string> generateParenthesis(int n)
{
    string s;
    vector<string> result;
    int open = 0;
    MakeStrings(result, s, n, open);

    return result;
}

int main()
{
    generateParenthesis(3);
    return 0;
}