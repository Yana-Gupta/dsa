#include <bits/stdc++.h>

using namespace std;

bool dfs(int node, vector<int>& pathvis, vector<int>& vis, vector<vector<int>>& pmap)
{
    pathvis[node] = 1;
    vis[node]  = 1;
    for (auto ele : pmap[node])
    {
        if (!vis[ele])
        {
            if (!dfs(ele, pathvis, vis, pmap))
                return false;
        }
        else if (vis[ele] && pathvis[ele])
            return false;
    }

    pathvis[node] = 0;

    return true;
}

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<int>> pmap(v);
    for (auto i = 0; i < e; i++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        pmap[n1].push_back(n2);
    }
    vector<int> vis(v, 0);
    vector<int> pathvis(v, 0);

    for (auto i = 0; i < v; i++)
    {
        if (!vis[i])
        {
            cout << i << endl;
            if (!dfs(i, pathvis, vis, pmap))
            {
                cout << "there is cycle" << endl;
                return 0;
            }
        }
    }

    cout << "there is not cycle" << endl;

    return 0;
}
