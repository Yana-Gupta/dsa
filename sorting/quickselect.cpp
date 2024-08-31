// Not an sorting algorithm
// Difference between quicksort and quickselect
// Quicksort sorts the whole array while quickselect just searches for an particular index

// Google Fav Topic

#include "bits/stdc++.h"
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int Partition(int arr[], int l, int r)
{
    int lst = arr[r], i = l, j = l;
    while (j < r)
    {
        if (arr[j] < lst)
        {
            swap(&arr[i], &arr[j]);
            i++;
        }
        j++;
    }
    swap(&arr[i], &arr[r]);
    return i;
}

int randomPartition(int arr[], int l, int r)
{
    int n = r - l + 1;
    int pivot = rand() % n;
    swap(&arr[l + pivot], &arr[r]);
    return Partition(arr, l, r);
}

void MedianUtil(int arr[], int l, int r, int k, int &a, int &b)
{
    if ( a != -1 && b != -1 ) return;

    if (l <= r)
    {

        int partitionIndex = randomPartition(arr, l, r);

        if (partitionIndex == k)
        {
            b = arr[partitionIndex];
            if (a != -1)
                return;
        }

        else if (partitionIndex == k - 1)
        {
            a = arr[partitionIndex];
            if (b != -1)
                return;
        }

        if (partitionIndex >= k)
            return MedianUtil(arr, l, partitionIndex - 1, k, a, b);

        else
            return MedianUtil(arr, partitionIndex + 1, r, k, a, b);
    }

    return;
}

void findMedian(int arr[], int n)
{
    float ans;
    int a = -1, b = -1;

    if (n % 2 == 1) {
        MedianUtil(arr, 0, n - 1, n / 2, a, b);
        ans = b;
    }

    else {
        MedianUtil(arr, 0, n - 1, n / 2, a, b);
        ans = (float(a) + float(b)) / 2;
    }

    cout << "Median = " << ans << endl;
}

int main()
{
    int arr[] = {12, 3, 5, 7, 100, 3, 32, 20, 41, 32, 44, 9, 10, 31, 4, 19, 20, 26};
    int n = sizeof(arr) / sizeof(arr[0]);
    findMedian(arr, n);

    // sort(arr.begin(), arr.end());

    cout << n << endl;
    return 0;
}
