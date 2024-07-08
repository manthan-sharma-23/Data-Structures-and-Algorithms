#include <bits/stdc++.h>

using namespace std;

void countSequence(string str1, int index, set<string> &s, string &example)
{
    if (index == str1.size())
    {
        s.insert(example);
        cout << example << endl;
        return;
    }

    example.push_back(str1[index]);
    countSequence(str1, index + 1, s, example);
    example.pop_back();
    countSequence(str1, index + 1, s, example);
}

string betterString(string str1, string str2)
{
    int c_1 = 0, c_2 = 0;
    int index = 0;
    string e_1 = "", e_2 = "";
    set<string> mp;

    countSequence(str1, index, mp, e_1);
    c_1 = mp.size();
    mp.clear();
    countSequence(str2, index, mp, e_2);
    c_2 = mp.size();

    if (c_2 > c_1)
    {
        return str2;
    }

    return str1;
}

int main()
{
    string better = betterString("ggg", "gfg");

    cout << better << endl;
    return 0;
}