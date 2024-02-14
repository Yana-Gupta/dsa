// The Rabin karp is also a pattern matching algorithm 
// It uses hash function for pattern matching
// By defining a hash function and calculating its hash value
// If the hash value of pattern matches with any substring of the text string then it further checks either they both are same or not cause there may be a cause of collision 
// If both the substrings matches 
// Then it return the index 

int Rabin_Karp(string source, string target)
{
    if (source == "" or target == "")
        return -1;
    int m = target.size();
    int power = 1;
    for (int i = 0; i < m; i++)
    {
        power = (power * 31) % BASE;
    }
    int targetCode = 0;
    for (int i = 0; i < m; i++)
    {
        targetCode = (targetCode * 31 + target[i]) % BASE;
    }
    int hashCode = 0;
    for (int i = 0; i < source.size(); i++)
    {
        hashCode = (hashCode * 31 + source[i]) % BASE;
        if (i < m - 1)
            continue;
        if (i >= m)
        {
            hashCode = (hashCode - source[i - m] * power) % BASE;
        }
        if (hashCode < 0)
            hashCode += BASE;
        if (hashCode == targetCode)
        {
            if (source.substr(i - m + 1, m) == target)
                return i - m + 1;
        }
    }
    return -1;
}