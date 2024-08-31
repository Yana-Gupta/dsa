#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        ll n, k, d;
        cin >> n >>k >> d;

        vector<ll> a(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        unordered_map<ll, int> mp;
        ll res = k;

        int i = 0, j = 0;
        while (j < n)
        {
            mp[a[j]]++;
            if (j - i + 1 == d)
            {
                res = min(res, (ll)mp.size());
                mp[a[i]]--;
                if (mp[a[i]] == 0)
                {
                    mp.erase(a[i]);
                }
                i++;
            }
            j++;
        }
        cout << res << endl;
    }
}
