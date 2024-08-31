#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool ok(ll opr, vector<ll> &a, ll sum, ll k)
{
    if (sum - k <= opr)
        return true;

    ll n = a.size();
    ll cur_sum = sum;
    
    // Try to maximize the elements you can remove
    for (int i = n - 1; i >= 0 && opr > 0; --i)
    {
        ll remove_amount = a[i];
        cur_sum -= remove_amount;
        opr--;
        
        // Check if current sum after removing this element satisfies the condition
        if (cur_sum - k <= opr)
            return true;
    }
    
    return false;
}

int main()
{
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        ll sum = 0;
        for (auto i = 0; i < n; i++)
            cin >> a[i], sum += a[i];

        sort(a.begin(), a.end());
        ll low = 0, high = n, ans = n;

        while (low <= high)
        {
            ll mid = (low + high) / 2;

            if (ok(mid, a, sum, k))
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        cout << ans << endl;
    }
}
