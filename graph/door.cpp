#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> arr = {2, 4, 4, 2};
    int allowedGap = 4;
    int length = 45;
    vector<int> arr1;
    vector<vector<int>> dp(100000, vector<int>(1000, 1000000));

    for (auto i = 0; i < arr.size(); i++)
    {
        arr1.push_back(arr[i]);
        arr1.push_back(1e9);
    }

    arr1.pop_back();

    dp[0][0] = max(0, length - arr1[0]);
    dp[0][1] = 0;

    for (auto i = 1; i < arr1.size(); i++)
    {
        int res = max(0, length - arr1[i]);
        for (auto gap = 0; gap <= allowedGap; gap++)
        {
            dp[i][gap] = min(dp[i][gap], dp[i - 1][gap] + res);
            dp[i][gap + 1] = min(dp[i][gap + 1], dp[i - 1][gap]);
        }
    }

    for (auto i = 0; i < arr1.size(); i++)
    {
        for (auto j = 0; j < allowedGap; j++)
        {
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}