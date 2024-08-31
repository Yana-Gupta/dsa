#include <bits/stdc++.h>

using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;
    vector<vector<pair<int, int>>> pmap(v);
    for (int i = 0; i < e; i++)
    {
        int n1, n2, c;
        cin >> n1 >> n2 >> c;
        pmap[n1].push_back({n2, c});
        pmap[n2].push_back({n1, c});
    }

    vector<int> cost(v, 1e9);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minpq;
    minpq.push({0, 0});
    cost[0] = 0;

    while (minpq.size())
    {
        auto it = minpq.top();
        minpq.pop();
        int c = it.first, n = it.second;
        for (auto ele : pmap[n])
        {
            if (cost[ele.first] > c + ele.second)
            {
                cost[ele.first] = c + ele.second;
                minpq.push({cost[ele.first], ele.first});
            }
        }
    }

    for (auto i = 0; i < v; i++)
    {
        cout << cost[i] << " ";
    }

    cout << endl;
}
