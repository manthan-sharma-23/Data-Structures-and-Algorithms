#include <bits/stdc++.h>

using namespace std;

// 000
void seeCode(string &s, int k)
{
    if (s.length() == k)
    {
        cout << s << endl;
        return;
    }

    s.push_back('0');
    seeCode(s, k);
    s.pop_back();

    if (s.empty() || s.back() != '1')
    {
        s.push_back('1');
        seeCode(s, k);
        s.pop_back();
    }
}

void stringCode(int k)
{
    string s = "";
    seeCode(s, k);
}

int main()
{
    stringCode(5);

    return 0;
}