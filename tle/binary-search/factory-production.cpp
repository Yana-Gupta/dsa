#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isfine(ll t, vector<ll> &mac, ll n)
{
    ll res = 0;
    for (ll i = 0; i < mac.size(); i++)
    {
        res += ll(t / mac[i]);
    }

    return (res >= n);
}

int main()
{
    ll n, t;
    cin >> n >> t;

    vector<ll> mac(n);
    for (ll i = 0; i < n; i++)
        cin >> mac[i];

    ll low = 0;

    ll high = (ll(*min_element(mac.begin(), mac.end()))) * t;

    ll res = 0;

    while (low <= high)
    {
        ll mid = (low + high) >> 1;
        if (isfine(mid, mac, t))
        {
            high = mid - 1;
            res = mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << res << endl;
}