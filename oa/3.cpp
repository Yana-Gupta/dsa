#include <bits/stdc++.h>
using namespace std;

int solve1(int *v, int n)
{
    int ans = 0;
    int left = 0;
    int right = 1;
    while (right < n)
    {
        if (v[left] < v[right])
        {
            ans = max(ans, v[right] - v[left]);
        }
        else
        {
            left = right;
        }

        right++;
    }
    return ans;
}

int dp[101][101][101];

int solve(vector<int> &v, int w, int r, int idx, bool u)
{
    if (idx == v.size())
    {
        if (w == 0 && r == 0)
            return 0;
        return (w > 0) + (r > 0);
    }

    if (dp[idx][w][r] != -1)
        return dp[idx][w][r];

    int res = INT_MAX / 2;

    if (v[idx] == 0)
    {
        int cnt = 0;
        int i;
        for (i = idx; i < v.size(); i++)
        {
            if (v[i] == 0)
                cnt++;
            else
                break;
        }
        int t = INT_MAX / 2;
        if (u)
        {
            t = 1 + solve(v, 0, r, i, false);
            t = min(t, 1 + solve(v, w, 0, i, true));
        }
        else
        {
            t = min(t, 1 + solve(v, w + cnt, 0, i, true));
            t = min(t, 1 + solve(v, min(cnt, w), r, i, false));
        }

        res = min(res, t);
    }

    if (v[idx] == 1)
    {
        int cnt = 0;
        int i;
        for (i = idx; i < v.size(); i++)
        {
            if (v[i] == 1)
                cnt++;
            else
                break;
        }

        int t = INT_MAX/2;

        if ( u ) {
            t = 1 + solve(v, 0, r + cnt, i, false);
            t = min(t, 1 + solve(v, w, min(cnt, r), i, true));
        } else {
            t = min(t, 1 + solve(v, w, 0, i, true));
            t = min(t, 1 + solve(v, 0, r + cnt, i, false));
        }
        res = min(res, t);
    }

    return dp[idx][w][r] = res;
}

int main()
{
    int n;
    cin >> n;
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    // Initialize dp array with -1
    memset(dp, -1, sizeof(dp));

    // Call solve function with initial parameters
    int result = solve(v, 0, 0, 0, false);

    // Output the result
    cout << (result == INT_MAX / 2 ? -1 : result) << endl;

    return 0;
}
