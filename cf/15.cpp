#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main () {
    ll n, t;
    cin >> n >> t;

    vector<ll> b(n);
    for ( auto i = 0; i < n; i++ ) cin >> b[i];

    ll i = 0, j = 0;
    ll sum = 0;
    ll res = 0;
    while ( j < n ) {
        sum += b[j];

        while ( sum > t ) {
            sum -= b[i];
            i++;
        } 
        res = max(res, j - i + 1);
        j++;
    }

    cout << res << endl;
}