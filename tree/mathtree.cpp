// A tree
// a node has some value and it has as much children as the value

// value starts from 1 ( root )

// Given 2 <= n <= 1e9

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<ll, ll> endstr;

void calc(ll n)
{
    if (n >= 9)
        return;

    ll s = endstr[n - 1] + 1;
    ll calcsum = (endstr[n - 1]) * (endstr[n - 1] + 1) / 2 - (endstr[n - 2] + 1) * (endstr[n - 2]) / 2;
    ll e = endstr[n - 1] + calcsum;

    endstr[n] = e;

    calc(n + 1);
}

ll solve1(ll s, ll e, ll westart, ll n)
{
    ll l = s, h = e;
    ll res = l;
    while (l <= h)
    {
        ll mid = (l + h) >> 1;
        // sum over s to mid
        // mid*(mid + 1)/2 - (s)*(s-1)/2
        // if the value is less than n then s = mid + 1;
        // else h = mid - 1;
        if (westart + mid * (mid + 1) / 2 - (s) * (s - 1) / 2 < n)
        {
            l = (mid + 1);
        }
        else
        {
            res = mid;
            h = mid - 1;
        }
    }

    return res;
}

ll solve(ll n)
{
    if (n == 2)
        return 1;
    ll i = 2;
    for (i = 2; i < 9; i++)
    {
        if (endstr[i] >= n)
            break;
    }

    // i represent the right depth
    // one depth before we have the parent
    // means need to search at d - 1

    // at d - 2 depth we will get the endstr
    ll d = i;

    ll s = endstr[d - 2] + 1;
    ll e = endstr[d - 1];

    ll westart = e + 1;
    return solve1(s, e, westart, n);
}

int solve2(int n)
{
    int sum = 0;
    for (int i = 1;; i++)
    {
        sum += i;
        if (n <= sum + 1)
            return i;
    }
}

int main()
{
    endstr[1] = 1;
    calc(2);
    // for (auto i = 1; i <= 8; i++)
        // cout << endstr[i] << endl;

    cout << solve(10000000) << endl;
    cout << solve2(10000000) << endl;

    cout << solve(13) << endl;
    cout << solve2(13) << endl;

    cout << solve(18) << endl;
    cout << solve2(18) << endl;

    cout << solve(11) << endl;
    cout << solve2(11) << endl;

    cout << solve(221) << endl;
    cout << solve2(221) << endl;

    cout << solve(2314) << endl;
    cout << solve2(2314) << endl;

    cout << solve(13214) << endl;
    cout << solve2(13214) << endl;

    cout << solve(3212141) << endl;
    cout << solve2(3212141) << endl;
}