#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int target;
    cin >> target;

    int l = 0, h = n - 1;

    while (l <= h)
    {
        int mid = (l + h) >> 1;

        if (a[mid] == target)
        {
            cout << mid << endl;
            return 0;
        }

        if (a[mid] < target)
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }

    cout << -1 << endl;

    return 0;
}
