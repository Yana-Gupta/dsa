// A C program to implement Manacher’s Algorithm
#include <bits/stdc++.h>

using namespace std;

int min(int a, int b)
{
    int res = a;
    if (b < a)
        res = b;
    return res;
}

void findLongestPalindromicString(string text)
{
    int N = text.size();
    if (N == 0) return;
    N = 2 * N + 1; // Position count
    int L[N];      // LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1, R = 2, i = 0;
    int iMirror;
    int start = -1, end = -1, diff = -1;
    for (i = 2; i < N; i++)
    {
        iMirror = 2 * C - i;
        L[i] = 0;
        diff = R - i;
        if (diff > 0)
            L[i] = min(L[iMirror], diff);
        while (((i + L[i]) < N && (i - L[i]) > 0) && (((i + L[i] + 1) % 2 == 0) || (text[(i + L[i] + 1) / 2] == text[(i - L[i] - 1) / 2]))) {
            L[i]++;
        }

        if (i + L[i] > R)
        {
            C = i;
            R = i + L[i];
        }
    }

    for ( auto i = 0; i < N; i++ ) cout << i << " " << L[i] << endl;
}

int main()
{
    string text = "babcbabcbaccba";

    findLongestPalindromicString(text);
    return 0;
}
