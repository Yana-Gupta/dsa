// https://codeforces.com/contest/876/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    ll n, k, m;
    cin >> n >> k >> m;
    vector<ll> a(n);
    for (auto i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    vector<vector<ll>> v(m);
    int idx = -1;

    for (auto i = 0; i < n; i++)
    {
        if (idx != -1)
        {
            break;
        }

        v[a[i] % m].push_back(a[i]);
        if (v[a[i] % m].size() == k)
            idx = a[i] % m;
    }

    if (idx == -1)
    {
        cout << "No" << endl;
    }
    else
    {
        cout << "Yes" << endl;
        for (auto i = 0; i < v[idx].size(); i++)
        {
            cout << v[idx][i] << " ";
        }
        cout << endl;
    }
}