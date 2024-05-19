#include <bits/stdc++.h>

using namespace std;

int maxNumber(vector<int> &arr)
{
    int maxi = INT_MIN;
    for (int n : arr)
    {
        maxi = max(n, maxi);
    }

    return maxi;
}

bool divisorCheck(vector<int> v, int divisor, int thresh)
{
    int sum = 0;
    for (int n : v)
    {
        sum += ceil(n / divisor);
    }
    return sum <= thresh;
}

int divisorFindBruteForce(vector<int> arr, int thresh)
{
    int n = arr.size();
    int maxN = maxNumber(arr);
    int low = 0, high = maxN;

    for (int i = low; i <= high; i++)
    {
        if (divisorCheck(arr, i, thresh))
        {
            return i;
        }
    }
}

int main()
{
    return 0;
}