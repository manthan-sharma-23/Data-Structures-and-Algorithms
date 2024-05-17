#include <bits/stdc++.h>

using namespace std;

// Find the index of Integer just greater than x
int upperBoundOptimal(vector<int> v, int x)
{
    int n = v.size();
    int low = 0, high = n - 1;

    while (low <= high)
    {
        for (int i = 0;
             i < n;
             i++)
        {
            int mid = low + (high - low) / 2;
        }
    }

    return high;
}

int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 5, 6, 7};
    return 0;
}