#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k; 

    int l = 1, h = n; 

    

    while (l < h)
    {
        int mid = (l + h) >> 1;

        cout << "? " << mid + 1 << " " << h << endl;
        fflush(stdout); 
        int a;
        cin >> a;

        if (a < (h - mid))
        {
            l = mid;
        }
        else
        {
            h = mid;
        }
    }

    cout << "! " << l + 1 << endl;
}
