#include <bits/stdc++.h>

using namespace std;

void findS(vector<int> &sums, int index, int sum, vector<int> &arr, int size)
{
    if (index == size)
    {
        sums.push_back(sum);
        return;
    }

    findS(sums, index + 1, sum + arr[index], arr, size);

    findS(sums, index + 1, sum, arr, size);
}

void print1D(vector<int> v)
{
    for (int i : v)
    {
        cout << i << " ";
    }

    cout << endl;
}

vector<int> subsetSums(vector<int> &arr, int n)
{
    vector<int> sums;
    int sum;

    findS(sums, 0, sum, arr, n);
    print1D(sums);
    return sums;
}

int main()
{
    vector<int> a = {2, 3};
    subsetSums(a, a.size());
    return 0;
}