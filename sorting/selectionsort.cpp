#include<bits/stdc++.h>

using namespace std;

// you select the correct element for that position 
// Time Complexity O(N^2)
// Space complexity O(1)


void selectionsort(vector<int>& arr) {
    for ( auto i = 0; i < arr.size() - 1; i++ ) {
        int key = arr[i];
        int idx = i;
        for ( auto j = i + 1; j < arr.size(); j++ ) {
            if ( key > arr[j] ) {
                idx = j;
                key = arr[j];
            }
        }
        swap(arr[i], arr[idx]);
    }
}

int main () {
    vector<int> arr = {23, 2, 324, 12, 21, 3, 12, 34, 21};
    selectionsort(arr);

    cout << "Sorted array: \n";
    for (int i = 0; i < arr.size(); i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;

}