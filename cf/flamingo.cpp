#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N, 0);

    int i = 0;

    while (i < N)
    {
        if (N - i >= 3)
        {
            int a12, a13, a23;
            cout << "? " << i + 1 << " " << i + 2 << endl;
            fflush(stdout);
            cin >> a12;
            cout << "? " << i + 1 << " " << i + 3 << endl;
            fflush(stdout);
            cin >> a13;
            cout << "? " << i + 2 << " " << i + 3 << endl;
            fflush(stdout);
            cin >> a23;
            a[i + 1] = (a12 + a23 - a13);
            a[i] = a12 - a[i + 1];
            a[i + 2] = a23 - a[i + 1];
        }
        else if (N - i >= 2)
        {

            int am1, a12;
            cout << "? " << i << " " << i + 1 << endl;
            fflush(stdout);
            cin >> am1;
            cout << "? " << i + 1 << " " << i + 2 << endl;
            fflush(stdout);
            cin >> a12;

            a[i] = am1 - a[i - 1];
            a[i + 1] = a12 - a[i];
        }
        else
        {
            int am1;
            cout << "? " << i << " " << i + 1 << endl;
            fflush(stdout);
            cin >> am1;

            a[i] = am1 - a[i - 1];
        }

        i = i + 3;
    }
    cout << "! ";

    for (auto i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}