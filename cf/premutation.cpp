#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int t;
    cin >> t;

    while (t) {
        ll n, s;
        cin >> n >> s;
        ll ms = 0;
        ll l = n - 1;
        while (l > 0) {
            ms += 2 * (l);
            l -= 2;
        }
        if (s % 2 == 1 || s > ms) {
            cout << "no" << endl;
        }
        else {
            vector<ll> res(n + 1);
            ll last = n;

            for (ll i = 1; i <= n && s; i++) {
                if (res[i])
                    continue;

                ll temp = s / 2;

                temp = min(i + temp, last);

                res[i] = temp;
                res[temp] = i;

                last = temp - 1;

                s -= 2 * (temp - i);
            }

            cout << "yes" << endl;

            for (ll i = 1; i <= n; i++) {
                if (res[i] == 0)
                    cout << i << " ";
                else
                    cout << res[i] << " ";
            }
            cout << endl;
        }

        t--;
    }
}