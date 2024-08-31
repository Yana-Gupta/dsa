#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    ll n, p;
    cin >> n >> p;
    vector<ll> a(n);
    for (auto i = 0; i < n; i++)
        cin >> a[i];
    ll sum = accumulate(a.begin(), a.end(), 0LL);

    ll idx = 0, res = 0;

    if (p > 2*sum)
    {
        res = ((p - sum) / sum) * n;
        p = sum  + (p) % sum;
    }
    a.resize(2 * n);
    for (auto i = 0; i < n; i++)
    {
        a[i + n] = a[i];
    }

    ll cs = 0;
    ll i = 0, j = 0;

    ll r2 = 2 * n;

    while (j < (2 * n))
    {
        cs += a[j];
        while ((cs - a[i]) >= p)
        {
            cs -= a[i];
            i++;
        }

        if (cs >= p)
        {
            if ((j - i + 1) < r2)
            {
                r2 = j - i + 1;
                idx = i + 1;
            }
        }
        j++;
    }

    cout << idx << " " << (res + r2) << endl;
}