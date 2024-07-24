#include <bits/stdc++.h>


using namespace std;

void dfs(string s1, string s2, map<string, set<string>> &eq, map<string, set<string>> &uneq, bool type)
{
    if (type == 1)
    {
        if ( eq.find(s1) != eq.end() && eq[s1].find(s2) != eq[s1].end() ) return;
        eq[s1].insert(s2);
        eq[s2].insert(s1);
    }

    if (type == 0)
    {
        if ( uneq.find(s1) != uneq.end() && uneq[s1].find(s2) != uneq[s1].end() ) return;
        uneq[s1].insert(s2);
        uneq[s2].insert(s1);
    }

    for ( auto ele: eq[s1] ) {
        dfs(s2, ele, eq, uneq, type);
    }

    for ( auto ele: eq[s2] ) {
        dfs(s1, ele, eq, uneq, type);
    }

    for ( auto ele: uneq[s1] ) {
        dfs(s2, ele, eq, uneq, (!type));
    }

    for ( auto ele: uneq[s2] ) {
        dfs(s1, ele, eq, uneq, (!type));
    }
}

int main()
{
    vector<string> temp = {"a==b", "b!=c", "c!=a", "a==e", "e==f", "f==g", "g!=e", "g==f", "z==e", "ee=ee"};

    map<string, set<string>> equals;
    map<string, set<string>> unequals;
    int i = 0;

    for ( i = 0; i < temp.size(); i++)
    {
        string str = temp[i];
        string s1 = "", s2 = "";

        bool sign = false; // means not equal;
        int k = 0;
        for (; k < str.size() && str[k] != '!' && str[k] != '='; k++)
        {
            s1 += str[k];
        }
        if (str[k] == '=')
            sign = true;

        k += 2;
        for (; k < str.size(); k++)
        {
            s2 += str[k];
        }

        // first equal
        cout << sign << endl;
        if ( s1 == s2 && !sign ) {
            cout << "Wrong" << endl;
            break;
        } else if ( s1 == s2 ) continue;
        if (sign)
        {
            if (unequals.find(s1) != unequals.end() && unequals[s1].find(s2) != unequals[s1].end())
            {
                cout << "Wrong" << endl;
                break;
            }


            dfs(s1, s2, equals, unequals, sign);
        }
        else
        {
            if (equals.find(s1) != equals.end() && equals[s1].find(s2) != equals[s1].end())
            {
                cout << "Wrong" << endl;
                break;
            }

            dfs(s1, s2, equals, unequals, sign);
        }
    }

    if ( i == temp.size()) cout << "Right" << endl;
    
}