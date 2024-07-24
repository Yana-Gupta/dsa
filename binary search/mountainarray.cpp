#include<bits/stdc++.h>

using namespace std;


int searchPeak(vector<int>& arr) {

    int low = 0;
    int high = arr.size() -1;

    while ( low < high ) {
        int mid = (low + high)/2;

        if ( arr[mid] < arr[mid +1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return low;
}

int searchRotatedArray(vector<int>& arr, int target) {
    int low = 0;
    int high = arr.size() - 1;
    while ( low <= high ) {
        int mid = ( low + high)/2;
        // either array is sorted left 

        if ( arr[mid] == target ) return mid;

        if ( arr[low] < arr[mid] ) {
            if ( arr[low] <= target && arr[mid] > target ) {
                high = mid -1;
            } else {
                low = mid + 1;
            }
        }
        else {

            if ( arr[mid] < target && arr[high] >= target ) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }

        }
    }

    return -1;
}

int main () {

    vector <int> arr = {1, 3, 4, 5, 19, 8, 2};

    vector<int> rotatedArray = {33, 53, 65, 74, 252, 3, 5, 10, 13, 20};

    cout << searchPeak(arr) << endl;
    
    cout << searchRotatedArray(rotatedArray, 33) << endl;

}