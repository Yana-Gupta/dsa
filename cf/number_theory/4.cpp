// https://codeforces.com/problemset/problem/495/B

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

vector<ll> getFactors(ll num) {
    vector<ll> factors;
    for (ll i = 1; i * i <= num; ++i) {
        if (num % i == 0) {
            factors.push_back(i);
            if (i != num / i) {
                factors.push_back(num / i);
            }
        }
    }
    return factors;
}

int countFactorsGreaterThan(ll num, ll threshold) {
    vector<ll> factors = getFactors(num);
    int count = 0;
    for (ll factor : factors) {
        if (factor > threshold) {
            ++count;
        }
    }
    return count;
}

int main() {
    ll a, b;
    cin >> a >> b;

    if (b == a) {
        cout << "infinity" << endl;
    } else if (b > a) {
        cout << 0 << endl;
    } else {
        ll difference = a - b;
        int result = countFactorsGreaterThan(difference, b);
        cout << result << endl;
    }

    return 0;
}
