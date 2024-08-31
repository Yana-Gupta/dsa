#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t)
    {

        ll n, c;
        cin >> n >> c;

        ll max_votes = 0;

        vector<ll> a(n);

        int smallestidx = 0;

        for (auto i = 0; i < n; i++)
        {
            cin >> a[i];
            if (max_votes < a[i]) {

                max_votes = a[i];
                smallestidx = i;
            }
        }

        if (a[0] + c >= max_votes) {

            max_votes = a[0] + c;
            smallestidx = 0;
        }

        vector<ll> pref(n + 1, 0);
        pref[0] = c;
        
        for (auto i = 0; i < n; i++)
        {
            pref[i + 1] = pref[i] + a[i];

            if (a[i] >= max_votes && i == smallestidx) {
                cout << 0 << " ";
            }

            else if (pref[i + 1] < max_votes)
                cout << i + 1 << " ";
            else
                cout << i << " ";
        }

        cout << endl;

        t--;
    }
}
