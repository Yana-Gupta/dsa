// KMP is also a pattern matching algorithm in string 
// It uses the concept of two pointers 
// two pointers i, j 


int KMP(string &s1, string &t)
{
    string s = t + '#' + s1;
    int n = s.length();
    vector<int> kmp(n + 1);
    int i = 0, j = -1;
    kmp[0] = -1;

    while (i < n)
    {
        while (j != -1 && s[j] != s[i])
        {
            j = kmp[j];
        }
        j++;
        i++;
        kmp[i] = j;

        if (kmp[i] == t.length())
            return i - 2 * t.length() - 1;
    }

    return -1;
}