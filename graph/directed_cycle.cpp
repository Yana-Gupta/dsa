#include<bits/stdc++.h>

using namespace std;

bool isCycle(int node, vector<vector<int>>& graph, vector<bool>& vis, vector<bool>& pathvis) {
    vis[node] = 1;
    pathvis[node] = 1;
 
    for ( auto n: graph[node] ) {
        if ( !vis[n] && isCycle(n, graph, vis, pathvis) ) {
            return true;
        } else if ( pathvis[n]) {
            return true;
        }
        
    }
    
    pathvis[node] = false;

    return false;
}

int main () {

    vector<vector<int>> graph(5);

    graph[0] = {1};
    graph[1] = {0, 4};
    graph[2] = { 3};
    graph[3] = {2, 4};
    graph[4] = {2, 1};
    vector<bool> vis(5, false);
    vector<bool> pathvis(5, false);
    for ( auto i = 0; i < 5; i++ ) {
        if ( !vis[i] && isCycle(i, graph, vis, pathvis)) {

            cout << 1 << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}

/*
* 0 -> 1 
*/
