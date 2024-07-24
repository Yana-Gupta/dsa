#include<bits/stdc++.h>

using namespace std;

vector<int> tree(36);

vector<int> arr = {32, 12, 32, 12, 421, 21, 314, 31};


void build(int node, int s, int e ) {
    if ( s == e ) {
        tree[node] = arr[s];
        return;
    }
    int mid = (s + e)/2;
    build(2*node + 1, s, mid);
    build(2*node + 2, mid + 1, e);
    tree[node] = tree[2*node+1] + tree[2*node + 2];
}

int query( int node, int s, int e, int ql, int qe) {

    if ( qe < s || ql > e ) return 0;

    if ( ql <= s && qe >= e ) return tree[node];
    int mid = ( s + e )/2;

    int left = query(2*node + 1, s, mid, ql, qe);
    int right = query(2*node + 2, mid+ 1, e, ql, qe);

    return left + right;
}

void update( int node, int st, int ed, int idx,  int key ) {


    if ( idx > ed || idx < st  ) return;
    if ( st == ed && st == idx ) {
        arr[idx] = key;
        tree[node] = key;
        return;
    }

    int mid = ( st + ed )/2;

    update(2*node + 1, st, mid, idx, key );

    update(2*node + 2, mid + 1, ed, idx, key);

    tree[node] = tree[2*node + 1] + tree[2*node + 2];
}

int main () {

    build(0 , 0, 7);
    cout << query(0, 0, 7, 1, 6) << endl;
    cout << query(0, 0, 7, 2, 4) << endl;

    update(0, 0, 7, 1, 88);

    cout << query(0, 0, 7, 1, 6) << endl;

}

