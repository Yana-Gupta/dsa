#include <bits/stdc++.h>

using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;

    int i = 0;
    bool flag = false;
    char last = '0';;
    int firstidx = -1;

    while ( i < a.size() ) {
        if ( a[i] < b[i] ) {
            firstidx = i;
            break;
        }
        i++;
    }

    int idx = -1;
    int j = i;
    while ( j < a.size() ) {
        if ( a[j] >= b[firstidx] ) {
            idx = j;
        }
        j++;
    }
    cout << firstidx << endl;

    cout << idx << endl;

    if ( idx != -1 ) {
        swap(a[idx], a[i]);
    }


    

    cout << a << endl;
}