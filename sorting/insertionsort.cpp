#include<bits/stdc++.h>

using namespace std;

void insertionsort(vector<int>& arr) {
    for ( auto i = 1; i < arr.size(); i++ ) {
        int key = arr[i];
        int l = i-1;

        while ( l >= 0 && arr[l] > key ) { 
            arr[l+1] = arr[l];
            l = l-1;
        }
        
        arr[l+1] = key;
    }
}

int main () {
    vector<int> arr = {23, 2, 324, 12, 21, 3, 12, 34, 21};
    insertionsort(arr);

    cout << "Sorted array: \n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;

}