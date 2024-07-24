#include <bits/stdc++.h>

using namespace std;

void build(int node, int l, int r, vector<pair<int, int>> &seg, vector<int> &v)
{
    if (l == r)
    {
        seg[node] = {v[l], l};
        return;
    }

    int mid = (l + r) / 2;
    build(2 * node + 1, l, mid, seg, v);
    build(2 * node + 2, mid + 1, r, seg, v);
    if (seg[2 * node + 1].first < seg[2 * node + 2].first)
    {
        seg[node] = seg[2 * node + 1];
    }
    else
    {
        seg[node] = seg[2 * node + 2];
    }
}

int query(int l, int r, int ql, int qr, int node, vector<pair<int, int>> &seg, int x)
{
    if (l > qr || r < ql)
        return -1;

    if (seg[node].first > x)
        return -1;

    if (l >= ql && r <= qr) {
        if ( l == r ) return seg[node].second;

        int left = query(l, (l + r )/2, qr, ql, 2*node + 1, seg, x);
        if ( left != -1 ) return min(left, seg[node].second);

        int right = query((l + r)/2 + 1, r, ql, qr, 2*node + 2, seg, x);

        if ( right != -1 ) return min(right, seg[node].second);

        return seg[node].second;

    }
        

    int mid = (l + r) / 2;

    int left = query(l, mid, ql, qr, 2 * node + 1, seg, x);
    int right = query(mid + 1, r, ql, qr, 2 * node + 2, seg, x);

    if (left != -1)
        return left;
    if (right != -1)
        return right;
    return -1;
}

void update(int l, int r, int node, int idx, int key, vector<pair<int, int>> &seg)
{
    if (l == r)
    {
        seg[node] = {key, l};
        return;
    }
    int mid = (l + r) / 2;

    if (idx <= mid)
    {
        update(l, mid, 2 * node + 1, idx, key, seg);
    }
    else
    {
        update(mid + 1, r, 2 * node + 2, idx, key, seg);
    }

    if (seg[2 * node + 1].first < seg[2 * node + 2].first)
    {
        seg[node] = seg[2 * node + 1];
    }
    else
    {
        seg[node] = seg[2 * node + 2];
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        vector<pair<int, int>> seg(4 * n);

        for (int i = 0; i < n; i++)
            cin >> v[i];

        build(0, 0, n - 1, seg, v);
        int q;
        cin >> q;

        while (q--)
        {
            int t;
            cin >> t;
            vector<int> lrx;
            if ( t == 1 ) {
                int l, x;
                cin >> l >> x;
                update(0, n-1, 0, l, x, seg);
            } else {
                int l, r, x;
                cin >> l >> r >> x;
                cout << query(0, n-1, l, r, 0, seg, x) << endl;
            }

        }
    }
    return 0;
}
