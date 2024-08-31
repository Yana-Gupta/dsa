#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    ll t;
    cin >> t;
    while (t--)
    {

        ll n, k;
        cin >> n;
        vector<ll> a(n);
        for (auto i = 0; i < n; i++)
            cin >> a[i];

        vector<ll> pre(n + 1);
        for (auto i = 1; i <= n; i++)
        {
            pre[i] += pre[i - 1] + a[i - 1];
        }

        ll low = 0, high = n - 1, ans = 0;
        while (low <= high)
        {
            ll mid = (low + high) >> 1;
            cout << "? " << mid - low + 1 << " ";
            for ( auto i = low; i <= mid; i++ ) cout << i + 1 << " ";

            cout.flush();
            cout << endl;
            ll k;
            cin >> k;

            if (k > pre[mid + 1] - pre[low])
            {
                ans = mid + 1;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << "! " << ans << endl;
    }
}