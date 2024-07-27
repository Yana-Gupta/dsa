#include <bits/stdc++.h>
#include <random>

using namespace std;


long int random() {
    std::random_device rd;

    std::mt19937 gen(rd());

    std::uniform_int_distribution<> distrib(0, 100);

    int random_number = distrib(gen);

    return random_number;
}


void dfs(string s1, string s2, map<string, set<string>> &eq, map<string, set<string>> &uneq, bool type)
{
    if (type == 1)
    {
        if (eq.find(s1) != eq.end() && eq[s1].find(s2) != eq[s1].end())
            return;
        eq[s1].insert(s2);
        eq[s2].insert(s1);
    }

    if (type == 0)
    {
        if (uneq.find(s1) != uneq.end() && uneq[s1].find(s2) != uneq[s1].end())
            return;
        uneq[s1].insert(s2);
        uneq[s2].insert(s1);
    }

    for (auto ele : eq[s1])
    {
        dfs(s2, ele, eq, uneq, type);
    }

    for (auto ele : eq[s2])
    {
        dfs(s1, ele, eq, uneq, type);
    }

    for (auto ele : uneq[s1])
    {
        dfs(s2, ele, eq, uneq, (!type));
    }

    for (auto ele : uneq[s2])
    {
        dfs(s1, ele, eq, uneq, (!type));
    }
}

std::string generateRandomString()
{
    char letters[] = "abcdefghijklmnopqrstuvwxyz";
    int len = sizeof(letters) - 1;
    char randStr[2];
    randStr[0] = letters[random() % len];
    randStr[1] = '\0';
    return std::string(randStr);
}

std::string generateRandomPattern()
{
    std::string str1 = generateRandomString();
    std::string str2 = generateRandomString();
    std::string operators[] = {"==", "!="};
    if (str1 == str2)
        return str1 + "==" + str2;

    return str1 + operators[random() % 2] + str2;
}

std::vector<std::string> generatePatterns(int count)
{
    std::vector<std::string> patterns;
    for (int i = 0; i < count; ++i)
    {
        patterns.push_back(generateRandomPattern());
    }
    return patterns;
}

int main()
{

    vector<string> temp = generatePatterns(1000);
    map<string, set<string>> equals;
    map<string, set<string>> unequals;
    int i = 0;

    for (i = 0; i < temp.size(); i++)
    {
        string str = temp[i];
        string s1 = "", s2 = "";
        bool sign = false;
        int k = 0;
        for (; k < str.size() && str[k] != '!' && str[k] != '='; k++)
            s1 += str[k];
        if (str[k] == '=')
            sign = true;
        k += 2;
        for (; k < str.size(); k++)
            s2 += str[k];
        if (s1 == s2 && !sign)
        {
            cout << i << "Wrong" << endl;
            break;
        }
        else if (s1 == s2)
            continue;
        if (sign)
        {
            if (unequals.find(s1) != unequals.end() && unequals[s1].find(s2) != unequals[s1].end())
            {
                cout << i << "Wrong" << endl;
                break;
            }
            dfs(s1, s2, equals, unequals, sign);
        }
        else
        {
            if (equals.find(s1) != equals.end() && equals[s1].find(s2) != equals[s1].end())
            {
                cout << i << "Wrong" << endl;
                break;
            }
            dfs(s1, s2, equals, unequals, sign);
        }
    }

    if (i == temp.size())
        cout << "Right" << endl;
}