// https://cses.fi/problemset/task/1085/
#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

bool isfine(vector<ll>& arr, int k, ll s) {
    ll cs = 0;

    int temp = 1;

    for ( auto i = 0; i < arr.size(); i++ ) {
        if ( cs + arr[i] > s ) {
            cs = arr[i];
            temp++;
        } else {
            cs += arr[i];
        }
    }

    return temp <= k;
} 

int main ( ) {
    int n, k;
    cin >> n >> k;

    vector<ll> arr(n);

    for ( auto i = 0; i < n; i++ ) {
        cin >> arr[i];
    }

    ll low = *max_element(arr.begin(), arr.end());
    ll high = accumulate(arr.begin(), arr.end(), 0LL);
    ll res = LLONG_MAX;

    while ( low <= high ) {
        ll mid = ( low + high ) >> 1;
        if ( isfine(arr, k, mid) ) {
            res = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    cout << res << endl;
    return 0;
}