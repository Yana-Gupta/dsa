// z-function - find the occurance of a pattern in linear time
// a a b c a a b x a a a z
// 0 1 0 0 3 1 0 0 2 2 1 0 

// Time Complexity = O(n)
// Space Complexity = O(n)

vector<int> z_func(vector<int> temp)
{
    int n = temp.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
            z[i] = min(r - i, z[i - l]);
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            z[i]++;
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}