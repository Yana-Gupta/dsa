#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto i = 0; i < n; i++)
        cin >> a[i];
    ll res = 0;

    map<int, int> mp;
    int i = 0, j = 0;
    while (j < n)
    {
        mp[a[j]]++;
        while (mp.size() > k && i <= j)
        {
            mp[a[i]]--;
            if (mp[a[i]] == 0)
                mp.erase(a[i]);
            i++;
        }



        res += (j + 1 - i);
        j++;
    }
    cout << res << endl;
}