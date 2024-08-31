#include<bits/stdc++.h>
 
using namespace std;
 
int main () {
    int t;
    cin >> t;
    
    while ( t ) {
        int n; 
        cin >> n;
        vector<int> v(n);
        int bf = 0;
        for ( auto i = 0; i < n; i++ ) {
            cin >> v[i];
            if ( i != n-1 ) bf = max(bf, v[i]);
        }
        for ( auto i = n/2 - 1; i < n - 1; i++ ) bf = max(bf, v[i]);
        cout << (bf + v[n-1]) << endl;
        t--;

        
    }
}
