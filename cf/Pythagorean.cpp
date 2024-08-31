#include<bits/stdc++.h>


using namespace std;


int main () {
    int t;
    cin >> t;

    while ( t ) {
        int n;
        cin >> n;
        n = 2*n;


        cout << ((int)sqrt(n) - 1)/2 << endl;

        t--;
    }



    return 0;
}