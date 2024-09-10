#include<bits/stdc++.h>


using namespace std;

typedef long long ll;

int solve(string& s) {
    int i = 0;

    ll res = 0;
    map<char, int> mp;
    for ( auto i = 0; i < s.size(); i++ ) {
        mp[s[i]]++;

        ll ans = 0;
        ans += mp[s[i]];


    }

}


// take 1 and then have rem 
int main() {
    string s = "abaabaasagwkjlelewriotaoewiefaw";
    cout << solve(s) << endl;
}