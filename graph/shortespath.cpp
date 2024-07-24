#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    int nodes = 4;
    vector<int> g_from = {0, 1, 3};
    vector<int> g_to = {1, 2, 0};
    vector<int> cost = {13, 21, 31};

    vector<vector<int>> dp(4, vector<int>(4, 1e9));
    for (auto i = 0; i < 3; i++)
    {
        dp[g_from[i]][g_to[i]] = cost[i];
        dp[g_to[i]][g_from[i]] = cost[i];
    }

    for (auto k = 0; k < 4; k++)
    {
        for (auto i = 0; i < 4; i++)
        {
            for (auto j = 0; j < 4; j++)
            {
                if (dp[i][j] > (dp[i][k] + dp[k][j]) && (dp[k][j] != 1e9 && dp[i][k] != 1e9))
                    dp[i][j] = dp[i][k] + dp[k][j];
            }
        }
    }

    vector<pair<int, int>> queries = {{0, 1},
                                      {1, 3},
                                      {2, 0},
                                      {2, 3}};

    for (auto q : queries)
    {
        cout << dp[q.first][q.second] << " ";
    }

    cout << endl;
}