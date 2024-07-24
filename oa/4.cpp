#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX_NODES = 100000;

int dfs(int mini, vector<vector<int>> &graph, vector<int> &mark, vector<int> &vis, int node)
{
    vis[node] = 1;
    for (auto ele : graph[node])
    {
        if (mark[ele] || vis[ele])
            continue;
        mini = min(mini, ele);
        mini = dfs(mini, graph, mark, vis, ele);
    }
    return mini;
}

int main()
{

    cout << "Connections:" << endl;
    int n;
    cin >> n;

    vector<vector<int>> graph(MAX_NODES + 1);

    for (int i = 0; i < n; ++i)
    {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    cout << "Queries:" << endl;

    vector<int> ans;

    int m;
    cin >> m;

    vector<vector<int>> queries(m, vector<int>(2));
    for (int i = 0; i < m; ++i)
    {
        int q, n;
        cin >> q >> n;
        queries[i][0] = q;
        queries[i][1] = n;
    }

    vector<int> mark(MAX_NODES + 1, 0);

    for (int i = 0; i < m; ++i)
    {
        int q = queries[i][0], n = queries[i][1];

        if (q == 1)
        {
            if (!mark[n])
            {
                ans.push_back(n);
            }
            else
            {
                vector<int> vis(MAX_NODES + 1, 0);
                int minUnmarked = dfs(MAX_NODES, graph, mark, vis, n);
                ans.push_back(minUnmarked);
            }
        }
        else
        {
            mark[n] = 1;
        }
    }

    cout << "Answers:" << endl;
    for (int a : ans)
    {
        cout << a << " ";
    }
    cout << endl;

    return 0;
}
