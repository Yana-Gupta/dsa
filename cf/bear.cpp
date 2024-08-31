#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};

    int cnt = 0;

    for (auto i = 0; i < primes.size(); i++)
    {
        cout << primes[i] << endl;
        fflush(stdout);
        string s;
        cin >> s;
        if (s == "yes")
        {
            cnt++;
            if (cnt > 1)
            {
                cout << "composite" << endl;
                break;
            }
            if (primes[i] * primes[i] <= 100)
            {
                cout << (primes[i] * primes[i]) << endl;
                fflush(stdout);
                cin >> s;
                if (s == "yes")
                {
                    cnt++;
                    cout << "composite" << endl;
                    break;
                }
            }
        }
    }

    if (cnt == 1 || cnt == 0)
    {
        cout << "prime" << endl;
    }
}