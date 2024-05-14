#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void explorePair()
{
    pair<int, int> p = {1, 2};

    cout << p.first << " " << p.second << endl;

    pair<int, pair<int, bool>> p2 = {1, {2, false}};

    cout << p2.first << " " << p2.second.second << endl;
}

int main(void)
{

    explorePair();
}