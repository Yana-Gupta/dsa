// https://codeforces.com/problemset/problem/812/C

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll check(ll k, ll s, const vector<ll> &a)
{
    if (k == 0)
        return 0;
    ll total = 0;
    priority_queue<ll, vector<ll>, greater<>> minpq;
    for (auto i = 0; i < a.size(); i++)
        minpq.push(a[i] + (i + 1) * k);

    ll j = 0;
    while (j < k)
    {
        total += minpq.top();
        minpq.pop();
        j++;
    }

    return total <= s ? total : -1;
}

// 14 + 55 + 5 + (3 + 4 + 5)*3
// 74 + 12*3
// 74 + 36 =
int main()
{
    ll n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (auto i = 0; i < n; ++i)
        cin >> a[i];

    ll low = 0, high = n, ans = 0, total = 0;

    while (low <= high)
    {
        ll mid = (low + high) / 2;
        ll sum = check(mid, s, a);
        if (sum != -1)
        {
            total = sum;
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << " " << total << endl;
}
