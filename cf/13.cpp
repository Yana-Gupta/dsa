#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
    int n;
    string s;
    cin >> n;
    cin >> s;
    map<char, int> mp1;
    for (auto ch : s)
        mp1[ch]++;
    int mcount = mp1.size();
    map<int, int> mp2;

    int i = 0, j = 0;

    int ans = n;

    while (j < n)
    {
        mp2[s[j]]++;
        while (mp2.size() > mcount)
        {
            mp2[s[i]]--;
            if (mp2[s[i]] == 0)
                mp2.erase(s[i]);
            i++;
        }
        while (mp2[s[i]] != 1)
        {
            mp2[s[i]]--;
            i++;
        }
        if (mp2.size() == mcount)
            ans = min(ans, j - i + 1);
        j++;
    }

    cout << ans << endl;
}
