#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {

        int low = 1, high = 1000, ans = 1000;

        while (low <= high)
        {
            int mid = (low + high) >> 1;
            cout << "? " << 1 << " " << mid << endl;
            cout.flush();
            int k;
            cin >> k;
            if (k == mid + 1)
            {
                ans = mid;
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        cout << "! " << ans << endl;
    }
}