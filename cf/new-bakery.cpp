#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t)
    {
        ll n, a, b;
        cin >> n >> a >> b;

        ll k = b - a + 1;
        k = max(1LL, k);
        k = min(k, n + 1);

        cout << ((n - k + 1) * a + (k-1) * b - (k - 2) * (k - 1) / 2) << endl;

        t--;
    }
}