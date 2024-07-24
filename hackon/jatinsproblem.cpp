#include <bits/stdc++.h>

using namespace std;

int main()
{
    // The solution is wrong won't work in case he can not do anything 
    vector<int> arr = {1, 1, 1, 5, 5, 5};
    vector <int> time = {0, 1, 2, 0, 0, 0, 0, 3, 0, 0, 4, 5};
    int n = arr.size();
    int m = time.size();

    cout << "The size of arr is: " << n << endl << "The size of time array is: " << m << endl;

    // considering anything in arr is not zero
    if ( m < 2*n ) {
        cout << -1 << endl;
        return -1;
    }

    int min_time = 0;
    for ( auto a: arr ) min_time += a;

    // then keep on reducing ith time by what we visit the array 
    // means if me make anything zero by visiting the index reduce that simply from the array
    // if in end we have left with something in negetive less than equal to -n then we have reach 

    for ( auto i = 0; i < m; i++ ) {
        if ( arr[time[i]] > 0 )
            min_time -= min(min_time, arr[time[i]]);
        else 
            min_time--;

        arr[time[i]] = 0;

        if ( min_time <= -n) {
            cout << i + 1 << endl;
            break;
        }
    }

    if ( min_time > -n ) cout << -1 << endl;

}
