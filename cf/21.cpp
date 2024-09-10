#include<bits/stdc++.h>

using namespace std;


int main ( ) {
    int n, t;
    cin >> n >> t;
    int k;
    cin >> k;

    int low = 1, high = n, ans = n;

    while ( low <= high ) {
        int mid = ( low + high ) >> 1;
        cout << "? " << 1 << " " << mid << endl;
        int cnt;
        cin >> cnt;
        if ( cnt > mid - k ) {
            low = mid + 1;
        } else {
            high = mid - 1;
            ans = mid;
        }
    }

    cout << "! " << ans << endl;
}