// https://codeforces.com/contest/474/problem/B

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (auto i = 0; i < n; i++) {
        cin >> a[i+1];
        a[i+1] += a[i];
    }
    int m;
    cin >> m;
    vector<int> jcy(m);
        

    for ( auto i = 0; i < m; i++ ) {
        cin >> jcy[i];
        int low = 1, high = n;
        int res = -1;
        while ( low <= high ) {
            int mid = ( low + high ) >> 1;

            if ( a[mid] >=  jcy[i] ) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }

        cout << res << endl;
    }
}