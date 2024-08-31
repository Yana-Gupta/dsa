#include<bits/stdc++.h>

using namespace std;
vector<int> z_function(const string &s)
{
    int n = s.size(), l = 0, r = 0;
    vector<int> z(n);
    for (int i = 1; i < n; i++)
    {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

int main() {
    string s = "abcyanaguptabacabcygp";
    vector<int> temp = z_function(s);
    
    for ( auto i = 0; i < s.size(); i++ ) {
        cout << temp[i] << " ";
    }
    cout << endl;
}