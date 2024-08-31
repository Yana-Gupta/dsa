#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t)
    {
        int n;
        cin >> n;
        int l = 1, r = n;

        while (l < r)
        {
            int mid = (l + r) >> 1;

            cout << "? " << l << " " << mid << endl;

            int t = mid - l + 1;

            int cnt = 0;

            for (auto i = 0; i < t; i++)
            {
                int k;
                cin >> k;
                if (k >= l && k <= mid)
                    cnt++;
            }

            if (cnt % 2)
            {
                r = mid;
            }
            else
            {
                l = mid + 1;
            }
        }

        cout << "! " << l << endl;
        t--;
    }
}