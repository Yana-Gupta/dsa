#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

bool fine(int val, vector<int>& a1, vector<int>& b1) {
    int i = 0, j = 0;

    while (i < a1.size() && j < b1.size()) {
        if (abs(a1[i] - b1[j]) <= val) i++;
        else j++;
    }

    return (i == a1.size());
}

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a1(n), b1(m);

    for (int i = 0; i < n; i++) {
        cin >> a1[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> b1[i];
    }

    sort(a1.begin(), a1.end());
    sort(b1.begin(), b1.end());

    ll low = 0, high = 2e9;
    ll res = -1;

    while (low <= high) {
        ll mid = (low + high) / 2;
        if (fine(mid, a1, b1)) {
            high = mid - 1;
            res = mid;
        } else {
            low = mid + 1;
        }
    }

    cout << res << endl;

    return 0;
}
