#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll t;
    cin >> t;
    while (t)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        int ele0 = 0;

        int minbefore = INT_MAX;

        bool foundpartion = false;
        bool done = false;

        for (auto i = 0; i < n; i++)
            cin >> a[i];

        int minele = a[0];
        int i = 1;
        for (; i < n && a[i] > a[i - 1]; i++)
        {
            minele = min(minele, a[i]);
        }

        if (i == n)
            cout << "yes" << endl;
        else
        {
            for (; i < n && a[i] <= minele; i++);

            if (i == n)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
        }
        t--;
    }
}