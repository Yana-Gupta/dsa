#include<bits/stdc++.h>


using namespace std;

vector<int> z_function(string& s) {
    int n = s.size();
    vector<int> z(n, 0);

    int l = 0, r = 0; 
    for ( auto i = 1; i < n; i++ ) {
        if ( i  < r ) {
            z[i] = min(r - i, z[i-l]);
        }

        while ( i + z[i] < n && s[i + z[i]] == s[z[i]] ) z[i]++;


        if ( i + z[i] > r ) {
            l = i;
            r = i + z[i];
        }
    }

    return z;
}

int main() {
    string text = "bbaababacabacbaabaababab", pattern = "abab";

    string s = pattern + "#" + text;

    vector<int> temp = z_function(s);

    for ( auto i = 0; i < temp.size(); i++ ) {
        cout << temp[i] << " " ;
    }


}