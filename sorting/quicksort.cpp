#include<bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int low, int high) {

    int pivot = arr[high];
    int l = low;

    for ( auto i = low; i <= high; i++ ) {
        if ( arr[i] < pivot ) {
            swap(arr[i], arr[l]);
            l++;
        }
    }

    swap(arr[l], arr[high]);
    return l;
}

void quicksort(vector<int>& arr, int low, int high) {
    if ( low >= high ) return;
    int pivot = partition(arr, low, high);

    quicksort(arr, low, pivot - 1);
    quicksort(arr, pivot + 1, high);
}

int main() {
    vector< int> arr = {23, 2, 324, 12, 21, 3 ,12, 34, 21};
    quicksort(arr, 0, 8);
    for ( auto i = 0; i < 9; i++ ) {
        cout << arr[i] << endl;
    }
}



/**
 * 
 * 32 41 42 2 51 12
 * Pivot = 12
 * low = 0
 * 
 * value at i and low gets swapped
 * after that low is incremented
 * 2 41 42 32 51 12
 * 
 * low is clearly low + 1 in this case as it is incremented only once
 * 2 12 42 32 51 41 
 * pivot = 1 ( zero based indexing )
 * again implement quicksort on the 0 to pivot - 1 
 * to pivot + 1 to high index 
 * 
*/