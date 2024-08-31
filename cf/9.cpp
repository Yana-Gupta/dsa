#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> heap(n);
        for (int i = 0; i < n; i++)
            cin >> heap[i];
        
        auto possible = [&](int x)
        {
            vector<int> a = heap;
            for (int i = n - 1; i >= 2; i--)
            {
                if (a[i] < x)
                    return false;
                
                int y = (a[i] - x) / 3;
                y = min(y, (heap[i] / 3));

                a[i - 1] += y;
                a[i - 2] += 2 * y;
            }
            return a[0] >= x && a[1] >= x;
        };

        int low = 0, high = 1e9, ans = 0;

        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (possible(mid))
            {
                ans = mid;
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }

        cout << ans << endl;
    }
}
