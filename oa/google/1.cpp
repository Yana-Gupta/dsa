#include <iostream>
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class MedianFinder
{
private:
    priority_queue<int> maxHeap;                           
    priority_queue<int, vector<int>, greater<int>> minHeap; 
    int size = 0;

    void rebalanceHeaps()
    {
        if (maxHeap.size() > minHeap.size() + 1)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else if (minHeap.size() > maxHeap.size())
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
public:
    void addNum(int num)
    {
        if (maxHeap.empty() || num <= maxHeap.top())
        {
            maxHeap.push(num);
        }
        else
        {
            minHeap.push(num);
        }
        size++;

        rebalanceHeaps();
    }

    void removeNum(int num)
    {
        bool f = false;
        while (!maxHeap.empty() && maxHeap.top() > num)
        {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        if (!maxHeap.empty() && maxHeap.top() == num)
        {
            maxHeap.pop();
            f = true;
        }
        while (!minHeap.empty() && minHeap.top() < num && !f)
        {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        if (!minHeap.empty() && minHeap.top() == num && !f)
        {
            minHeap.pop();
        }
        rebalanceHeaps();
        size--;
    }

    double findMedian()
    {
        rebalanceHeaps();

        return maxHeap.top();
    }

    int getSize() { return size; }
};

long long solve(vector<int> &cost, multiset<int> &ms, int node, map<int, vector<int>> &pmap, int p)
{
    long long ans = 0;

    ms.insert(cost[node - 1]);
    int s = ms.size();
    // cout << node << " " << s << endl;
    if (s % 2 == 1)
    {
       auto it = ms.begin();
       advance(it, (s/2));
       ans += *it;
    }

    for (auto ele : pmap[node])
    {
        if (ele != p)
        {
            ans += solve(cost, ms, ele, pmap, node);
        }
    }

    ms.erase(cost[node - 1]);

    return ans;
}

int main()
{
    vector<int> cost;

    for (auto i = 0; i < 10; i++)
    {
        cost.push_back((rand() % 20));
    }
    for (auto i = 0; i < 10; i++)
    {
        cout << cost[i] << " ";
    }

    vector<vector<int>> edges;
    cout << endl;

    auto it = ms1.begin();
    advance(it, ms1.size() / 2  );
    cout << *it << endl;

    edges.push_back({1, 3});
    edges.push_back({1, 2});
    edges.push_back({1, 4});
    edges.push_back({1, 5});
    edges.push_back({3, 7});
    edges.push_back({2, 8});
    edges.push_back({3, 9});
    edges.push_back({4, 6});
    edges.push_back({9, 10});

    map<int, vector<int>> pmap;

    for (auto e : edges)
    {
        pmap[e[0]].push_back(e[1]);
        pmap[e[1]].push_back(e[0]);
    }

    multiset<int> ms;


    cout << solve(cost, ms, 1, pmap, -1) << endl;
    return 0;
}
