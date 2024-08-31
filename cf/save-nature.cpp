#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool solve(ll k, vector<ll> &arr, ll m, ll x, ll y, ll a, ll b)
{
    ll temp = (a * b) / __gcd(a, b);

    ll res = 0;

    int j = 0;
    
    for ( auto i = 0; i <= m; i++ ) {
        if ( (i+1)%temp == 0 ) {
            res += (arr[j]/100)*(x + y);
            j++;
        }
    }

    for ( auto i = 0; i <= m; i++ ) {
        if ( (i+1)%temp != 0 && ( i+1)%a == 0 ) {
            res += (arr[j]/100)*x;
            j++;
        }
    }

    for ( auto i = 0; i <= m; i++ ) {
        if ( (i+1)%temp != 0 && (i+1)%b == 0 ) {
            res += (arr[j]/100)*y;
            j++;
        }
    }

    return (res >= k);
}

int main()
{
    ll t;
    cin >> t;
    while (t)
    {
        ll n;
        cin >> n;
        vector<ll> arr(n);

        for (auto i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        ll x, a, y, b;
        cin >> x >> a >> y >> b;
        ll k;
        cin >> k;

        if (x < y)
        {
            swap(x, y);
            swap(a, b);
        }

        sort(arr.rbegin(), arr.rend());

        ll low = 0, high = n - 1;
        int res = -1;

        while (low <= high)
        {
            ll mid = (low + high) / 2;

            if (solve(k, arr, mid, x, y, a, b))
            {
                high = mid - 1;
                res = mid + 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << res << endl;

        t--;
    }
    return 0;
}