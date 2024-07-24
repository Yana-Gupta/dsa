#include <bits/stdc++.h>
using namespace std;

vector<int> arr = {1, 2, 2, 1, 1, 2};

int main()
{

    map<int, int> mp1;
    map<int, int> mp2;
    
    for (auto ele : arr)
    {
        mp2[ele]++;
    }

    int ans = 0;

    for (auto i = 0; i < arr.size(); i++)
    {
        mp1[arr[i]]++;
        if (mp2[arr[i]])
            mp2[arr[i]]--;

        ans = max(ans, 2 * min(mp1[arr[i]], int(arr.size()) - 1 - i - mp2[arr[i]]));
    }

    cout << ans << endl;
}
