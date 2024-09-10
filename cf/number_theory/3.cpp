// https://codeforces.com/problemset/problem/1458/A

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll gcd(ll a, ll b)
{
    if (b > a)
        swap(a, b);

    if (b != 0)
    {
        return gcd(b, a % b);
    }

    return a;
}

int main()
{
    ll n, m;
    cin >> n >> m;

    vector<ll> a(n), b(m);
    for (auto i = 0; i < n; i++)
        cin >> a[i];
    for (auto i = 0; i < m; i++)
        cin >> b[i];

    if ( n == 1 ) {
        for ( auto i = 0; i < m; i++ ) {
            cout << a[0] + b[i] << " ";
        }
        cout << endl;
        return 0;
    }

    ll last = abs(a[1] - a[0]);
    for (auto i = 2; i < n; i++)
    {
        last = gcd(last, abs(a[i] - a[i - 1]));
    }

    for (auto i = 0; i < m; i++)
    {
        cout << gcd(last, abs(a[0] + b[i])) << " ";
    }
    cout << endl;
}