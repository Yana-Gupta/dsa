// Count the number of subarray where whose product has odd number of divisors

// Constrains - n = 2*10^5
// A[i] <= 200

#include <bits/stdc++.h>
using namespace std;

vector<int> getPrimes(int n)
{
    vector<bool> is(n + 1, true);

    for (auto i = 2; i <= n; i++)
    {
        for (auto j = 2 * i; j <= n; j += i)
        {
            is[j] = false;
        }
    }

    vector<int> res;

    for (auto i = 2; i <= n; i++)
    {
        if (is[i])
            res.push_back(i);
    }

    return res;
}

int main()
{
    vector<int> prime = getPrimes(199);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<long long, int> cnt;
    cnt[0] += 1;
    long long res = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        int val = 0;
        for (int j = 0; j < prime.size(); j++)
        {
            int cnt = 0;
            while (a[i] % prime[j] == 0)
            {
                cnt += 1;
                a[i] /= prime[j];
            }
            if (cnt % 2)
                val |= (1LL << j);
        }
        sum ^= val;
        res += cnt[sum];
        cnt[sum] += 1;
    }
    cout << res << endl;
    return 0;
}