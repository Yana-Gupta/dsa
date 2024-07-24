#include <bits/stdc++.h>

using namespace std;

int parent(vector<int> &p, int idx)
{
    if (p[idx] == idx)
        return idx;

    return p[idx] = parent(p, p[idx]);
}
void do_union(vector<int> &p, vector<int> &rank, int i1, int i2)
{
    int p1 = parent(p, i1);
    int p2 = parent(p, i2);

    if (p1 != p2)
    {
        if (rank[p1] > rank[p2])
        {
            p[p2] = p1;
        }
        else if (rank[p1] < rank[p2])
        {
            p[p1] = p2;
        }
        else
        {
            p[p1] = p2;
            rank[p2]++;
        }
    }
}

int main()
{

    vector<vector<pair<int, int>>> graph(5);

    graph[0] = {{12, 1}};
    graph[1] = {{23, 2}};
    graph[2] = {{32, 3}};
    graph[3] = {{23, 4}};
    graph[4] = {{23, 1}};

    // use the edge list
    vector<vector<int>> edges;
    edges.push_back({12, 0, 1});
    edges.push_back({23, 1, 2});
    edges.push_back({32, 2, 3});
    edges.push_back({23, 3, 4});
    edges.push_back({23, 4, 1});

    sort(edges.begin(), edges.end());

    vector<int> rank(5, 0);
    vector<int> p(5, 0);
    for (auto i = 0; i < 5; i++)
        p[i] = i;
    int ans = 0;

    for (auto e : edges)
    {
        int wt = e[0];
        int e1 = e[1];
        int e2 = e[2];
        if (parent(p, e1) != parent(p, e2))
        {
            ans += wt;
            do_union(p, rank, e1, e2);
        }
    }

    cout << ans << endl;

    return 0;
}