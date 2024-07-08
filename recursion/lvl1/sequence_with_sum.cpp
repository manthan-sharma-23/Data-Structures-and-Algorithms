#include <bits/stdc++.h>

using namespace std;
int M = 1e9 + 7;

void findSubsets(int arr[], int &temp, int index, int sum, int &count)
{

    if (index == sizeof(arr))
    {
        if (temp == sum)
        {
            ++count;
                }
        return;
    }

    temp += arr[index];
    findSubsets(arr, temp, index + 1, sum, count);
    temp -= arr[index];
    findSubsets(arr, temp, index + 1, sum, count);
}

int perfectSum(int arr[], int n, int sum)
{
    int temp = 0, index = 0, count = 0;
    findSubsets(arr, temp, index, sum, count);

    return count % M;
}

int main()
{
    int arr[] = {9, 7, 0, 3, 9, 8, 6, 5, 7, 6};

    int c = perfectSum(arr, sizeof(arr), 10);
    cout << c << endl;

    return 0;
}