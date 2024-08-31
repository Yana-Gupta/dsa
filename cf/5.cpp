#include <bits/stdc++.h>
using namespace std;

bool dfs(int n, int p, vector<int> &vis, vector<vector<int>> &pmap)
{
    vis[n] = 1;
    for (auto ele : pmap[n])
    {
        if (ele != p)
        {
            if (vis[ele])
                return false;
            if (!dfs(ele, n, vis, pmap))
                return false;
        }
    }

    return true;
}

int main()
{
    int v;
    cin >> v;
    int e;
    cin >> e;
    vector<int> vis(v, 0);
    vector<vector<int>> pmap(v);
    for (auto i = 0; i < e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        pmap[n1].push_back(n2);
        pmap[n2].push_back(n1);
    }

    for (auto i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            if (!dfs(i, -1, vis, pmap))
            {
                cout << "There is a cycle" << endl;
                return 0;
            }
        }
    }

    cout << "There is not a cycle" << endl;
    return 0;
}
