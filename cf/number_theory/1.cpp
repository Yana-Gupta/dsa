// https://codeforces.com/contest/1826/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int gcd(int a, int b) {
    if ( a < b ) swap(a, b);
    if ( b == 0 ) return a;
    return gcd(b, a%b);
}


int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        vector<ll> a(n);
        for (auto i = 0; i < n; i++)
            cin >> a[i];
        
        int prev = abs(a[n-1] - a[0]);
        for ( auto i = 1; i < n/2; i++ ) {
            prev = gcd(prev, abs(a[n-i-1] - a[i]));


        }

        cout << prev << endl;
    }
}