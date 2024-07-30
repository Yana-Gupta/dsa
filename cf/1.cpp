#include <bits/stdc++.h>
using namespace std;

int merge(int i, int mid, int j, vector<int>& a, int& m) {
    long long res = 1;
    int left = i;
    int right = mid + 1;

    // Calculate the product of absolute differences
    vector<int> temp(j - i + 1);
    int k = 0;
    while (left <= mid && right <= j) {
        if (a[left] <= a[right]) {
            temp[k++] = a[left++];
        } else {
            // All elements from a[left] to a[mid] will be greater than a[right]
            for (int start = left; start <= mid; start++) {
                int t = abs(a[start] - a[right]);
                res = (res * t) % m;
            }
            temp[k++] = a[right++];
        }
    }

    // Collect remaining elements
    while (left <= mid) {
        temp[k++] = a[left++];
    }
    while (right <= j) {
        temp[k++] = a[right++];
    }

    // Copy the sorted elements back into the original array
    for (int t = 0; t < temp.size(); t++) {
        a[t + i] = temp[t];
    }

    return res;
}

int mergesort(int i, int j, vector<int> &a, int& m) {
    if (i >= j)
        return 1;

    int mid = (i + j) >> 1;

    long long res = mergesort(i, mid, a, m);
    res = (res * mergesort(mid + 1, j, a, m)) % m;

    res = (res * merge(i, mid, j, a, m)) % m;

    return res;
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cout << mergesort(0, n - 1, a, m) << endl;
}
