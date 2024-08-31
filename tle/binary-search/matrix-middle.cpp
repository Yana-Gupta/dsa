#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool cnt(ll c, ll n)
{
    ll total = 0;
    for (ll i = 1; i <= n; i++)
    {
        total += min(n, c / i);
    }

    return total >= ((n * n) / 2) + 1;
}

int main()
{
    ll n;
    cin >> n;

    ll low = 1, high = n * n;
    ll res = 0;

    while (low <= high)
    {
        ll mid = (low + high) / 2;

        if (cnt(mid, n))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << res << endl;
    return 0;
}
