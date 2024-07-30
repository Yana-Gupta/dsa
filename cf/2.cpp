#include<bits/stdc++.h>

using namespace std;

int main () {
    int t;
    cin >> t;
    while ( t ) {
        string s;
        cin >> s;

        int ones = 0, zeros = 0;
        for ( auto ch: s ) {
            if ( ch == '1' ) ones++;
            else zeros++;
        }

        int len = 0;
        int i = 0;
        for ( i = 0; i < s.size(); i++ ) {
            if ( s[i] == '1' ) {
                if ( !zeros )  break;
                zeros--;
            } else {
                if ( !ones ) break;
                ones--;
            }
        }
        cout << s.size() - i << endl;
        t--;
    }
}