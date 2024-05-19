#include <bits/stdc++.h>

using namespace std;

int sqrt(int x)
{
    int low = 0, high = x;

    while (low <= high)
    {
        long long mid = low + (high - low) / 2;
        long long sqr = mid * mid;

        if (sqr <= (long long)(x))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    return high;
}

int main()
{
    return 0;
}