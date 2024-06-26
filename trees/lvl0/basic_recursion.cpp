#include <bits/stdc++.h>

using namespace std;

void recurs(int n)
{
    if (n < 0)
    {
        return;
    }
    cout << n << endl;

    recurs(--n);
    recurs(n-2);
}

int main()
{
    recurs(16);
    return 0;
}