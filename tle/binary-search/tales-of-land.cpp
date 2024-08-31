// https://codeforces.com/problemset/problem/1166/C

#include<bits/stdc++.h>

using namespace std;



int main () {
    int n;
    cin >> n;
    vector<int> a(n);

    for ( auto i = 0; i < n; i++ ) {
        cin >> a[i];
        a[i] = abs(a[i]);
    }

    sort(a.begin(), a.end());

    ll res = 0;

    for ( auto i = 0; i < n; i++ ) {
        int low = i;
        int high = n-1;
        int temp = i;

        while ( low <= high ) {
            
            int mid = ( low + high ) >> 1;

            if ( a[mid] - a[i] <= a[i] ) {
                temp = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        } 

        res += (ll)temp - (ll)i;
    }

    cout << res << endl;
    return 0;
}