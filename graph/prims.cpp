#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<vector<pair<int, int>>> graph(5);

    graph[0] = {{12, 1}};
    graph[1] = {{23, 2}};
    graph[2] = {{32, 3}};
    graph[3] = {{23, 4}};
    graph[4] = {{23, 1}};


    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;
    // weight , src
    minpq.push({0, 0});

    int ans = 0;
    vector<bool> vis(5, false);

    while (!minpq.empty())
    {
        auto [weight, src] = minpq.top();
        minpq.pop();
        if (vis[src])
            continue;
        vis[src] = true;

        ans += weight;
        for (auto ed : graph[src])
        {
            if (vis[ed.second] == false)
            {
                minpq.push({ed.first, ed.second});
            }
        }
    }

    cout << ans << endl;

    return 0;
}