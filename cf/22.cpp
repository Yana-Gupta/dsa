#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    ll n;
    cin >> n;

    ll low = 1, high = n;

    while (low < high && (high - low >= 2))
    {
        ll mid = (low + high) >> 1;
        cout << "? " << low << " " << high << endl;
        int smax;
        cin >> smax;
        if ( smax < mid  ) {
            cout << "? " << low << " " << mid - 1 << endl;
            int m1;
            cin >> m1;
            if ( smax == m1 ) {
                high = mid - 1;
            } else {
                low = mid;
            }
        } else {
            cout << "? " << mid << " " << high << endl;
            int m1;
            cin >> m1;
            if ( smax == m1  ) {
                low = mid;
            } else {
                high = mid - 1;
            }
        }
    }

    cout << "! " << low << endl;

}

// 5 1 2 3 4 