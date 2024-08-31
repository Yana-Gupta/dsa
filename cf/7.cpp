#include <bits/stdc++.h>

using namespace std;

// Function to build the segment tree
void build(int node, int l, int h, const vector<int> &a, vector<int> &seg)
{
    if (l == h)
    {
        seg[node] = a[l];
        return;
    }
    int mid = (l + h) >> 1;
    build(2 * node + 1, l, mid, a, seg);
    build(2 * node + 2, mid + 1, h, a, seg);
    seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}

int query(int l, int h, int ql, int qh, int node, const vector<int> &seg)
{
    if (l > qh || h < ql) {
        return 0;
    }
    
    if (l >= ql && h <= qh) {
        return seg[node];
    }
    
    int mid = (l + h) >> 1;
    int leftSum = query(l, mid, ql, qh, 2 * node + 1, seg);
    int rightSum = query(mid + 1, h, ql, qh, 2 * node + 2, seg);
    return leftSum + rightSum;
}

void update(int idx, int val, int l, int h, int node, vector<int> &seg)
{
    if (l == h)
    {
        seg[node] = val;
        return; 
    }

    int mid = (l + h) >> 1;
    if (idx <= mid)
    {
        update(idx, val, l, mid, 2 * node + 1, seg);
    }
    else
    {
        update(idx, val, mid + 1, h, 2 * node + 2, seg);
    }

    seg[node] = seg[2 * node + 1] + seg[2 * node + 2];
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> seg(4 * n); // Segment tree size

    build(0, 0, n - 1, a, seg);

    cout << query(0, n - 1, 2, 4, 0, seg) << endl;
    cout << query(0, n - 1, 0, 4, 0, seg) << endl;
    cout << query(0, n - 1, 3, 4, 0, seg) << endl;

    update(3, 42, 0, n - 1, 0, seg);

    cout << query(0, n - 1, 2, 4, 0, seg) << endl;

    return 0;
}
