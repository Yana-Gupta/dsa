#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (auto i = 0; i < n; i++)
        cin >> a[i];
    for (auto i = 0; i < m; i++)
        cin >> b[i];

    int i = 0, j = 0;
    ll ans = 0;
    while (i < n && j < m)
    {
        int val = a[i];
        if (a[i] == b[j])
        {
            int cnt = 0, cnt2 = 0;
            while (j < m && val == b[j])
            {
                cnt++, j++;
            }

            while (i < n && val == a[i])
            {
                cnt2++, i++;
            }
            ans += ((ll)cnt) * ((ll)cnt2);
        }
        else if (a[i] > b[j])
            j++;
        else
            i++;
    }

    cout << ans << endl;
}