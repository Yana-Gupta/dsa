#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;
    while (t--) {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n), h(n);
        for (auto i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (auto i = 0; i < n; i++) {
            cin >> h[i];
        }

        int res = 0;

        ll sum = a[0];
        res = (sum <= k);
        int i = 1;
        int j = 0;

        while (i < n) {
            if (h[i - 1] % h[i] == 0)
                sum += a[i];
            else {
                sum = a[i];
                j = i;
            }

            while (sum > k) {
                sum -= a[j];
                j++;
            }

            res = max(res, i - j + 1);
            i++;
        }

        cout << res << endl;
    }
}